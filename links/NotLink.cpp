//
// NotLink.cpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Mon Feb 27 23:34:17 2017 Sebastien Le Guischer
// Last update Mon Feb 27 23:34:18 2017 Sebastien Le Guischer
//

#include "NotLink.hpp"
#include "Gate.hpp"

NotLink::NotLink(nts::IComponent *first, size_t first_pin)
{
	in = std::make_pair(first, first_pin);
}

NotLink::~NotLink()
{
}

nts::Tristate NotLink::compute()
{
	return (not_gate((this->in.first)->Compute(this->in.second)));
}