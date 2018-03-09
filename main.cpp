#include <ostream>
#include <vector>
#include <iostream>
#include "Factory.hpp"
#include "Parser.hpp"
#include "Circuit.hpp"


void	dump_tree(nts::t_ast_node *tree)
{
    size_t	i;

  i = 0;
  std::cout << "Type: ";
  if (tree->type == nts::ASTNodeType::COMPONENT)
    std::cout << "Component";
  else if (tree->type == nts::ASTNodeType::LINK)
    std::cout << "Link";
  else if (tree->type == nts::ASTNodeType::LINK_END)
    std::cout << "Link end";
  else if (tree->type == nts::ASTNodeType::DEFAULT)
    std::cout << "Default";
  else if (tree->type == nts::ASTNodeType::SECTION)
    std::cout << "Section";
  std::cout << "\nLexeme: " << tree->lexeme << "\nValue: " << tree->value << std::endl << std::endl;
  if (tree->children == NULL)
    return ;
  while (i < tree->children->size())
    {
      dump_tree(tree->children->at(i));
      i++;
    }
}

int	main(int argc, char *argv[1])
{
  if (argc < 2)
    {
      std::cerr << "Usage: ./nanotekspice file.nts input1=value1 [input2=value2...]" << std::endl;
      return (0);
    }

  std::string	arg(argv[1]);
  nts::Circuit	circuit(arg);
  nts::t_ast_node	*tree;
  std::string	input;

  try{
    if ((tree = circuit.parser.createTree()) == NULL)
      return (1);
    circuit.parser.parseTree(*tree);
    for (int i = 2; i < argc; i++)
      circuit.parser.feed(argv[i]);
    circuit.parser.simulate();
    circuit.parser.display();
    std::cout << "> ";
    while (getline(std::cin, input) && input != "exit")
      {
	circuit.command(input);
	std::cout << "> ";
      }
  }
  catch (std::exception &e)
    {
    }
  return (0);
}
