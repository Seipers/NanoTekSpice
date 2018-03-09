//
// False.cpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Sun Mar  5 19:58:52 2017 Sebastien Le Guischer
// Last update Sun Mar  5 19:58:53 2017 Sebastien Le Guischer
//

#include <iostream>
#include "False.hpp"

False::False(const std::string &name)
  : _name(name)
{
}

False::~False()
{
}

nts::Tristate False::Compute(size_t pin_num_this)
{
	(void)(pin_num_this);
	return(nts::FALSE);
}

void	False::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
  component.SetLink(pin_num_target, *this, pin_num_this);
}

void	False::Dump() const
{
  std::cout << "False: " << this->_name << " is " << 0 << std::endl;
}