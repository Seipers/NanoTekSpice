//
// Factory.hpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Wed Mar  1 17:25:25 2017 Sebastien Le Guischer
// Last update Sat Mar  4 17:38:51 2017 Dorian Voravong
//

#ifndef FACTORY_HPP_
# define FACTORY_HPP_

# include <string>
# include <map>
# include "IComponent.hpp"
# include "Input.hpp"

class Factory
{
public:
  Factory();
  virtual ~Factory() {};
  nts::IComponent *createComponent(const std::string &type, const std::string &value);
  nts::IComponent *createComponent(const std::string &type, const std::string &value, nts::Tristate state);
private:
  std::map<std::string, nts::IComponent *(Factory::*)(const std::string &value)> map;
  //nts::IComponent *create2716(const std::string &value);
  nts::IComponent *create4001(const std::string &value);
  //nts::IComponent *create4004(const std::string &value);
  //nts::IComponent *create4008(const std::string &value);
  nts::IComponent *create4011(const std::string &value);
  //nts::IComponent *create4013(const std::string &value);
  //nts::IComponent *create4017(const std::string &value);
  nts::IComponent *create4030(const std::string &value);
  //nts::IComponent *create4040(const std::string &value);
  nts::IComponent *create4069(const std::string &value);
  nts::IComponent *create4071(const std::string &value);
  nts::IComponent *create4081(const std::string &value);
  //nts::IComponent *create4094(const std::string &value);
  //nts::IComponent *create4503(const std::string &value);
  //nts::IComponent *create4512(const std::string &value);
  //nts::IComponent *create4514(const std::string &value);	
  //nts::IComponent *create4801(const std::string &value);
  nts::IComponent *createInput(const std::string &value);
  nts::IComponent *createInput(const std::string &value, nts::Tristate state);
  nts::IComponent *createOutput(const std::string &value);
  nts::IComponent *createTrue(const std::string &value);
  nts::IComponent *createFalse(const std::string &value);
  //nts::IComponent *createClock(const std::string &value);
  nts::IComponent *createAndGate(const std::string &value);
  nts::IComponent *createNandGate(const std::string &value);
  nts::IComponent *createOrGate(const std::string &value);
  nts::IComponent *createNorGate(const std::string &value);
  nts::IComponent *createNotGate(const std::string &value);
  nts::IComponent *createXorGate(const std::string &value);
};

#endif
