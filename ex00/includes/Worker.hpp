/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guest <guest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:09:01 by guest             #+#    #+#             */
/*   Updated: 2024/08/02 13:14:43 by guest            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_HPP
# define WORKER_HPP

# include <iostream>
# include <string>
# include <vector>
# include "position.hpp"
# include "statistic.hpp"
# include "colours.hpp"
# include "Shovel.hpp"

class Worker
{
    private:
        position coordonnee;
        statistic stat;
        std::vector<Shovel *> shovelList;
        static size_t nextId;
        const size_t idWorker;
    
    public:
        Worker(void);
        Worker(int x, int y, int z, int level, int exp);
        Worker(const Worker &src);
        ~Worker(void);
        Worker &operator=(const Worker &rhs);
        
        // Setters
        void setPosition(int x, int y, int z);
        void setStatistic(int level, int exp);

        // Getters
        const position &getPosition(void) const;
        const statistic &getStatistic(void) const;
        const size_t &getIdWorker(void) const;
        const std::vector<Shovel *> &getShovelList(void) const;

        // Shovel
        void giveShovel(Shovel *newShovel);
        void takeAwayShovel(Shovel *shovelToRemove);
        void removeAllShovels(void);
        void useShovel(size_t shovelId); // New method to use a shovel by its ID
};

#endif
