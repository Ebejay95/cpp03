/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:37:27 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/28 13:37:52 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

ClapTrap::ClapTrap() : name("\"claptrap\""), hit_points(10), energy_points(10), attack_damage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0) {
	std::cout << "ClapTrap named constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src) {
	if (this != &src)
	{
		this->name = src.name;
		this->hit_points = src.hit_points;
		this->energy_points = src.energy_points;
		this->attack_damage = src.attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called for " << name << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->energy_points <= 0 || this->hit_points <= 0)
		return ;
	this->energy_points--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hit_points <= 0)
		return ;
	this->hit_points = this->hit_points - amount;
	if (this->hit_points < 0)
		this->hit_points = 0;
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energy_points <= 0 || this->hit_points <= 0) {
		std::cout << "ClapTrap " << this->name << " can't repair itself - no energy or hit points left!" << std::endl;
		return ;
	}
	this->energy_points--;
	this->hit_points += amount;
	std::cout << "ClapTrap " << this->name << " repairs itself for " << amount << " hit points!" << std::endl;
}
