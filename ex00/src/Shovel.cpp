/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guest <guest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:04:02 by guest             #+#    #+#             */
/*   Updated: 2024/07/23 12:05:23 by guest            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Shovel.hpp"

Shovel::Shovel(void) : numberOfUses(0)
{
    std::cout << YELLOW << "Shovel default constructor called" << RESET 
        << std::endl;
}

Shovel::Shovel(const Shovel &src)
{
    std::cout << YELLOW << "Shovel copy constructor called" << RESET 
        << std::endl;
    *this = src;
}

Shovel::~Shovel(void)
{
    std::cout << ORANGE << "Shovel destructor called" << RESET << std::endl;
}

Shovel &Shovel::operator=(const Shovel &rhs)
{
    std::cout << YELLOW << "Shovel assignation operator called" << RESET 
        << std::endl;
    if (this != &rhs)
        this->numberOfUses = rhs.numberOfUses;
    return (*this);
}

void Shovel::use(void)
{
    std::cout << YELLOW << "Shovel used" << RESET << std::endl;
    this->numberOfUses++;
}

const size_t &Shovel::getNumberOfUses(void) const
{
    return (this->numberOfUses);
}
