/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Workshop.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:00:31 by abaiao-r          #+#    #+#             */
/*   Updated: 2024/08/14 21:13:28 by abaiao-r         ###   ########.fr       */
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
        size_t nextId;
    
    public:
        Workshop(void);
        Workshop(const Workshop &src);
        ~Workshop(void);
        Workshop &operator=(const Workshop &rhs);
        
        // Worker
        void registerWorker(Worker *newWorker);
        void unregisterWorker(Worker *workerToRemove);
        void removeAllWorkers(void);
        void displayWorkers(void) const;
        void executeWorkDay(void);
};

#endif

