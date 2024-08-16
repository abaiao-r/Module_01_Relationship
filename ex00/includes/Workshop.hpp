/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Workshop.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:00:31 by abaiao-r          #+#    #+#             */
/*   Updated: 2024/08/16 21:35:31 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

# include <iostream>
# include <string>
# include <vector>
# include "colours.hpp"
# include "Worker.hpp"

class Workshop
{
    private:
        std::vector<Worker *> workerList;
        std::vector<std::string> toolsNeeded;
        static size_t nextId;
        const size_t idWorkshop;
        Workshop(void);

    
    public:
        Workshop(const std::vector<std::string> &toolsNeeded);
        Workshop(const Workshop &src);
        Workshop &operator=(const Workshop &rhs);
        ~Workshop(void);
        
        // getters
        const std::vector<Worker *> &getWorkerList(void) const;
        const std::vector<std::string> &getToolsNeeded(void) const;
        const size_t &getIdWorkshop(void) const;
        
        // Worker
        void registerWorker(Worker *newWorker);
        void unregisterWorker(Worker *workerToRemove);
        void removeAllWorkers(void);
        void displayWorkers(void) const;
        void executeWorkDay(void);

        bool isWorkerRegistered(Worker *workerToCheck) const;
        bool hasRequiredTools(Worker *workerToCheck) const;
};

#endif

