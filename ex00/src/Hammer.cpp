/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hammer.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 20:04:57 by abaiao-r          #+#    #+#             */
/*   Updated: 2024/08/14 20:45:24 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Hammer.hpp"

Hammer::Hammer(void) : ATool("Hammer")
{    //print: what constructor is called, the id of the object, and the number of uses
    std::cout << YELLOW << "Hammer default constructor called" << RESET 
        << std::endl;
}

Hammer::Hammer(const Hammer &src) : ATool(src)
{
    *this = src;
    this->numberOfUses = 0;
    this->owner = NULL;
    //print: what constructor is called, the id of the object, and the number of uses
    std::cout << YELLOW << "Hammer copy constructor called" << RESET 
        << std::endl;
}

Hammer::~Hammer(void)
{
    //print: what is being called, the id of the object, and the number of uses
    std::cout << ORANGE << "Hammer destructor called" << RESET << std::endl;
}

Hammer &Hammer::operator=(const Hammer &rhs)
{
    if (this != &rhs)
    {
        this->type = rhs.type;
        this->numberOfUses = 0;
        this->owner = NULL;
    }
    //print: what constructor is called, the id of the object, and the number of uses
    std::cout << YELLOW << "Hammer assignation operator called" << RESET 
        << std::endl;
    
    return (*this);
}

void Hammer::use(void)
{
    this->numberOfUses++;
    //print: what is being called, the id of the object, and the number of uses
    std::cout << YELLOW << "Hammer used" << RESET << std::endl;
    printToolInfo();
}
