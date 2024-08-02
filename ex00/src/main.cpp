/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guest <guest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:49:10 by guest             #+#    #+#             */
/*   Updated: 2024/08/02 13:31:18 by guest            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Worker.hpp"
#include "../includes/Shovel.hpp"
#include "../includes/colours.hpp"

void testShovelAggregation(void)
{
    {
        std::cout << CYAN << "\n\n------------------------------------\n\n" 
            << RESET << std::endl;
        std::cout << CYAN << "Testing Shovel assignment...\n\n" << RESET 
            << std::endl;

        std::cout << CYAN << "Test 1: Assigning and using the shovel with Worker 1\n" << RESET << std::endl;
        Worker worker1;
        Worker worker2;
        Shovel shovel1;

        std::cout << "Worker 1 giving shovel to itself." << std::endl;
        worker1.giveShovel(&shovel1);
        
        std::cout << "Worker 1 using the shovel." << std::endl;
        worker1.useShovel(shovel1.getIdShovel());
        
        std::cout << "Worker 1 using the shovel again." << std::endl;
        worker1.useShovel(shovel1.getIdShovel());

        std::cout << CYAN << "Test 2: Reassigning the shovel to Worker 2 and using it\n" << RESET << std::endl;
        std::cout << "Worker 2 giving shovel to itself. This should remove the shovel from Worker 1." << std::endl;
        worker2.giveShovel(&shovel1);
        
        std::cout << "Worker 1 trying to use the shovel." << std::endl;
        worker1.useShovel(shovel1.getIdShovel()); // Should show worker1 does not have the shovel
        
        std::cout << "Worker 2 using the shovel." << std::endl;
        worker2.useShovel(shovel1.getIdShovel());

        std::cout << CYAN << "Test 3: Worker 2 takes the shovel away\n" << RESET << std::endl;
        std::cout << "Worker 2 taking the shovel away." << std::endl;
        worker2.takeAwayShovel(&shovel1);
        
        std::cout << "Worker 2 trying to use the shovel." << std::endl;
        worker2.useShovel(shovel1.getIdShovel());// Should show worker2 does not have the shovel

        std::cout << "Shovel total uses: " << shovel1.getNumberOfUses() << std::endl;
        if (shovel1.getNumberOfUses() == 4) {
            std::cout << "Test Shovel Assignment: Passed" << std::endl;
        } else {
            std::cout << "Test Shovel Assignment: Failed" << std::endl;
        }

        std::cout << CYAN << "Test 4: Ensure the shovel is not destroyed when Worker is destroyed\n" << RESET << std::endl;
        {
            Worker tempWorker;
            std::cout << "Temporary Worker giving shovel to itself." << std::endl;
            tempWorker.giveShovel(&shovel1);
            
            std::cout << "Temporary Worker using the shovel." << std::endl;
            tempWorker.useShovel(shovel1.getIdShovel());
        } // tempWorker goes out of scope here and should be destroyed

        std::cout << "Shovel total uses after temporary Worker destruction: " << shovel1.getNumberOfUses() << std::endl;
        if (shovel1.getNumberOfUses() == 5) {
            std::cout << "Test Shovel Assignment 2: Passed" << std::endl;
        } else {
            std::cout << "Test Shovel Assignment 2: Failed" << std::endl;
        }

        std::cout << CYAN << "\n\n------------------------------------\n\n" << RESET << std::endl;
    }
}

/**
 * @brief Test function for the Shovel class when used alone.
 * 
 * This function tests the functionality of the Shovel class when used alone.
 * It creates a Shovel object, uses it multiple times, and checks the number of uses.
 * It also tests the copy constructor by creating a copy of the Shovel object and using it.
 * 
 * @return void
 */
void testShovelAlone(void)
{
    {
        std::cout << CYAN << "\n\n------------------------------------\n\n" 
            << RESET << std::endl;
        std::cout << CYAN << "Testing Shovel alone...\n" << RESET << std::endl;
        
        std::cout << "\nCreating Shovel..." << std::endl;
        
        Shovel shovel;
        
        std::cout << "\nUsing Shovel..." << std::endl;
        shovel.use();
        shovel.use();
        if (shovel.getNumberOfUses() == 2)
        {
            std::cout << GREEN << "Test Shovel Alone: Passed" << RESET 
                << std::endl;
        }
        else 
        {
            std::cout << RED << "Test Shovel Alone: Failed" << RESET 
                << std::endl;
        }

        std::cout << "\nCreate a new shovel" << std::endl;
        Shovel shovel2;
        shovel2.use();
        shovel2.use();
        shovel2.use();
        
        if (shovel2.getNumberOfUses() == 3)
        {
            std::cout << GREEN << "Test Shovel Alone 2: Passed" << RESET 
                << std::endl;
        }
        else 
        {
            std::cout << RED << "Test Shovel Alone 2: Failed" << RESET 
                << std::endl;
        }

        
        std::cout << "\nCreating Shovel copy..." << std::endl;
        Shovel shovelCopy(shovel);
        
        std::cout << "\nUsing Shovel copy..." << std::endl;
        shovelCopy.use();

        if (shovelCopy.getNumberOfUses() == 3)
        {
            std::cout << GREEN << "Test Shovel Copy: Passed" << RESET 
                << std::endl;
        }
        else 
        {
            std::cout << RED << "Test Shovel Copy: Failed" << RESET 
                << std::endl;
        }

        std::cout << "\nUsing first Shovel..." << std::endl;
        shovel.use();
        if (shovel.getNumberOfUses() == 3)
        {
            std::cout << GREEN << "Test Shovel Copy 2: Passed" << RESET 
                << std::endl;
        }
        else 
        {
            std::cout << RED << "Test Shovel Copy 2: Failed" << RESET 
                << std::endl;
        }
    }
}

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
 * and statistic values are set correctly.
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

    // testCreateDefaultWorker();
    // testCreateParameterizedWorker();
    //testShovelAlone();
    testShovelAggregation();

    std::cout << PURPLE << "Tests Finished." << RESET << std::endl;
}