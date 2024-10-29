/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:13:41 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/29 23:17:57 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(std::string init_name) : ClapTrap(init_name) {
	std::cout << "ScavTrap named constructor called for " << init_name << std::endl;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src) {
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &src) {
		this->name = src.name;
		this->hit_points = src.hit_points;
		this->energy_points = src.energy_points;
		this->attack_damage = src.attack_damage;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called for " << name << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (this->energy_points <= 0)
	{
		std::cout << "ScavTrap " << this->name << " would require more energy to attack." << std::endl;
		return ;
	}
	if (this->hit_points <= 0)
	{
		std::cout << "ScavTrap " << this->name << " can only attack if alive" << std::endl;
		return ;
	}
	this->energy_points--;
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}
