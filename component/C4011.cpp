//
// C4011.cpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Tue Feb 28 01:38:49 2017 Sebastien Le Guischer
// Last update Tue Feb 28 01:38:50 2017 Sebastien Le Guischer
//

#include <iostream>
#include "NandLink.hpp"
#include "SimpleLink.hpp"
#include "C4011.hpp"

C4011::C4011(const std::string &name)
:	_name(name), _link(std::vector<ILinks *> (14, NULL))
{
	this->_link.at(2) = new NandLink(this, 1, this, 2);
	this->_link.at(3) = new NandLink(this, 5, this, 6);
	this->_link.at(9) = new NandLink(this, 8, this, 9);
	this->_link.at(10) = new NandLink(this, 12, this, 13);
}

C4011::~C4011()
{
}

nts::Tristate C4011::Compute(size_t pin_num_this)
{
	if ((pin_num_this > 0 && pin_num_this < 15) && this->_link[pin_num_this - 1])
		return (this->_link[pin_num_this - 1]->compute());
	return (nts::UNDEFINED);
}

void	C4011::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
	if (pin_num_this == 1 || pin_num_this == 2 
		|| pin_num_this == 5 || pin_num_this == 6 
		|| pin_num_this == 8 || pin_num_this == 9 
		|| pin_num_this == 12 || pin_num_this == 13)
	this->_link.at(pin_num_this - 1) = new SimpleLink(&component, pin_num_target);
	else if (pin_num_this == 3 || pin_num_this == 4 || pin_num_this == 10 || pin_num_this == 11)
		component.SetLink(pin_num_target, *this, pin_num_this);
}

void	C4011::Dump() const
{
	std::cout << "4011: " << this->_name << std::endl;
}