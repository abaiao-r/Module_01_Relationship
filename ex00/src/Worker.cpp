/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guest <guest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:17:13 by guest             #+#    #+#             */
/*   Updated: 2024/07/23 11:25:06 by guest            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Worker.hpp"
#include "../includes/colours.hpp"

Worker::Worker()
{
    std::cout << YELLOW << "Worker default constructor called" << RESET 
        << std::endl;
    
    this->coordonnee.x = 0;
    this->coordonnee.y = 0;
    this->coordonnee.z = 0;
    this->stat.level = 0;
    this->stat.exp = 0;
}

Worker::Worker(int x, int y, int z, int level, int exp)
{
    std::cout << YELLOW << "Worker parameterized constructor called" << RESET 
        << std::endl;

    this->coordonnee.x = x;
    this->coordonnee.y = y;
    this->coordonnee.z = z;
    this->stat.level = level;
    this->stat.exp = exp;
}

Worker::Worker(const Worker &src) : coordonnee(src.coordonnee), stat(src.stat)
{
    std::cout << YELLOW << "Worker copy constructor called" << RESET 
        << std::endl;
}

Worker::~Worker(void)
{
    std::cout << ORANGE << "Worker destructor called" << RESET << std::endl;
}

Worker &Worker::operator=(const Worker &rhs)
{
    std::cout << YELLOW << "Worker assignation operator called" << RESET 
        << std::endl;
    if (this != &rhs)
    {
        this->coordonnee = rhs.coordonnee;
        this->stat = rhs.stat;
    }
    return (*this);
}

void Worker::setPosition(int x, int y, int z)
{
    std::cout << "Worker setPosition called: x = " << x << ", y = " 
        << y << ", z = " << z << std::endl;
    this->coordonnee.x = x;
    this->coordonnee.y = y;
    this->coordonnee.z = z;
}

void Worker::setStatistic(int level, int exp)
{
    std::cout << "Worker setStatistic called: level = " << level 
        << ", exp = " << exp << std::endl;
    this->stat.level = level;
    this->stat.exp = exp;
}

const position &Worker::getPosition(void) const
{
    std::cout << "Worker getPosition called! Position: x = " 
        << this->coordonnee.x << ", y = " << this->coordonnee.y << ", z = " 
        << this->coordonnee.z << std::endl;
    return (this->coordonnee);
}

const statistic &Worker::getStatistic(void) const
{
    std::cout << "Worker getStatistic called! Statistic: level = " 
        << this->stat.level << ", exp = " << this->stat.exp << std::endl;
    return (this->stat);
}


