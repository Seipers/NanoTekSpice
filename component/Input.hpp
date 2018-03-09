//
// Input.hpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Mon Feb 27 21:13:09 2017 Sebastien Le Guischer
// Last update Sat Mar  4 17:20:07 2017 Dorian Voravong
//

#ifndef INPUT_HPP
# define INPUT_HPP

# include <string>
# include "IComponent.hpp"

class Input : public nts::IComponent
{
public:
  Input(const std::string &name, nts::Tristate state = nts::TRUE);
  virtual ~Input();
  virtual nts::Tristate Compute(size_t pin_num_this = 1);
  virtual void SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
  virtual void Dump(void) const;
  void	changeState(nts::Tristate state);
private:
  nts::Tristate _state;
  std::string _name;
};

#endif
