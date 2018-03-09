//
// SimpleLink.hpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Mon Feb 27 20:26:58 2017 Sebastien Le Guischer
// Last update Mon Feb 27 21:33:58 2017 Sebastien Le Guischer
//

#ifndef SIMPLELINK_HPP
# define SIMPLELINK_HPP

# include <utility>
# include "ILinks.hpp"

class SimpleLink : public ILinks
{
public:
  SimpleLink(nts::IComponent *component, size_t pin);
  virtual ~SimpleLink();
  virtual nts::Tristate compute();
private:
  std::pair<nts::IComponent *, size_t> in;
};

#endif
