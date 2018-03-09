//
// SimpleLink.cpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Mon Feb 27 20:27:05 2017 Sebastien Le Guischer
// Last update Mon Feb 27 21:33:49 2017 Sebastien Le Guischer
//

#include "SimpleLink.hpp"

SimpleLink::SimpleLink(nts::IComponent *component, size_t pin)
: in(std::make_pair(component, pin))
{
}

SimpleLink::~SimpleLink()
{
}

nts::Tristate SimpleLink::compute()
{
  return((this->in.first)->Compute(this->in.second));
}