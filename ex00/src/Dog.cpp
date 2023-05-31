/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   Dog.cpp                                         |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2023/05/31 09:40:55 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2023/05/31 09:40:55 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include <Dog.hpp>

/* **************************Orthodox_Canonical_Form************************* */

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &rhs)
{
	*this = rhs;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

/* **************************Public_member_functions************************* */

void Dog::makeSound() const
{
	std::cout << "The " << *this << " says: Woof Woof!" << std::endl;
}

/* ************************************************************************** */
