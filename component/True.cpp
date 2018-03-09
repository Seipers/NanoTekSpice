//
// True.cpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Sun Mar  5 19:58:34 2017 Sebastien Le Guischer
// Last update Sun Mar  5 19:58:35 2017 Sebastien Le Guischer
//

#include <iostream>
#include "True.hpp"

True::True(const std::string &name)
  : _name(name)
{
}

True::~True()
{
}

nts::Tristate True::Compute(size_t pin_num_this)
{
	(void)(pin_num_this);
	return(nts::TRUE);
}

void	True::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
  component.SetLink(pin_num_target, *this, pin_num_this);
}

void	True::Dump() const
{
  std::cout << "True: " << this->_name << " is " << 1 << std::endl;
}
