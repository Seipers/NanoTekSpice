//
// Output.hpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Mon Feb 27 19:21:29 2017 Sebastien Le Guischer
// Last update Mon Feb 27 21:33:35 2017 Sebastien Le Guischer
//

#ifndef OUTPUT_HPP_
# define OUTPUT_HPP_

# include <string>
# include "IComponent.hpp"
# include "ILinks.hpp"

class Output : public nts::IComponent
{
public:
  Output(const std::string &);
  virtual ~Output();
  virtual nts::Tristate Compute(size_t pin_num_this = 1);
  virtual void SetLink(size_t pin_num_this,
		       nts::IComponent &component,
		       size_t pin_num_target);
  virtual void Dump(void) const;
private:
  ILinks	*_link;
  std::string	_name;
};

#endif
