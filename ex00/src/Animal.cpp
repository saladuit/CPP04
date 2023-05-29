/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ClapTrap.cpp                                    |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2023/05/24 14:47:37 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2023/05/24 14:47:37 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include <ClapTrap.hpp>
#include <Color.hpp>

/* **************************Public_member_functions************************* */

/* **************************Loggers***************************************** */

void ClapTrap::logMessage(const std::string &color,
						  const std::string &message) const
{
	std::cout << color << message << NC << std::endl;
}

/* **************************Orthodox_Canonical_Form************************* */

ClapTrap::ClapTrap()
	: _name("CL4P-TP"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	log_construction("ClapTrap called default constructor");
}

ClapTrap::ClapTrap(const std::string name)
	: _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	log_construction("ClapTrap called Copy constructor");
}

ClapTrap::ClapTrap(const ClapTrap &rhs)
	: _name(rhs._name), _hit_points(rhs._hit_points),
	  _energy_points(rhs._energy_points), _attack_damage(rhs._attack_damage)
{
	log_construction("ClapTrap called Copy constructor");
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_hit_points = rhs._hit_points;
		_energy_points = rhs._energy_points;
		log_construction("Copy assignment operator called");
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	logMessage(BRED, "Destructor called by " + _name);
}
