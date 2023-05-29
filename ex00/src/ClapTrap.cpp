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

bool ClapTrap::canPerformAction(const std::string &action) const
{
	if (_hit_points == 0)
	{
		log_is_dead(action);
		return (false);
	}
	if (_energy_points == 0)
	{
		log_no_energy(action);
		return (false);
	}
	return (true);
}

void ClapTrap::attack(const std::string &target)
{
	if (!canPerformAction("attack"))
		return;
	_energy_points--;
	logMessage(MAG, _name + " attacks " + target + " causing " +
						std::to_string(_attack_damage) +
						" points of damage !\nNew Energy points: " +
						std::to_string(_energy_points));
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!canPerformAction(""))
		return;
	_hit_points = (_hit_points < amount) ? 0 : _hit_points - amount;
	logMessage(YEL, _name + " took " + std::to_string(amount) +
						" points of damage !\nNew health_total: " +
						std::to_string(_hit_points));
	if (_hit_points == 0)
	{
		logMessage(RED, _name + " has died ");
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!canPerformAction("repair"))
		return;
	_energy_points--;
	unsigned int actual_repair_amount =
		(_hit_points + amount > 10) ? 10 - _hit_points : amount;
	_hit_points += actual_repair_amount;
	logMessage(
		GRN,
		_name + " repaired itself for " + std::to_string(actual_repair_amount) +
			"\nNew health_total: " + std::to_string(_hit_points) +
			"\nRemaining Energy points: " + std::to_string(_energy_points));
}

/* **************************Loggers***************************************** */

void ClapTrap::logMessage(const std::string &color,
						  const std::string &message) const
{
	std::cout << color << message << NC << std::endl;
}

void ClapTrap::log_no_energy(std::string action) const
{
	logMessage(CYN, _name + " has no energy points left to " + action);
}

void ClapTrap::log_is_dead(std::string action) const
{
	logMessage(RED, _name + " is dead.\n" + action + "ing is not possible...");
}

void ClapTrap::log_construction(std::string message) const
{
	logMessage(GRN, message + "\nName: " + _name +
						"\nHit points: " + std::to_string(_hit_points) +
						"\nEnergy points: " + std::to_string(_energy_points) +
						"\nAttack damage: " + std::to_string(_attack_damage));
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
