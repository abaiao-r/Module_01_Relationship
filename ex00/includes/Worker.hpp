/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:09:01 by guest             #+#    #+#             */
/*   Updated: 2024/08/14 19:11:26 by abaiao-r         ###   ########.fr       */
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
# include "ATool.hpp"

class Worker
{
    private:
        position coordonnee;
        statistic stat;
        std::vector<ATool *> toolList;
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
        const std::vector<ATool *> &getToolList(void) const;

        // Tool
        void giveTool(ATool *newTool);
        void takeAwayTool(ATool *toolToRemove);
        void removeAllTools(void);
        void useTool(size_t toolId); // New method to use a tool by its ID
};

#endif
