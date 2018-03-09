//
// Circuit.cpp for nanotekspice in /home/dorian.voravong/rendu/cpp_nanotekspice/parser
// 
// Made by Dorian Voravong
// Login   <dorian.voravong@epitech.net>
// 
// Started on  Fri Mar  3 11:10:44 2017 Dorian Voravong
// Last update Sun Mar  5 16:10:02 2017 Dorian Voravong
//

#include "Circuit.hpp"

nts::Circuit::Circuit()
  : parser("default")
{

}

nts::Circuit::Circuit(std::string &s)
  : parser(s)
{

}

nts::Circuit::~Circuit()
{

}

nts::Circuit::Circuit(nts::Circuit &c)
  : parser("default")
{
  (void)c;
}

nts::Circuit		&nts::Circuit::operator=(nts::Circuit &c)
{
  return (c);
}

void		nts::Circuit::command(std::string &input)
{
  if (input == "" || input == "loop")
    return ;
  if (input == "display")
    parser.display();
  else if (input == "simulate")
    parser.simulate();
  else if (input == "dump")
    parser.dump();
  else
    parser.feed(input);
}
