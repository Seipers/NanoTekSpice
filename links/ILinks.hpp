//
// ILinks.hpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Mon Feb 27 14:52:17 2017 Sebastien Le Guischer
// Last update Mon Feb 27 21:32:31 2017 Sebastien Le Guischer
//

#ifndef ILINKS_HPP_
# define ILINKS_HPP_

# include "IComponent.hpp"

class ILinks
{
public:
  virtual ~ILinks() {}
  virtual nts::Tristate compute() = 0;
};

#endif
