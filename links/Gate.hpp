//
// Gate.hpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Tue Feb 28 00:11:07 2017 Sebastien Le Guischer
// Last update Tue Feb 28 00:11:08 2017 Sebastien Le Guischer
//

#ifndef GATE_HPP
# define GATE_HPP

# include "IComponent.hpp"

nts::Tristate nand_gate(nts::Tristate a, nts::Tristate b);
nts::Tristate nor_gate(nts::Tristate a, nts::Tristate b);
nts::Tristate not_gate(nts::Tristate a);
nts::Tristate and_gate(nts::Tristate a, nts::Tristate b);
nts::Tristate or_gate(nts::Tristate a, nts::Tristate b);
nts::Tristate xor_gate(nts::Tristate a, nts::Tristate b);

nts::Tristate operator^(nts::Tristate a, nts::Tristate b);
nts::Tristate operator||(nts::Tristate a ,nts::Tristate b);
nts::Tristate operator&&(nts::Tristate a, nts::Tristate b);
nts::Tristate operator!(nts::Tristate a);

#endif