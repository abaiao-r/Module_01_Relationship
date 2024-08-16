/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:09:01 by guest             #+#    #+#             */
/*   Updated: 2024/08/16 21:57:57 by abaiao-r         ###   ########.fr       */
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
# include "Workshop.hpp"

class Workshop; // Forward declaration

class Worker
{
    private:
        position coordonnee;
        statistic stat;
        std::vector<ATool *> toolList;
        static size_t nextId;
        const size_t idWorker;
        std::vector<Workshop *> workshopList;
    
    public:
        Worker(void);
        Worker(int x, int y, int z, int level, int exp);
        Worker(const Worker &src);
        ~Worker(void);
        Worker &operator=(const Worker &rhs);
        
        // Setters
        void setPosition(int x, int y, int z);
        void setStatistic(int level, int exp);
        void addWorkshop(Workshop *workshop);
        void removeWorkshop(Workshop *workshop);

        // Getters
        const position &getPosition(void) const;
        const statistic &getStatistic(void) const;
        const size_t &getIdWorker(void) const;
        const std::vector<ATool *> &getToolList(void) const;
        const std::vector<Workshop *> &getWorkshopList(void) const;
    

        void work(Workshop &workshop);
        void displayWorkshops(void) const;

        // Tool
        void giveTool(ATool *newTool);
        void takeAwayTool(ATool *toolToRemove);
        void removeAllTools(void);
        void useTool(size_t toolId); // New method to use a tool by its ID
        template<typename ToolType>
        ToolType* GetTool(void) const;

};

#endif
