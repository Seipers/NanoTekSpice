//
// Output.cpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Mon Feb 27 19:21:22 2017 Sebastien Le Guischer
// Last update Sun Mar  5 17:39:31 2017 Dorian Voravong
//

#include <iostream>
#include "Output.hpp"
#include "SimpleLink.hpp"

Output::Output(const std::string &name)
  : _link(NULL), _name(name)
{
}

Output::~Output()
{
}

nts::Tristate Output::Compute(size_t pin_num_this)
{
   if (this->_link && pin_num_this == 1)
    return (this->_link->compute());
  return (nts::UNDEFINED);
}

void	Output::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
	if (pin_num_this == 1)
	  this->_link = new SimpleLink(&component, pin_num_target);
}

void	Output::Dump() const
{
  std::cout << "Output: " << this->_name << std::endl;
}
