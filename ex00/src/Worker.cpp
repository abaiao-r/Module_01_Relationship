/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:17:13 by guest             #+#    #+#             */
/*   Updated: 2024/08/12 12:59:36 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Worker.hpp"
#include "../includes/colours.hpp"

size_t Worker::nextId = 1;

Worker::Worker() : idWorker(nextId++)
{
    std::cout << YELLOW << "Worker default constructor called" << RESET 
        << std::endl;
    
    this->coordonnee.x = 0;
    this->coordonnee.y = 0;
    this->coordonnee.z = 0;
    this->stat.level = 0;
    this->stat.exp = 0;

}

Worker::Worker(int x, int y, int z, int level, int exp) : idWorker(nextId++)
{
    std::cout << YELLOW << "Worker parameterized constructor called" << RESET 
        << std::endl;
    getIdWorker();
    this->coordonnee.x = x;
    this->coordonnee.y = y;
    this->coordonnee.z = z;
    this->stat.level = level;
    this->stat.exp = exp;

}

Worker::Worker(const Worker &src) : coordonnee(src.coordonnee), stat(src.stat), 
    idWorker(nextId++)
{
    std::cout << YELLOW << "Worker copy constructor called" << RESET 
        << std::endl;
    getIdWorker();

    // No deep copy of shovels, just copy the pointers
    for (std::vector<Shovel *>::const_iterator it = src.shovelList.begin(); 
        it != src.shovelList.end(); it++)
    {
        this->shovelList.push_back(*it); // copy the pointer, not the object
    }
}

Worker::~Worker(void)
{
    std::cout << ORANGE << "Worker destructor called" << RESET << std::endl;
    getIdWorker();
    if (this->shovelList.size() > 0)
    {
        std::cout << " However, the shovel was not destroyed." << std::endl;
        removeAllShovels();
    }
}

Worker &Worker::operator=(const Worker &rhs)
{
    std::cout << YELLOW << "Worker assignation operator called" << RESET 
        << std::endl;
    getIdWorker();
    if (this != &rhs)
    {
        this->coordonnee = rhs.coordonnee;
        this->stat = rhs.stat;
        removeAllShovels();
        // No deep copy of shovels, just copy the pointers
        for (std::vector<Shovel *>::const_iterator it = rhs.shovelList.begin(); 
            it != rhs.shovelList.end(); it++)
        {
            this->shovelList.push_back(*it); // copy the pointer, not the object
        }
    }
    return (*this);
}

void Worker::setPosition(int x, int y, int z)
{
    std::cout << "Worker setPosition called: x = " << x << ", y = " 
        << y << ", z = " << z << std::endl;
    getIdWorker();
    
    this->coordonnee.x = x;
    this->coordonnee.y = y;
    this->coordonnee.z = z;
}

void Worker::setStatistic(int level, int exp)
{
    std::cout << "Worker setStatistic called: level = " << level 
        << ", exp = " << exp << std::endl;
    getIdWorker();
    
    this->stat.level = level;
    this->stat.exp = exp;
}

const position &Worker::getPosition(void) const
{
    std::cout << "Worker getPosition called! Position: x = " 
        << this->coordonnee.x << ", y = " << this->coordonnee.y << ", z = " 
        << this->coordonnee.z << std::endl;
    getIdWorker();
    
    return (this->coordonnee);
}

const statistic &Worker::getStatistic(void) const
{
    std::cout << "Worker getStatistic called! Statistic: level = " 
        << this->stat.level << ", exp = " << this->stat.exp << std::endl;
    getIdWorker();
    
    return (this->stat);
}

const size_t &Worker::getIdWorker(void) const
{
    std::cout << "Worker getIdWorker called! Worker ID: " << this->idWorker 
        << std::endl;
    return (this->idWorker);
}

const std::vector<Shovel *> &Worker::getShovelList(void) const
{
    std::cout << "Worker getShovelList called! Worker ID: " << this->idWorker 
        << std::endl;
    return (this->shovelList);
}

void Worker::giveShovel(Shovel *newShovel)
{
    //check if the shovel is already in the list
    for (std::vector<Shovel *>::iterator it = this->shovelList.begin(); 
        it != this->shovelList.end(); it++)
    {
        if (*it == newShovel)
        {
            std::cout << "Worker " << this->idWorker << " already has shovel with ID: " 
                << newShovel->getIdShovel() << std::endl;
            return;
        }
    }

    // remove the shovel from the previous owner
    Worker *previousOwner = newShovel->getOwner();
    if (previousOwner != NULL)
    {
        previousOwner->takeAwayShovel(newShovel);
    }

    this->shovelList.push_back(newShovel);
    newShovel->setOwner(this);
    std::cout << "Worker " << this->idWorker << " received a new shovel with ID: " 
        << newShovel->getIdShovel() << std::endl;
}

void Worker::takeAwayShovel(Shovel *shovelToRemove)
{
    std::vector<Shovel *>::iterator it = this->shovelList.begin();
    while (it != this->shovelList.end())
    {
        if (*it == shovelToRemove)
        {
            std::cout << "Worker " << this->idWorker << " is removing shovel with ID: " 
                << shovelToRemove->getIdShovel() << std::endl;
            this->shovelList.erase(it);
            shovelToRemove->setOwner(NULL); // Remove the owner from the shovel
            return;
        }
        it++;
    }
    std::cout << "Worker " << this->idWorker << " did not find shovel with ID: " 
        << shovelToRemove->getIdShovel() << std::endl;
}

void Worker::removeAllShovels(void)
{
    // Optionally notify that shovels are not being deleted
    std::cout << "Worker " << this->idWorker << " is clearing all shovels without deleting them." << std::endl;
    // Remove the owner from all shovels and clear the list
    for (std::vector<Shovel *>::iterator it = this->shovelList.begin(); 
        it != this->shovelList.end(); it++)
    {
        (*it)->setOwner(NULL);
    }
    this->shovelList.clear();
}

void Worker::useShovel(size_t shovelId)
{
    std::vector<Shovel *>::iterator it = this->shovelList.begin();
    while (it != this->shovelList.end())
    {
        if ((*it)->getIdShovel() == shovelId)
        {
            (*it)->use();
            return;
        }
        it++;
    }
    std::cout << "Worker " << this->idWorker << " did not find shovel with ID: " 
        << shovelId << std::endl;
}
