/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   Cat.cpp                                         |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2023/05/31 09:54:01 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2023/05/31 09:54:01 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include <Cat.hpp>

/* **************************Orthodox_Canonical_Form************************* */

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << *this << " default constructor called" << std::endl;
}

Cat::Cat(const Cat &rhs)
{
	*this = rhs;
	std::cout << *this << " copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	std::cout << *this << " assignation operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << BRED << "Destructor called by " << *this << " at " << this
			  << NC << std::endl;
}

/* **************************Public_member_functions************************* */

void Cat::makeSound() const
{
	std::cout << "The " << *this << " says: Meow!" << std::endl;
}

/* ************************************************************************** */
