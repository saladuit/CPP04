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

#include "Color.hpp"
#include <Cat.hpp>

/* **************************Orthodox_Canonical_Form************************* */

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << YEL << *this << " default constructor called" << NC
			  << std::endl;
}

Cat::Cat(const Cat &rhs)
{
	*this = rhs;
	std::cout << YEL << *this << " copy constructor called" << NC << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
		Animal::operator=(rhs);
	std::cout << YEL << *this << " assignation operator called" << NC
			  << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << BRED << "Cat destructor called by " << *this << " at " << this
			  << NC << std::endl;
}

/* **************************Public_member_functions************************* */

void Cat::makeSound() const
{
	std::cout << CYN << "The " << *this << " says: Meow!" << NC << std::endl;
}

/* ************************************************************************** */
