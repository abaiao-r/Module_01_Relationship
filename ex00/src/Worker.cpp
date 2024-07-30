/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guest <guest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:17:13 by guest             #+#    #+#             */
/*   Updated: 2024/07/30 11:40:13 by guest            ###   ########.fr       */
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
    this->shovel = NULL;
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
    this->shovel = NULL;
}

Worker::Worker(const Worker &src) : coordonnee(src.coordonnee), stat(src.stat), 
    shovel(src.shovel)
{
    std::cout << YELLOW << "Worker copy constructor called" << RESET 
        << std::endl;
}

Worker::~Worker(void)
{
    std::cout << ORANGE << "Worker destructor called" << RESET << std::endl;
    if (this->shovel)
    {
        std::cout << "Worker still has a shovel." << std::endl;
    }
}

Worker &Worker::operator=(const Worker &rhs)
{
    std::cout << YELLOW << "Worker assignation operator called" << RESET 
        << std::endl;
    if (this != &rhs)
    {
        this->coordonnee = rhs.coordonnee;
        this->stat = rhs.stat;
        this->shovel = rhs.shovel;
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

void Worker::giveShovel(Shovel *newShovel)
{
    std::cout << "Worker giveShovel called" << std::endl;
    if (this->shovel)
    {
        std::cout << "Worker already has a shovel." << std::endl;
        shovel = NULL;
    }
    this->shovel = newShovel;
    std::cout << "Shovel given to worker." << std::endl;
}

void Worker::useShovel(void)
{
    std::cout << "Worker useShovel called" << std::endl;
    if (this->shovel)
        this->shovel->use();
    else
        std::cout << "Worker has no shovel to use." << std::endl;
}

void Worker::takeShovel(void)
{
    std::cout << "Worker takeShovel called" << std::endl;
    this->shovel = NULL;
    std::cout << "Shovel taken away from worker." << std::endl;
}
