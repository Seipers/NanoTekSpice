//
// OrGate.cpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Tue Feb 28 00:25:13 2017 Sebastien Le Guischer
// Last update Tue Feb 28 00:25:14 2017 Sebastien Le Guischer
//

#include <iostream>
#include "SimpleLink.hpp"
#include "OrLink.hpp"
#include "OrGate.hpp"

OrGate::OrGate(const std::string &name)
: _name(name), _link(std::vector<ILinks *> (3, NULL))
{
	this->_link.at(0) = new OrLink(this, 3, this, 2);
}

OrGate::~OrGate()
{
}

nts::Tristate OrGate::Compute(size_t pin_num_this)
{
	if ((pin_num_this > 0 && pin_num_this < 4) && this->_link[pin_num_this - 1])
		return ((this->_link[pin_num_this - 1])->compute());
	return (nts::UNDEFINED);
}

void	OrGate::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
	if (pin_num_this == 2 || pin_num_this == 3)
		this->_link.at(pin_num_this - 1) = new SimpleLink(&component, pin_num_target);
	else if (pin_num_this == 1)
		component.SetLink(pin_num_target, *this, pin_num_this);
}

void	OrGate::Dump() const
{
	std::cout << "OrGate: " << this->_name << std::endl;
}