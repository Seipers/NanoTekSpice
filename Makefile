##
## Makefile for nano in /home/sebastien/Rendu/cpp_nanotekspice
## 
## Made by Sebastien Le Guischer
## Login   <sebastien@epitech.net>
## 
## Started on  Tue Feb 28 08:23:53 2017 Sebastien Le Guischer
## Last update Sun Mar  5 21:17:20 2017 Sebastien Le Guischer
##

NAME		= nanotekspice

NAMELIB		= libnanotekspice.a

SRCS		= main.cpp

OBJS		= $(SRCS:.cpp=.o)

SRCSLIB		= links/AndLink.cpp\
		  links/NandLink.cpp\
		  links/NorLink.cpp\
		  links/NotLink.cpp\
		  links/OrLink.cpp\
		  links/SimpleLink.cpp\
		  links/XorLink.cpp\
		  links/Gate.cpp\
		  component/Factory.cpp\
		  component/AndGate.cpp\
		  component/C4001.cpp\
		  component/C4011.cpp\
		  component/C4030.cpp\
		  component/C4069.cpp\
		  component/C4071.cpp\
		  component/C4081.cpp\
		  component/Input.cpp\
		  component/NandGate.cpp\
		  component/NorGate.cpp\
		  component/NotGate.cpp\
		  component/OrGate.cpp\
		  component/Output.cpp\
		  component/XorGate.cpp\
		  component/False.cpp\
		  component/True.cpp\
		  parser/Parser.cpp\
		  parser/Circuit.cpp\
		  exception/Exception.cpp

OBJSLIB		= $(SRCSLIB:.cpp=.o)

CPPFLAGS	= -Wall -Wextra -W -std=c++11 -Ilinks -Icomponent -Iparser -Icircuit -Iexception -I.

GPP		= g++

RM		= rm -f

all:		$(NAMELIB) $(NAME)

$(NAME):	$(OBJS)
	$(GPP) -o $(NAME) $(OBJS) $(CPPFLAGS) -L. -lnanotekspice

$(NAMELIB): 	$(OBJSLIB)
	ar rvs $(NAMELIB) $(OBJSLIB)

clean:
	$(RM) $(OBJS) $(OBJSLIB)

fclean:		clean
	$(RM) $(NAME)
	$(RM) $(NAMELIB)

re:		fclean all

.PHONY:		all clean fclean re
