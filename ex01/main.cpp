/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:37:29 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/28 16:57:34 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

void printSeparator() {
    std::cout << "\n----------------------------------------\n" << std::endl;
}

int main(void)
{
	std::cout << "TESTING CONSTRUCTORS AND INHERITANCE:" << std::endl;
	{
		printSeparator();
		std::cout << "Testing default constructors:" << std::endl;
		ClapTrap clap1;
		ScavTrap scav1;
		printSeparator();
		std::cout << "Testing named constructors:" << std::endl;
		ClapTrap clap2("C2");
		ScavTrap scav2("S2");
		printSeparator();
		std::cout << "Testing copy constructors:" << std::endl;
		ClapTrap clap3(clap2);
		ScavTrap scav3(scav2);
	}
	printSeparator();
	std::cout << "TESTING BASIC COMBAT FUNCTIONALITY:" << std::endl;
	{
		ClapTrap fighter("Fighter");
		ScavTrap defender("Defender");
		std::cout << "\nBasic attack sequence:" << std::endl;
		fighter.attack("Defender");
		defender.attack("Fighter");
		fighter.takeDamage(20);
		fighter.beRepaired(10);
	}
	printSeparator();
	std::cout << "TESTING ENERGY POINT DEPLETION:" << std::endl;
	{
		ClapTrap clap("TiredClap");
		ScavTrap scav("TiredScav");
		std::cout << "\nDepleting ClapTrap energy (should stop at 10):" << std::endl;
		for (int i = 0; i < 12; i++) {
			std::cout << "\nAttempt " << i + 1 << ":" << std::endl;
			clap.attack("target");
		}
		std::cout << "\nDepleting ScavTrap energy (should stop at 50):" << std::endl;
		for (int i = 0; i < 52; i++) {
			if (i % 10 == 0) std::cout << "\nAttempt " << i + 1 << ":" << std::endl;
			scav.attack("target");
		}
	}
	printSeparator();
	std::cout << "TESTING DEATH SCENARIOS:" << std::endl;
	{
		ClapTrap clap("Mortal1");
		ScavTrap scav("Mortal2");
		std::cout << "\nTesting ClapTrap death:" << std::endl;
		clap.takeDamage(15);
		clap.attack("target");
		clap.beRepaired(5);
		std::cout << "\nTesting ScavTrap death:" << std::endl;
		scav.takeDamage(50);
		scav.beRepaired(20);
		scav.takeDamage(70);
		scav.attack("target");
		scav.guardGate();
	}
	printSeparator();
	std::cout << "TESTING SCAVTRAP SPECIAL ABILITIES:" << std::endl;
	{
		ScavTrap guardian("Guardian");
		std::cout << "\nTesting guard gate:" << std::endl;
		guardian.guardGate();
		guardian.attack("intruder");
		guardian.takeDamage(30);
		guardian.guardGate();
		guardian.beRepaired(15);
		guardian.guardGate();
	}
	printSeparator();
	std::cout << "END OF TESTS - Destructors will be called:" << std::endl;
	return (0);
}
