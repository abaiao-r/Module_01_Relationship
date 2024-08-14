/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATool.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:51:01 by abaiao-r          #+#    #+#             */
/*   Updated: 2024/08/14 18:53:48 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ATool.hpp"

size_t ATool::nextId = 1;

/**
 * @brief Default constructor for ATool class.
 * 
 * This constructor initializes the ATool object with default values.
 * It sets the number of uses to 0, assigns a unique id to the tool,
 * and sets the owner to NULL.
 * 
 * @return None.
 */
ATool::ATool(void) : numberOfUses(0), idTool(nextId++), owner(NULL)
{
    //print: what constructor is called, the id of the object, and the number of uses
    std::cout << YELLOW << "ATool default constructor called" << RESET 
        << std::endl;
    printToolInfo(); 
}


/**
 * @brief Parameterized constructor for ATool class.
 * 
 * This constructor initializes the ATool object with the values of the
 * parameter.
 * It sets the number of uses to 0, assigns a unique id to the tool,
 * and sets the owner to NULL.
 * 
 * @param type The type of the tool.
 * 
 * @return None.
 */
ATool::ATool(std::string const &type) : type(type), numberOfUses(0), 
    idTool(nextId++), owner(NULL)
{
    //print: what constructor is called, the id of the object, and the number of uses
    std::cout << YELLOW << "ATool parameterized constructor called" << RESET 
        << std::endl;
    printToolInfo();
}

/**
 * @brief Copy constructor for ATool class.
 * 
 * This constructor initializes the ATool object with the values of another
 * ATool object.
 * 
 * @param src The ATool object to copy.
 * 
 * @return None.
 */
ATool::ATool(ATool const &src) : idTool(nextId++)
{
    *this = src;
    //print: what constructor is called, the id of the object, and the number of uses
    std::cout << YELLOW << "ATool copy constructor called" << RESET 
        << std::endl;
    printToolInfo();
}

/**
 * @brief Destructor for ATool class.
 * 
 * This destructor prints a message indicating that the object is being
 * destroyed.
 * 
 * @return None.
 */
ATool::~ATool(void)
{
    //print: what is being called, the id of the object, and the number of uses
    std::cout << ORANGE << "ATool destructor called" << RESET << std::endl;

    printToolInfo();
}

/**
 * @brief Assignment operator for ATool class.
 * 
 * This operator assigns the values of one ATool object to another.
 * 
 * @param rhs The ATool object to copy.
 * 
 * @return A reference to the ATool object.
 */

ATool &ATool::operator=(ATool const &src)
{
    if (this != &src)
    {
        this->numberOfUses = src.numberOfUses;
    }
    //print: what constructor is called, the id of the object, and the number of uses
    std::cout << YELLOW << "ATool assignation operator called" << RESET 
        << std::endl;
    printToolInfo();
    
    return (*this);
}

/**
 * @brief Get the type of the tool.
 * 
 * This function returns the type of the tool.
 * 
 * @return The type of the tool.
 */
const std::string &ATool::getType(void) const
{
    //print: the type of the tool
    std::cout << YELLOW << "Tool type: " << this->type << RESET << std::endl;
    return (this->type);
}

/**
 * @brief Get the number of uses of the tool.
 * 
 * This function returns the number of uses of the tool.
 * 
 * @return The number of uses of the tool.
 */
const size_t &ATool::getNumberOfUses(void) const
{
    //print: the number of uses of the tool
    std::cout << YELLOW << "Number of uses: " << this->numberOfUses << RESET 
        << std::endl;
    return (this->numberOfUses);
}

/**
 * @brief Get the id of the tool.
 * 
 * This function returns the id of the tool.
 * 
 * @return The id of the tool.
 */
const size_t &ATool::getIdTool(void) const
{
    //print: the id of the tool
    std::cout << YELLOW << "ID: " << this->idTool << RESET << std::endl;
    return (this->idTool);
}

/**
 * @brief Get the owner of the tool.
 * 
 * This function returns the owner of the tool.
 * 
 * @return The owner of the tool.
 */
Worker *ATool::getOwner(void) const
{
    //print: the owner of the tool
    std::cout << YELLOW << "Owner: " << this->owner << RESET << std::endl;
    return (this->owner);
}

/**
 * @brief Print the information of the tool.
 * 
 * This function prints the information of the tool.
 * 
 * @return None.
 */
void ATool::printToolInfo(void) const
{
    //print: the type, id, number of uses, and owner of the tool
    std::cout << "\n------------Tool info------------" << std::endl;
    getType();
    getIdTool();
    getNumberOfUses();
    getOwner();
    std::cout << "---------------------------------\n" << std::endl;
}

/**
 * @brief Set the owner of the tool.
 * 
 * This function sets the owner of the tool.
 * 
 * @param owner The owner of the tool.
 * 
 * @return None.
 */
void ATool::setOwner(Worker *newOwner)
{
    this->owner = newOwner;
    //print: the owner of the tool
    std::cout << YELLOW << "Owner set to: " << this->owner << RESET 
        << std::endl;
    printToolInfo();
}


