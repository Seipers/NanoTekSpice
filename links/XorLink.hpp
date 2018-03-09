//
// XorLink.hpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Mon Feb 27 23:34:27 2017 Sebastien Le Guischer
// Last update Mon Feb 27 23:34:29 2017 Sebastien Le Guischer
//

#ifndef XORLINK_HPP_
# define XORLINK_HPP_

# include <utility>
# include "ILinks.hpp"

class XorLink : public ILinks
{
public:
	XorLink(nts::IComponent *first, size_t first_pin, nts::IComponent *second, size_t second_pin);
	virtual ~XorLink();
	virtual nts::Tristate compute();
private:
	std::pair<nts::IComponent *, size_t> in[2];
};

#endif