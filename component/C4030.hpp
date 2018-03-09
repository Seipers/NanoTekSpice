//
// C4001.hpp for nano in /home/sebastien/Rendu/cpp_nanotekspice/component
//
// Made by Sebastien Le Guischer
// Login   <sebastien@epitech.net>
//
// Started on  Tue Feb 28 01:38:34 2017 Sebastien Le Guischer
// Last update Tue Feb 28 01:38:35 2017 Sebastien Le Guischer
//

#ifndef C4030_HPP_
# define C4030_HPP_

# include <string>
# include <vector>
# include "ILinks.hpp"
# include "IComponent.hpp"

class C4030 : public nts::IComponent
{
public:
	C4030(const std::string &name);
	virtual ~C4030();
	virtual nts::Tristate Compute(size_t pin_num_this = 1);
	virtual void SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
	virtual void Dump(void) const;
private:
	std::string _name;
	std::vector<ILinks *> _link;
};

#endif