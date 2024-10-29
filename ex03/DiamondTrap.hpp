/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:22:44 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/29 19:18:10 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <string>
#include <iostream>
#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : virtual public DiamondTrap, virtual public ScavTrap {
	private:
		std::string	name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& src);
		DiamondTrap& operator=(const DiamondTrap& src);
		~DiamondTrap();
		void	attack(const std::string& target);
		void	whoAmI(void);
};

#endif
