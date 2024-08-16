/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:17:13 by guest             #+#    #+#             */
/*   Updated: 2024/08/16 22:42:55 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Worker.hpp"

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

    // No deep copy of tools, just copy the pointers
    for (std::vector<ATool *>::const_iterator it = src.toolList.begin(); 
        it != src.toolList.end(); it++)
    {
        this->toolList.push_back(*it); // copy the pointer, not the object
    }

}

Worker::~Worker(void)
{
    std::cout << ORANGE << "Worker destructor called" << RESET << std::endl;
    getIdWorker();
    if (this->toolList.size() > 0)
    {
        std::cout << " However, the tool was not destroyed." << std::endl;
        removeAllTools();
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
        removeAllTools();
        // No deep copy of tools, just copy the pointers
        for (std::vector<ATool *>::const_iterator it = rhs.toolList.begin(); 
            it != rhs.toolList.end(); it++)
        {
            this->toolList.push_back(*it); // copy the pointer, not the object
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

void Worker::addWorkshop(Workshop *workshop)
{
    //check if the workshop is NULL
    if (workshop == NULL)
    {
        std::cout << "Worker " << this->idWorker << " cannot register in a NULL workshop." << std::endl;
        return;
    }

    //check if the workshop is already in the list
    for (std::vector<Workshop *>::iterator it = this->workshopList.begin(); 
        it != this->workshopList.end(); it++)
    {
        if (*it == workshop)
        {
            std::cout << "Worker " << this->idWorker << " already registered in workshop with ID: " 
                << workshop->getIdWorkshop() << std::endl;
            return;
        }
    }

    this->workshopList.push_back(workshop);
    std::cout << "Worker 1 registered in workshop with ID: " << workshop->getIdWorkshop() << std::endl;
    
}

void Worker::removeWorkshop(Workshop *workshop)
{
    //check if the workshop is NULL
    if (workshop == NULL)
    {
        std::cout << "Worker " << this->idWorker << " cannot unregister from a NULL workshop." << std::endl;
        return;
    }

    std::vector<Workshop *>::iterator it = this->workshopList.begin();
    while (it != this->workshopList.end())
    {
        if (*it == workshop)
        {
            std::cout << "Worker " << this->idWorker << " is unregistering from workshop with ID: " 
                << workshop->getIdWorkshop() << std::endl;
            this->workshopList.erase(it);
            return;
        }
        it++;
    }
    std::cout << "Worker " << this->idWorker << " is not registered in workshop with ID: " 
        << workshop->getIdWorkshop() << std::endl;
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

const std::vector<ATool *> &Worker::getToolList(void) const
{
    std::cout << "Worker getToolList called! Worker ID: " << this->idWorker 
        << std::endl;
    return (this->toolList);
}

const std::vector<Workshop *> &Worker::getWorkshopList(void) const
{
    std::cout << "Worker getWorkshopList called! Worker ID: " << this->idWorker 
        << std::endl;
    return (this->workshopList);
}

void Worker::giveTool(ATool *newTool)
{
    //check if the tool is already in the list
    for (std::vector<ATool *>::iterator it = this->toolList.begin(); 
        it != this->toolList.end(); it++)
    {
        if (*it == newTool)
        {
            std::cout << "Worker " << this->idWorker << " already has tool with ID: " 
                << newTool->getIdTool() << std::endl;
            return;
        }
    }

    // remove the tool from the previous owner
    Worker *previousOwner = newTool->getOwner();
    if (previousOwner != NULL)
    {
        previousOwner->takeAwayTool(newTool);
    }

    this->toolList.push_back(newTool);
    newTool->setOwner(this);
    std::cout << "Worker " << this->idWorker << " received a new tool with ID: " 
        << newTool->getIdTool() << std::endl;
}

void Worker::takeAwayTool(ATool *toolToRemove)
{
    std::vector<ATool *>::iterator it = this->toolList.begin();
    while (it != this->toolList.end())
    {
        if (*it == toolToRemove)
        {
            std::cout << "Worker " << this->idWorker << " is removing tool with ID: " 
                << toolToRemove->getIdTool() << std::endl;
            this->toolList.erase(it);
            toolToRemove->setOwner(NULL); // Remove the owner from the tool
            // check 
            // check if worker has the tools needed to work in the workshop that he is registered in
            // if not, remove the worker from the workshop
            for (std::vector<Workshop *>::iterator item = this->workshopList.begin(); 
                item != this->workshopList.end(); item++)
            {
                if (!(*item)->hasRequiredTools(this))
                {
                    (*item)->unregisterWorker(this);
                }
            }
            return;
        }
        it++;
    }

    std::cout << "Worker " << this->idWorker << " did not find tool with ID: " 
        << toolToRemove->getIdTool() << std::endl;
}

void Worker::removeAllTools(void)
{
    // Optionally notify that tools are not being deleted
    std::cout << "Worker " << this->idWorker << " is clearing all tools without deleting them." << std::endl;
    // Remove the owner from all tools and clear the list
    for (std::vector<ATool *>::iterator it = this->toolList.begin(); 
        it != this->toolList.end(); it++)
    {
        (*it)->setOwner(NULL);
    }
    this->toolList.clear();
    // remove worker from all workshops that he is registered in
    for (std::vector<Workshop *>::iterator it = this->workshopList.begin(); 
        it != this->workshopList.end(); it++)
    {
        (*it)->unregisterWorker(this);
    }
}

void Worker::useTool(size_t toolId)
{
    std::vector<ATool *>::iterator it = this->toolList.begin();
    while (it != this->toolList.end())
    {
        if ((*it)->getIdTool() == toolId)
        {
            (*it)->use();
            return;
        }
        it++;
    }
    std::cout << "Worker " << this->idWorker << " did not find tool with ID: " 
        << toolId << std::endl;
}

void Worker::work(Workshop &workshop)
{
    // check if the worker is registered in the workshop
    if (!workshop.isWorkerRegistered(this))
    {
        std::cout << "Worker " << this->idWorker << " is not registered in workshop with ID: " 
            << workshop.getIdWorkshop() << std::endl;
        return;
    }
    // check if the worker has all the required tools
    if (!workshop.hasRequiredTools(this))
    {
        std::cout << "Worker " << this->idWorker << " does not have all the required tools for workshop with ID: " 
            << workshop.getIdWorkshop() << std::endl;
        return;
    }
    std::cout << "Worker " << this->idWorker << " is working in workshop with ID: " 
        << workshop.getIdWorkshop() << std::endl;
}

void Worker::displayWorkshops(void) const
{
    std::cout << YELLOW<< "Worker " << this->idWorker << " is registered in the following workshops:" << RESET << std::endl;
    for (std::vector<Workshop *>::const_iterator it = this->workshopList.begin(); 
        it != this->workshopList.end(); it++)
    {
        std::cout << "Workshop ID: " << (*it)->getIdWorkshop() << std::endl;
    }
}

template <typename ToolType>
 ToolType* Worker::GetTool(void) const
{
    for (std::vector<ATool *>::const_iterator it = this->toolList.begin(); 
        it != this->toolList.end(); it++)
    {
        if (dynamic_cast<ToolType*>(*it))
        {
            return (dynamic_cast<ToolType*>(*it));
        }
    }
    return (NULL);
}