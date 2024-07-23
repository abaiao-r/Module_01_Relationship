/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guest <guest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:49:10 by guest             #+#    #+#             */
/*   Updated: 2024/07/23 11:53:22 by guest            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Worker.hpp"
#include "../includes/colours.hpp"

/**
 * @brief Test function for creating a parameterized Worker object.
 * 
 * This function creates a parameterized Worker object with specific values for 
 * its position and statistic.
 * It then retrieves the position and statistic of the created Worker object and 
 * compares them with the expected values.
 * If the retrieved values match the expected values, the test is considered 
 * passed; otherwise, it is considered failed.
 * 
 * @note This function assumes that the Worker class has been properly 
 * implemented.
 */
void testCreateParameterizedWorker(void)
{
    { 
        std::cout << CYAN << "\n\n------------------------------------\n\n" 
            << RESET << std::endl;
        std::cout << CYAN << "Test: Create parameterized Worker\n\n" << RESET
            << std::endl;
        std::cout << CYAN << "Creating parameterized Worker..." << RESET 
            << std::endl;
        Worker parameterizedWorker(1, 2, 3, 4, 5);
        std::cout << CYAN << "Parameterized Worker created.\n\n" << RESET 
            << std::endl;

        position pos = parameterizedWorker.getPosition();
        statistic stat = parameterizedWorker.getStatistic();

        std::cout << "Position of parameterized Worker: x = " << pos.x 
            << ", y = " << pos.y << ", z = " << pos.z << std::endl;
        std::cout << "Statistic of parameterized Worker: level = " << stat.level 
            << ", exp = " << stat.exp << std::endl;

        if (pos.x == 1 && pos.y == 2 && pos.z == 3 && stat.level == 4
            && stat.exp == 5)
            std::cout << GREEN << "\nTest Passed." << RESET << std::endl;
        else
            std::cout << RED << "\nTest Failed." << RESET << std::endl;
        
        std::cout << CYAN << "\n\n------------------------------------\n\n" 
            << RESET << std::endl;
    }
}


/**
 * @brief Test case for creating a default Worker.
 * 
 * This test case creates a default Worker object and verifies that its position 
 * and statistic
 * values are set correctly.
 * 
 * @param void
 * @return void
 */
void testCreateDefaultWorker(void)
{
    {
        std::cout << CYAN << "\n\n------------------------------------\n\n" 
            << RESET << std::endl;
        std::cout << CYAN << "Test: Create default Worker\n\n" << RESET 
            << std::endl;
        std::cout << CYAN << "Creating default Worker..." << RESET 
            << std::endl;
        Worker defaultWorker;
        std::cout << CYAN << "Default Worker created.\n" << RESET << std::endl;

        defaultWorker.setPosition(1, 2, 3);
        defaultWorker.setStatistic(4, 5);

        position pos = defaultWorker.getPosition();
        statistic stat = defaultWorker.getStatistic();
        

        std::cout << "Position of default Worker: x = " << pos.x 
            << ", y = " << pos.y << ", z = " << pos.z << std::endl;
        std::cout << "Statistic of default Worker: level = " << stat.level 
            << ", exp = " << stat.exp << std::endl;

        if (pos.x == 1 && pos.y == 2 && pos.z == 3 && stat.level == 4 
            && stat.exp == 5)
            std::cout << GREEN << "\nTest Passed." << RESET << std::endl;
        else
            std::cout << RED << "\nTest Failed." << RESET << std::endl;

        std::cout << CYAN << "\n\n------------------------------------\n\n"
            << RESET << std::endl;   
    }
}

int main (void)
{
    std::cout << PURPLE << "Starting Tests...\n\n" << RESET << std::endl;

    testCreateDefaultWorker();
    testCreateParameterizedWorker();

    std::cout << PURPLE << "Tests Finished." << RESET << std::endl;
}