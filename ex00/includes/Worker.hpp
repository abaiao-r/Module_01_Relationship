/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guest <guest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:09:01 by guest             #+#    #+#             */
/*   Updated: 2024/07/30 11:24:01 by guest            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_HPP
# define WORKER_HPP

# include <iostream>
# include <string>
# include "position.hpp"
# include "statistic.hpp"
# include "colours.hpp"
# include "Shovel.hpp"

class Worker
{
    private:
        position coordonnee;
        statistic stat;
        Shovel *shovel;
    
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

        // Shovel
        void giveShovel(Shovel *newShovel);
        void useShovel(void);
        void takeShovel(void);
};

#endif
