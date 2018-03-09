//
// Factory.cpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Wed Mar  1 17:25:19 2017 Sebastien Le Guischer
// Last update Sat Mar  4 17:38:40 2017 Dorian Voravong
//

#include "Factory.hpp"
#include "C4001.hpp"
#include "C4011.hpp"
#include "C4030.hpp"
#include "C4069.hpp"
#include "C4071.hpp"
#include "C4081.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "AndGate.hpp"
#include "NandGate.hpp"
#include "OrGate.hpp"
#include "NorGate.hpp"
#include "NotGate.hpp"
#include "XorGate.hpp"
#include "True.hpp"
#include "False.hpp"

Factory::Factory()
{
	map.insert(std::make_pair("4001", &Factory::create4001));
	map.insert(std::make_pair("4011", &Factory::create4011));
	map.insert(std::make_pair("4030", &Factory::create4030));
	map.insert(std::make_pair("4069", &Factory::create4069));
	map.insert(std::make_pair("4071", &Factory::create4071));
	map.insert(std::make_pair("4081", &Factory::create4081));
	//map.insert(std::make_pair("input", &Factory::createInput));
	map.insert(std::make_pair("output", &Factory::createOutput));
	map.insert(std::make_pair("and_gate", &Factory::createAndGate));
	map.insert(std::make_pair("nand_gate", &Factory::createNandGate));
	map.insert(std::make_pair("or_gate", &Factory::createOrGate));
	map.insert(std::make_pair("nor_gate", &Factory::createNorGate));
	map.insert(std::make_pair("not_gate", &Factory::createNotGate));
	map.insert(std::make_pair("xor_gate", &Factory::createXorGate));
	map.insert(std::make_pair("true", &Factory::createTrue));
	map.insert(std::make_pair("false", &Factory::createFalse));
}

nts::IComponent *Factory::createComponent(const std::string &type, const std::string &value)
{
	return (((this->*this->map.find(type)->second)(value)));
}

nts::IComponent *Factory::createComponent(const std::string &type, const std::string &value, nts::Tristate state)
{
	if (type == "input")
		return (this->createInput(value, state));
	return (NULL);
}

nts::IComponent *Factory::create4001(const std::string &value)
{
	return (new C4001(value));
}

nts::IComponent *Factory::create4011(const std::string &value)
{
	return (new C4011(value));
}

nts::IComponent *Factory::create4030(const std::string &value)
{
	return (new C4030(value));
}

nts::IComponent *Factory::create4069(const std::string &value)
{
	return (new C4069(value));
}

nts::IComponent *Factory::create4071(const std::string &value)
{
	return (new C4071(value));
}

nts::IComponent *Factory::create4081(const std::string &value)
{
	return (new C4081(value));
}

nts::IComponent *Factory::createInput(const std::string &value)
{
	return (new Input(value));
}

nts::IComponent *Factory::createInput(const std::string &value, nts::Tristate state)
{
	return (new Input(value, state));
}

nts::IComponent *Factory::createOutput(const std::string &value)
{
	return (new Output(value));
}

nts::IComponent *Factory::createTrue(const std::string &value)
{
	return (new True(value));
}

nts::IComponent *Factory::createFalse(const std::string &value)
{
	return (new False(value));
}

nts::IComponent *Factory::createAndGate(const std::string &value)
{
	return (new AndGate(value));
}

nts::IComponent *Factory::createNandGate(const std::string &value)
{
	return (new NandGate(value));
}

nts::IComponent *Factory::createOrGate(const std::string &value)
{
	return (new OrGate(value));
}

nts::IComponent *Factory::createNorGate(const std::string &value)
{
	return (new NorGate(value));
}

nts::IComponent *Factory::createNotGate(const std::string &value)
{
	return (new NotGate(value));
}

nts::IComponent *Factory::createXorGate(const std::string &value)
{
	return (new XorGate(value));
}
