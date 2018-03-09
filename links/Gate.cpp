//
// Gate.cpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Tue Feb 28 00:10:57 2017 Sebastien Le Guischer
// Last update Tue Feb 28 00:10:58 2017 Sebastien Le Guischer
//

#include "Gate.hpp"

nts::Tristate xor_gate(nts::Tristate a, nts::Tristate b)
{
	return (a ^ b);
}

nts::Tristate nand_gate(nts::Tristate a, nts::Tristate b)
{
	return (!(a && b));
}

nts::Tristate nor_gate(nts::Tristate a, nts::Tristate b)
{
	return (!(a || b));
}

nts::Tristate not_gate(nts::Tristate a)
{
	return (!a);
}

nts::Tristate and_gate(nts::Tristate a, nts::Tristate b)
{
	return (a && b);
}

nts::Tristate or_gate(nts::Tristate a, nts::Tristate b)
{
	return (a || b);
}

nts::Tristate operator^(nts::Tristate a, nts::Tristate b)
{
	if (a == nts::UNDEFINED || b == nts::UNDEFINED)
		return (nts::UNDEFINED);
	else if (a == b)
		return (nts::FALSE);
	return (nts::TRUE);
}

nts::Tristate operator||(nts::Tristate a, nts::Tristate b)
{
	if (a == nts::UNDEFINED && b == nts::UNDEFINED)
		return (nts::UNDEFINED);
	if ((a == nts::UNDEFINED && b == nts::FALSE) || (a == nts::FALSE && b == nts::UNDEFINED))
		return (nts::UNDEFINED);
	if (a == nts::TRUE || b == nts::TRUE)
		return (nts::TRUE);
	return (nts::FALSE);
}

nts::Tristate operator&&(nts::Tristate a, nts::Tristate b)
{
	if (a == nts::UNDEFINED || b == nts::UNDEFINED)
		return (nts::UNDEFINED);
	if (a == b && a == nts::TRUE)
		return (nts::TRUE);
	return (nts::FALSE);
}

nts::Tristate operator!(nts::Tristate a)
{
	if (a == nts::UNDEFINED)
		return (nts::UNDEFINED);
	if (a == nts::TRUE)
		return (nts::FALSE);
	return (nts::TRUE);
}