/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:22:43 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/29 19:33:33 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default"), ScavTrap("default"), DiamondTrap("default"), name("default") {
	this->hit_points + DiamondTrap::hit_points;
	this->energy_points + ScavTrap::energy_points;
	this->attack_damage + DiamondTrap::attack_damage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), DiamondTrap(name), name(name) {
	this->hit_points + DiamondTrap::hit_points;
	this->energy_points + ScavTrap::energy_points;
	this->attack_damage + DiamondTrap::attack_damage;
	std::cout << "DiamondTrap named constructor called for " << name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src) {
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &src) {
		ClapTrap::operator=(src);
		this->name = src.name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called for " << name << std::endl;
}

void	DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called for " << name << std::endl;
}
