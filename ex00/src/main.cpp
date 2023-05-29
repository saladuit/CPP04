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

#include <ClapTrap.hpp>
#include <Color.hpp>

void test_default_constructor(void)
{
	ClapTrap clap_trap;

	clap_trap.attack("Martijn");
	clap_trap.attack("Victor");
	clap_trap.attack("lucien");
	clap_trap.takeDamage(5);
	clap_trap.beRepaired(1);
	clap_trap.beRepaired(10);
	clap_trap.attack("Victor");
	clap_trap.attack("Victor");
	clap_trap.attack("Victor");
	clap_trap.attack("Victor");
	clap_trap.attack("Victor");
	clap_trap.beRepaired(2); // Can be switched out for attack
	clap_trap.takeDamage(5);
	clap_trap.takeDamage(10);
	// show that it is dead
	clap_trap.takeDamage(10);
	clap_trap.attack("Show that it is dead");
	clap_trap.beRepaired(10);
}

void test_constructors(void)
{
	ClapTrap saladin("Saladin");
	ClapTrap saladin_copy(saladin);
	ClapTrap default_claptrap;
	default_claptrap = saladin;
}

int main(void)
{
	std::cout << std::endl << BCYN "TEST default behaviour:" << std::endl;
	test_default_constructor();
	std::cout << std::endl << BCYN "TEST other constructors:" << std::endl;
	test_constructors();
	return (0);
}
