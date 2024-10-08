/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:04:02 by guest             #+#    #+#             */
/*   Updated: 2024/08/14 20:45:05 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Shovel.hpp"

Shovel::Shovel(void) : ATool("Shovel")
{    //print: what constructor is called, the id of the object, and the number of uses
    std::cout << YELLOW << "Shovel default constructor called" << RESET 
        << std::endl;
}

Shovel::Shovel(const Shovel &src) : ATool(src)
{
    *this = src;
    this->numberOfUses = 0;
    this->owner = NULL;
    //print: what constructor is called, the id of the object, and the number of uses
    std::cout << YELLOW << "Shovel copy constructor called" << RESET 
        << std::endl;
}

Shovel::~Shovel(void)
{
    //print: what is being called, the id of the object, and the number of uses
    std::cout << ORANGE << "Shovel destructor called" << RESET << std::endl;
}

Shovel &Shovel::operator=(const Shovel &rhs)
{
    if (this != &rhs)
    {
        this->type = rhs.type;
        this->numberOfUses = 0;
        this->owner = NULL;
    }
    //print: what constructor is called, the id of the object, and the number of uses
    std::cout << YELLOW << "Shovel assignation operator called" << RESET 
        << std::endl;
    
    return (*this);
}

void Shovel::use(void)
{
    this->numberOfUses++;
    //print: what is being called, the id of the object, and the number of uses
    std::cout << YELLOW << "Shovel used" << RESET << std::endl;
    printToolInfo();
}
