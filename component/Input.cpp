//
// Input.cpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Mon Feb 27 21:13:20 2017 Sebastien Le Guischer
// Last update Sat Mar  4 17:44:20 2017 Dorian Voravong
//

#include <iostream>
#include "Input.hpp"

Input::Input(const std::string &name, nts::Tristate state)
  : _state(state), _name(name)
{
}

Input::~Input()
{
}

nts::Tristate Input::Compute(size_t pin_num_this)
{
  if (pin_num_this == 1)
    return (this->_state);
  return (nts::UNDEFINED);
}

void	Input::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
  component.SetLink(pin_num_target, *this, pin_num_this);
}

void	Input::Dump() const
{
  std::cout << "Input: " << this->_name << " is " << this->_state << std::endl;
}

void	Input::changeState(nts::Tristate state)
{
  this->_state = state; 
}
