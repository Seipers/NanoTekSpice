//
// True.hpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Sun Mar  5 19:58:41 2017 Sebastien Le Guischer
// Last update Sun Mar  5 19:58:42 2017 Sebastien Le Guischer
//

#ifndef TRUE_HPP_
# define TRUE_HPP_

# include <string>
# include "IComponent.hpp"

class True : public nts::IComponent
{
public:
  True(const std::string &name);
  virtual ~True();
  virtual nts::Tristate Compute(size_t pin_num_this = 1);
  virtual void SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
  virtual void Dump(void) const;
private:
  std::string _name;
};

#endif