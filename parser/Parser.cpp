//
// Parser.cpp for nanotekspice in /home/dorian.voravong/rendu/cpp_nanotekspice/parser
// 
// Made by Dorian Voravong
// Login   <dorian.voravong@epitech.net>
// 
// Started on  Wed Mar  1 04:31:33 2017 Dorian Voravong
// Last update Sun Mar  5 17:33:23 2017 Dorian Voravong
//

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include "IComponent.hpp"
#include "Parser.hpp"
#include "Exception.hpp"

nts::Parser::Parser(const std::string &filename)
  : _filename(filename), components(new std::vector<IComponent *>),
    infos(new std::vector<std::pair<std::string, std::string>>)
{
  
}

nts::Parser::~Parser()
{

}

void	nts::Parser::replaceInput(std::string &name, int nb)
{
  auto	i = components->begin();
  auto	j = infos->begin();
  size_t	pos = 0;
  
  while (i < components->end() && j < infos->end())
    {
      if (j->second == name)
	{
	  if (j->first != "input")
	    {
	      std::cerr << "Invalid type for input" << std::endl;
	      throw (std::exception());
	    }
	  if (nb == 1)
	    dynamic_cast<Input *>(*i)->changeState(Tristate::TRUE);
	  else
	    dynamic_cast<Input *>(*i)->changeState(Tristate::FALSE);
	  return ;
	}
      i++;
      j++;
      pos++;
    }
}

void			nts::Parser::feed(std::string const &input)
{
  std::stringstream	stream(input);
  std::string		name;
  std::string		value;
  int			nb;
  
  getline(stream, name, '=');
  try{
    checkExisting(name);
  }
  catch (nts::GeneralError &e)
    {
      std::cerr << "A component name is unknown" << std::endl;
      throw (std::exception());
    }
  getline(stream, value);
  try{
    nb = std::stoi(value);
  }
  catch (std::exception &e)
    {
      std::cerr << "Missing input value on command line"  << std::endl;
      throw (std::exception());
    }
  if (nb != 0 && nb != 1)
    {
      std::cerr << "Unknown input specified by command line" << std::endl;
      throw (std::exception());
    }
  try{
    replaceInput(name, nb);
  }
  catch (nts::GeneralError &e)
    {
      throw (std::exception());
    }
}

nts::IComponent*	nts::Parser::getComponent(std::string &name) const
{
  auto		i = infos->begin();
  auto		j = components->begin();
  
  while (i < infos->end() && j < components->end())
    {
      if (i->second == name)
	return (*j);
      i++;
      j++;
    }
  std::cerr << "A component name is unknown" << std::endl;
  throw (std::exception());
  return (NULL);
}

void	nts::Parser::checkType(std::string &type)
{
  auto exist = {"4001", "4011", "4030", "4069", "4071", "4081", "input",
   "output", "true", "false", "and_gate", "nand_gate", "or_gate", "nor_gate", "not_gate", "xor_gate"};
  auto it = exist.begin();

  while (it < exist.end())
  {
    if ((*it) == type)
      return ;
    it++;
  }
  throw (nts::GeneralError());
}

bool	nts::Parser::checkExisting(std::string &name)
{  
  for (auto it = infos->begin(); it != infos->end(); it++)
    {
      if ((*it).second == name)
	return (true);
    }
  return (false);
}

void	nts::Parser::parseChips(t_ast_node *chips)
{
  if (chips->children == NULL)
    {
      std::cerr << "Syntax error in .nts" << std::endl;
      throw (std::exception());
    }
  for (auto it = chips->children->begin(); it != chips->children->end(); it++)
    {
      if ((*it)->type != ASTNodeType::COMPONENT)
	{
	  std::cerr << "Syntax error in .nts" << std::endl;
	  throw (std::exception());
	}
      if (checkExisting((*it)->value))
	{
	  std::cerr << "Several components share the same name" << std::endl;
	  throw (std::exception());
	}
      try {
      checkType((*it)->lexeme);
    }
    catch(nts::GeneralError &e) {
      std::cerr << "Bad Type" << std::endl;
      throw (std::exception());
    }
      if ((*it)->lexeme == "input")
	components->push_back(factory.createComponent((*it)->lexeme, (*it)->value, nts::Tristate::UNDEFINED));
      else
	components->push_back(factory.createComponent((*it)->lexeme, (*it)->value));
      infos->push_back(make_pair((*it)->lexeme, (*it)->value));
    }
}

void		nts::Parser::parseLinks(t_ast_node *links)
{
  IComponent	*first;
  IComponent	*second;
  size_t	first_pin;
  size_t	second_pin;

  if (links->children->size() == 0 || links->children->size() % 2 != 0)
    {
      std::cerr << "Syntax error in .nts" << std::endl;
      throw (std::exception());
    }
  for (auto it = links->children->begin(); it != links->children->end(); it++)
    {
      if ((*it)->type != ASTNodeType::LINK)
	{
	  std::cerr << "Syntax error in .nts" << std::endl;
	  throw (std::exception());
	}
      else
	{
	  first = getComponent((*it)->lexeme);
	  first_pin = std::stoi((*it)->value);
	  it++;
	  if ((*it)->type != ASTNodeType::LINK_END)
	    {
	        std::cerr << "Syntax error in .nts" << std::endl;
		throw (std::exception());
	    }
	  else
	    {
	      try{
		if ((second = getComponent((*it)->lexeme)) == first)
		  throw (std::exception());
		second_pin = std::stoi((*it)->value);
		first->SetLink(first_pin, *second, second_pin);
	      }
	      catch (std::exception &e)
		{
		  std::cerr << "Links error" << std::endl;
		  throw (std::exception());
		}
	    }
	}
    }
}
  
void	nts::Parser::parseTree(t_ast_node &root)
{
  if (root.children != NULL && root.children->size() == 2)
    {
      parseChips(root.children->at(0));
      parseLinks(root.children->at(1));
    }
  else
    {
      std::cerr << "Syntax error" << std::endl;
      throw (std::exception());
    }
}

void	nts::Parser::cleanString(std::string &str) const
{
  std::replace(str.begin(), str.end(), '\t', ' ');
  std::string::iterator new_end = std::unique(str.begin(), str.end(), duplicateSpaces);
  str.erase(new_end, str.end());
}

void			nts::Parser::addChild(t_ast_node *components, t_ast_node *links,
					      ASTNodeType nodetype, std::string &line) const
{
  t_ast_node		*n = new t_ast_node(NULL);
  std::stringstream	stream(line);
  std::stringstream	stream2;
  std::stringstream	stream3;
  std::string		substr;
  
  n->type = nodetype;
  if (n->type == ASTNodeType::COMPONENT)
    {
      getline(stream, n->lexeme, ' ');
      getline(stream, n->value);
      components->children->push_back(n);
    }
  else if (n->type == ASTNodeType::LINK)
    {
	  getline(stream, substr, ' ');
	  stream2.str(substr);
	  getline(stream2, n->lexeme, ':');
	  getline(stream2, n->value);
	  links->children->push_back(n);
	  n = new t_ast_node(NULL);
	  n->type = ASTNodeType::LINK_END;
	  getline(stream, substr);
	  stream3.str(substr);
	  getline(stream3, n->lexeme, ':');
	  getline(stream3, n->value);
	  links->children->push_back(n);
    }
  else
    {
      std::cout << "line error: " << line << std::endl;
      throw (std::exception());
    }
}

nts::t_ast_node *nts::Parser::createTree()
{
  ASTNodeType	nodetype;
  std::ifstream	file(this->_filename); 
  t_ast_node	*components = new t_ast_node(new std::vector<t_ast_node *>);
  t_ast_node	*links = new t_ast_node(new std::vector<t_ast_node *>);
  t_ast_node	*tree = new t_ast_node(new std::vector<t_ast_node *>);
  std::string	line;
  
  tree->type = ASTNodeType::DEFAULT;
  components->type = ASTNodeType::SECTION;
  links->type = ASTNodeType::SECTION;
  if (!file.is_open())
    return (NULL);
  while (!file.eof())
    {
      getline(file, line);
      if (line[0] && line[0] != '#')
	{
	  if (line == ".chipsets:")
	    nodetype = ASTNodeType::COMPONENT;	      
	  else if (line == ".links:")
	    nodetype = ASTNodeType::LINK;
	  else
	    {
	      cleanString(line);
	      this->addChild(components, links, nodetype, line);
	    }
	}
    }
  file.close();
  tree->children->push_back(components);
  tree->children->push_back(links);
  return (tree);
}

void	nts::Parser::dump()
{
  for (auto i = components->begin(); i < components->end(); i++)
    (*i)->Dump();
}

void	nts::Parser::simulate()
{
  outputs.clear();
  auto  i = components->begin();
  auto  j = infos->begin();

  while (i != components->end() && j != infos->end())
    {
      if (j->first == "output")
        outputs.insert(std::make_pair(j->second, (*i)->Compute(1)));
      i++;
      j++;
    }  
}

void	nts::Parser::display()
{
  auto it = outputs.begin();

  while (it != outputs.end())
  {
    std::cout << (*it).first << "=" << (*it).second << std::endl;
    it++;
  }
}

bool	nts::duplicateSpaces(char left, char right)
{
  return ((left == right) && (left == ' '));
}
