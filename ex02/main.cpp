/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:13:37 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/29 09:34:04 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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
		FragTrap frag1;
		printSeparator();
		std::cout << "Testing named constructors:" << std::endl;
		ClapTrap clap2("C2");
		ScavTrap scav2("S2");
		FragTrap frag2("F2");
		printSeparator();
		std::cout << "Testing copy constructors:" << std::endl;
		ClapTrap clap3(clap2);
		ScavTrap scav3(scav2);
		FragTrap frag3(frag2);
	}
	printSeparator();
	std::cout << "TESTING BASIC COMBAT FUNCTIONALITY:" << std::endl;
	{
		ClapTrap fighter("Fighter");
		ScavTrap defender("Defender");
		FragTrap fragger("Fragger");
		std::cout << "\nBasic attack sequence:" << std::endl;
		fighter.attack("Defender");
		defender.attack("Fighter");
		fragger.attack("Fighter");
		fragger.attack("Defender");
		fighter.takeDamage(20);
		fighter.beRepaired(10);
		defender.takeDamage(20);
		defender.beRepaired(10);
		fragger.takeDamage(20);
		fragger.beRepaired(10);
	}
	printSeparator();
	std::cout << "TESTING ENERGY POINT DEPLETION:" << std::endl;
	{
		ClapTrap clap("TiredClap");
		ScavTrap scav("TiredScav");
		FragTrap frag("TiredFrag");
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
		std::cout << "\nDepleting FragTrap energy (should stop at 100):" << std::endl;
		for (int i = 0; i < 102; i++) {
			if (i % 30 == 0) std::cout << "\nAttempt " << i + 1 << ":" << std::endl;
			frag.attack("target");
		}
	}
	printSeparator();
	std::cout << "TESTING DEATH SCENARIOS:" << std::endl;
	{
		ClapTrap clap("Mortal1");
		ScavTrap scav("Mortal2");
		FragTrap frag("Mortal3");
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
		std::cout << "\nTesting FragTrap death:" << std::endl;
		frag.takeDamage(60);
		frag.beRepaired(30);
		frag.takeDamage(70);
		frag.attack("target");
		frag.highFivesGuys();
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
	std::cout << "TESTING FRAGTRAP SPECIAL ABILITIES:" << std::endl;
	{
		FragTrap friendly("Friendly");
		std::cout << "\nTesting high fives:" << std::endl;
		friendly.highFivesGuys();
		friendly.attack("dummy");
		friendly.takeDamage(40);
		friendly.highFivesGuys();
		friendly.beRepaired(20);
		friendly.highFivesGuys();
		std::cout << "\nTesting high fives with depleted energy:" << std::endl;
		for (int i = 0; i < 102; i++) {
			friendly.attack("dummy");
		}
		friendly.highFivesGuys();
	}
	printSeparator();
	std::cout << "END OF TESTS - Destructors will be called:" << std::endl;
	return (0);
}
