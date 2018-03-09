//
// XorGate.hpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Tue Feb 28 00:25:19 2017 Sebastien Le Guischer
// Last update Tue Feb 28 00:25:20 2017 Sebastien Le Guischer
//

#ifndef XORGATE_HPP_
# define XORGATE_HPP_

# include <string>
# include <vector>
# include "IComponent.hpp"
# include "ILinks.hpp"

class XorGate : public nts::IComponent
{
public:
	XorGate(const std::string &name);
	virtual ~XorGate();
	virtual nts::Tristate Compute(size_t pin_num_this = 1);
	virtual void SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
	virtual void Dump() const;
private:
	std::string _name;
	std::vector<ILinks *> _link;
};

#endif