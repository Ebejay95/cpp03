/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:16:04 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/29 17:18:54 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap named constructor called for " << name << std::endl;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap& FragTrap::operator=(const FragTrap& src) {
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &src) {
		this->name = src.name;
		this->hit_points = src.hit_points;
		this->energy_points = src.energy_points;
		this->attack_damage = src.attack_damage;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called for " << name << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	if (this->energy_points <= 0)
	{
		std::cout << "FragTrap " << this->name << " would require more energy to attack." << std::endl;
		return ;
	}
	if (this->hit_points <= 0)
	{
		std::cout << "FragTrap " << this->name << " can only attack if alive" << std::endl;
		return ;
	}
	this->energy_points--;
	std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys() {
	if (this->energy_points <= 0)
	{
		std::cout << "FragTrap " << this->name << " would require more energy to give a high five." << std::endl;
		return ;
	}
	if (this->hit_points <= 0)
	{
		std::cout << "FragTrap " << this->name << " can only give a high five if alive" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->name << " enthusiastically requests a high five! ✋" << std::endl;
}

