//
// Parser.hpp for nanotekspice in /home/dorian.voravong/rendu/cpp_nanotekspice/parser
// 
// Made by Dorian Voravong
// Login   <dorian.voravong@epitech.net>
// 
// Started on  Wed Mar  1 04:28:13 2017 Dorian Voravong
// Last update Sun Mar  5 17:29:48 2017 Dorian Voravong
//

#ifndef PARSER_HPP_
# define PARSER_HPP_

# include <list>
# include <string>
# include "Factory.hpp"
# include "IComponent.hpp"
# include "IParser.hpp"

namespace nts
{
  class	Parser : public IParser
  {
  public:
    virtual void feed(std::string const& input);
    virtual void parseTree(t_ast_node& root);
    virtual t_ast_node *createTree();
    Parser(const std::string &filename);
    virtual ~Parser();

    bool	checkExisting(std::string &);
    void	checkType(std::string &);
    void	parseChips(t_ast_node *chips);
    void	parseLinks(t_ast_node *links);
    void	addChild(t_ast_node *, t_ast_node *, ASTNodeType, std::string&) const;
    void	cleanString(std::string &) const;
    IComponent	*getComponent(std::string &) const;
    void	replaceInput(std::string &name, int nb);
    void	simulate();
    void	dump();
    void	display();
    
  private:
    std::string _filename;
    std::vector<IComponent *> *components;
    std::vector<std::pair<std::string, std::string> > *infos;
    std::list<IComponent *> *list;
    std::map<std::string, nts::Tristate> outputs;
    Factory	factory;
  };
  bool	duplicateSpaces(char l, char r);
}


#endif /* !PARSER_HPP_ */
