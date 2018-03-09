//
// NotLink.hpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Mon Feb 27 23:34:27 2017 Sebastien Le Guischer
// Last update Mon Feb 27 23:34:29 2017 Sebastien Le Guischer
//

#ifndef NOTLINK_HPP_
# define NOTLINK_HPP_

# include <utility>
# include "ILinks.hpp"

class NotLink : public ILinks
{
public:
	NotLink(nts::IComponent *first, size_t first_pin);
	virtual ~NotLink();
	virtual nts::Tristate compute();
private:
	std::pair<nts::IComponent *, size_t> in;
};

#endif