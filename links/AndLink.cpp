//
// AndLink.cpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Mon Feb 27 23:34:17 2017 Sebastien Le Guischer
// Last update Mon Feb 27 23:34:18 2017 Sebastien Le Guischer
//

#include "AndLink.hpp"
#include "Gate.hpp"

AndLink::AndLink(nts::IComponent *first, size_t first_pin, nts::IComponent *second, size_t second_pin)
{
	in[0] = std::make_pair(first, first_pin);
	in[1] = std::make_pair(second, second_pin);
}

AndLink::~AndLink()
{
}

nts::Tristate AndLink::compute()
{
	return (and_gate((this->in[0].first)->Compute(this->in[0].second),
			 (this->in[1].first)->Compute(this->in[1].second)));
}
