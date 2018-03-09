//
// Circuit.hpp for nanotekspice in /home/dorian.voravong/rendu/cpp_nanotekspice/parser
// 
// Made by Dorian Voravong
// Login   <dorian.voravong@epitech.net>
// 
// Started on  Fri Mar  3 11:10:53 2017 Dorian Voravong
// Last update Sat Mar  4 15:25:30 2017 Dorian Voravong
//

#ifndef CIRCUIT_HPP_
# define CIRCUIT_HPP_

# include "Parser.hpp"

namespace nts
{
class	Circuit
{
public:
  Circuit(std::string &);
  virtual ~Circuit();
  Parser	parser;

  void		command(std::string &);
  
private:
  Circuit();
  Circuit(Circuit &c);
  Circuit	&operator=(Circuit &c);
};
}

#endif /* !CIRCUIT_HPP_ */
