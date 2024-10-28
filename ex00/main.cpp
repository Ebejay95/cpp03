/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:56:23 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/28 13:14:52 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap clap1("Clappy");
	ClapTrap clap2("Trappy");

	std::cout << "\nTesting basic attacks:" << std::endl;
	clap1.attack("Trappy");
	clap2.takeDamage(0);

	std::cout << "\nTesting repair:" << std::endl;
	clap2.beRepaired(5);

	std::cout << "\nTesting energy points depletion:" << std::endl;
	for (int i = 0; i < 11; i++)
	{
		clap1.attack("Trappy");
	}

	std::cout << "\nTesting death scenario:" << std::endl;
	clap2.takeDamage(15);
	clap2.attack("Clappy");
	clap2.beRepaired(5);

	return (0);
}
