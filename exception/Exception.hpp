//
// Exception.hpp for nanotekspice in /home/dorian.voravong/rendu/cpp_nanotekspice/exception
// 
// Made by Dorian Voravong
// Login   <dorian.voravong@epitech.net>
// 
// Started on  Sun Mar  5 15:01:37 2017 Dorian Voravong
// Last update Sun Mar  5 15:09:03 2017 Dorian Voravong
//

#ifndef EXCEPTION_HPP_
# define EXCEPTION_HPP_

# include <exception>
# include <string>

namespace nts
{
  class GeneralError : public std::exception
  {
  public:
    GeneralError() throw();
    virtual ~GeneralError() throw();
  };
}

#endif /* ! EXCEPTION_HPP_ */
