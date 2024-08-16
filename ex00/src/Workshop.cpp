/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Workshop.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:46:36 by abaiao-r          #+#    #+#             */
/*   Updated: 2024/08/16 22:30:45 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Workshop.hpp"

size_t Workshop::nextId = 1;

Workshop::Workshop() : idWorkshop(nextId++)
{
    std::cout << YELLOW << "Workshop default constructor called" << RESET 
        << std::endl;
}

Workshop::Workshop(const std::vector<std::string> &toolsNeeded) : idWorkshop(nextId++)
{
    std::cout << YELLOW << "Workshop parameterized constructor called" << RESET 
        << std::endl;

    this->toolsNeeded = toolsNeeded;
}

Workshop::Workshop(const Workshop &src) : idWorkshop(nextId++)
{
    std::cout << YELLOW << "Workshop copy constructor called" << RESET 
        << std::endl;

    // No deep copy of workers, just copy the pointers
    for (std::vector<Worker *>::const_iterator it = src.workerList.begin(); 
        it != src.workerList.end(); it++)
    {
        this->workerList.push_back(*it); // copy the pointer, not the object
    }

}

Workshop &Workshop::operator=(const Workshop &rhs)
{
    std::cout << YELLOW << "Workshop assignation operator called" << RESET 
        << std::endl;

    if (this != &rhs)
    {
        removeAllWorkers();

        // No deep copy of workers, just copy the pointers
        for (std::vector<Worker *>::const_iterator it = rhs.workerList.begin(); 
            it != rhs.workerList.end(); it++)
        {
            this->workerList.push_back(*it); // copy the pointer, not the object
        }
    }

    return (*this);
}

Workshop::~Workshop(void)
{
    std::cout << YELLOW << "Workshop destructor called" << RESET << std::endl;
    removeAllWorkers();
}

const std::vector<Worker *> &Workshop::getWorkerList(void) const
{
    return (this->workerList);
}

const std::vector<std::string> &Workshop::getToolsNeeded(void) const
{
    return (this->toolsNeeded);
}

const size_t &Workshop::getIdWorkshop(void) const
{
    return (this->idWorkshop);
}

// check if the worker is registered in the workshop
bool Workshop::isWorkerRegistered(Worker *workerToCheck) const
{
    for (std::vector<Worker *>::const_iterator it = this->workerList.begin(); 
        it != this->workerList.end(); it++)
    {
        if (*it == workerToCheck)
        {
            std::cout << "Worker " << workerToCheck->getIdWorker() 
                << " is already registered in Workshop " << this->idWorkshop << std::endl;
            return (true);
        }
    }
    return (false);
}

// Check if the worker has all the required tools by the workshop
bool Workshop::hasRequiredTools(Worker *workerToCheck) const
{
    // store get the worker's tool list
    std::vector<ATool *> workerToolList = workerToCheck->getToolList();
    // check if the worker has all the required tools using GetTool method
    for (std::vector<std::string>::const_iterator it = this->toolsNeeded.begin(); 
        it != this->toolsNeeded.end(); it++)
    {
        bool hasTool = false;
        for (std::vector<ATool *>::const_iterator it2 = workerToolList.begin(); 
            it2 != workerToolList.end(); it2++)
        {
            if ((*it2)->getType() == *it)
            {
                hasTool = true;
                break;
            }
        }
        if (!hasTool)
        {
            std::cout << RED << "Error: Worker " << workerToCheck->getIdWorker() 
                << " does not have the required tool " << *it << " for Workshop " 
                << this->idWorkshop << RESET << std::endl;
            return (false);
        }
    }
    std::cout << "Worker " << workerToCheck->getIdWorker() 
        << " has all the required tools for Workshop " << this->idWorkshop << std::endl;
    return (true);
}



void Workshop::registerWorker(Worker *newWorker)
{
    // Check if the worker
    if (!newWorker)
    {
        std::cout << RED << "Error: Worker is NULL" << RESET << std::endl;
        return ;
    }

    // Check if the worker is already registered
    if (isWorkerRegistered(newWorker))
        return ;

    // Check if the worker has all the required tools by the workshop
    if (!hasRequiredTools(newWorker))
        return ;

    // Add the worker to the workshop's worker list
    this->workerList.push_back(newWorker);
    std::cout << "Worker " << newWorker->getIdWorker() << " registered in Workshop " 
        << this->idWorkshop << std::endl;
    // Add the workshop to the worker's workshop list
    newWorker->addWorkshop(this);
}

void Workshop::unregisterWorker(Worker *workerToRemove)
{
    std::vector<Worker *>::iterator it = this->workerList.begin();
    while (it != this->workerList.end())
    {
        if (*it == workerToRemove)
        {
            std::cout << "Worker " << workerToRemove->getIdWorker() 
                << " unregistered from Workshop " << this->idWorkshop << std::endl;
            this->workerList.erase(it);
            return;
        }
        it++;
    }
    std::cout << RED << "Error: Worker not found in Workshop" << RESET << std::endl;
}

void Workshop::removeAllWorkers(void)
{
    for (std::vector<Worker *>::iterator it = this->workerList.begin(); 
        it != this->workerList.end(); it++)
    {
        std::cout << "Worker " << (*it)->getIdWorker() << " unregistered from Workshop " 
            << this->idWorkshop << std::endl;
    }
    this->workerList.clear();
}

/**
 * @brief Displays the workers in the workshop.
 * 
 * This function prints the IDs of all the workers in the workshop.
 */
void Workshop::displayWorkers(void) const
{
    std::cout << "Workers in Workshop " << this->idWorkshop << ":" << std::endl;
    for (std::vector<Worker *>::const_iterator it = this->workerList.begin(); 
        it != this->workerList.end(); it++)
    {
        std::cout << "Worker " << (*it)->getIdWorker() << std::endl;
    }
}

/**
 * Executes a work day for the workshop.
 * Prints a message indicating the workshop ID and that a work day is being executed.
 * Calls the `work` function for each worker in the worker list, passing a reference to the workshop.
 */
void Workshop::executeWorkDay(void)
{
    std::cout << "Workshop " << this->idWorkshop << " is executing a work day" << std::endl;
    for (std::vector<Worker *>::iterator it = this->workerList.begin(); 
        it != this->workerList.end(); it++)
    {
        (*it)->work(*this);
    }
}
