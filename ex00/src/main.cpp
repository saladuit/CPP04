/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   main.cpp                                        |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2023/05/24 14:47:46 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2023/05/24 14:47:46 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include <Animal.hpp>
#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongAnimal.hpp>
#include <WrongCat.hpp>

int main(void)
{
	std::cout << "\n---Creating objects with default constructor---\n";
	Dog dog1;
	Cat cat1;
	WrongCat wrongCat1;

	std::cout << "\n---Creating objects with copy constructor---\n";
	Dog dog2(dog1);
	Cat cat2(cat1);
	WrongCat wrongCat2(wrongCat1);

	std::cout << "\n---Creating objects with assignment operator---\n";
	Dog dog3;
	dog3 = dog1;
	Cat cat3;
	cat3 = cat1;
	WrongCat wrongCat3;
	wrongCat3 = wrongCat1;

	std::cout << "\n---Creating pointers to Animal objects---\n";
	const Animal *animal = new Animal();
	const Animal *dogAnimal = new Dog();
	const Animal *catAnimal = new Cat();
	const WrongAnimal *wrongAnimal = new WrongAnimal();
	const WrongAnimal *wrongCatAnimal = new WrongCat();

	std::cout << "\n---Making sounds---\n";
	dog1.makeSound();
	cat1.makeSound();
	catAnimal->makeSound();
	dogAnimal->makeSound();
	animal->makeSound();
	wrongAnimal->makeSound();
	wrongCatAnimal->makeSound();
	wrongCat1.makeSound();

	std::cout << "\n---Deleting objects from the heap---\n";
	delete animal;
	delete dogAnimal;
	delete catAnimal;
	delete wrongAnimal;
	delete wrongCatAnimal;

	std::cout << "\n---Deleting objects from the stack---\n";
	return (0);
}

/* ************************************************************************** */
