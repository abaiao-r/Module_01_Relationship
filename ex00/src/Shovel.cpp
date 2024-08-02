/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guest <guest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:04:02 by guest             #+#    #+#             */
/*   Updated: 2024/08/02 11:04:18 by guest            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Shovel.hpp"

size_t Shovel::nextId = 1;

Shovel::Shovel(void) : numberOfUses(0), idShovel(nextId++)
{
    //print: what constructor is called, the id of the object, and the number of uses
    std::cout << YELLOW << "Shovel default constructor called" << RESET 
        << std::endl;
    
    getIdShovel();
    getNumberOfUses(); 
}

Shovel::Shovel(const Shovel &src) : idShovel(nextId++)
{
    *this = src;
    //print: what constructor is called, the id of the object, and the number of uses
    std::cout << YELLOW << "Shovel copy constructor called" << RESET 
        << std::endl;
    getIdShovel();
    getNumberOfUses();
}

Shovel::~Shovel(void)
{
    //print: what is being called, the id of the object, and the number of uses
    std::cout << ORANGE << "Shovel destructor called" << RESET << std::endl;
    getIdShovel();
    getNumberOfUses();
}

Shovel &Shovel::operator=(const Shovel &rhs)
{
    if (this != &rhs)
    {
        this->numberOfUses = rhs.numberOfUses;
    }
    //print: what constructor is called, the id of the object, and the number of uses
    std::cout << YELLOW << "Shovel assignation operator called" << RESET 
        << std::endl;
    getIdShovel();
    getNumberOfUses();
    
    return (*this);
}

void Shovel::use(void)
{
    this->numberOfUses++;
    //print: what is being called, the id of the object, and the number of uses
    std::cout << YELLOW << "Shovel used" << RESET << std::endl;
    getIdShovel();
    getNumberOfUses();
}

const size_t &Shovel::getNumberOfUses(void) const
{
    //print: the number of uses of the shovel
    std::cout << YELLOW << "Number of uses: " << this->numberOfUses << RESET 
        << std::endl;
    return (this->numberOfUses);
}

const size_t &Shovel::getIdShovel(void) const
{
    //print: the id of the shovel
    std::cout << YELLOW << "Id of the shovel: " << this->idShovel << RESET 
        << std::endl;
    return (this->idShovel);
}

