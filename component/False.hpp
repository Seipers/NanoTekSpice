//
// False.hpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Sun Mar  5 19:59:00 2017 Sebastien Le Guischer
// Last update Sun Mar  5 19:59:01 2017 Sebastien Le Guischer
//

#ifndef FALSE_HPP_
# define FALSE_HPP_

# include <string>
# include "IComponent.hpp"

class False : public nts::IComponent
{
public:
  False(const std::string &name);
  virtual ~False();
  virtual nts::Tristate Compute(size_t pin_num_this = 1);
  virtual void SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
  virtual void Dump(void) const;
private:
  std::string _name;
};

#endif