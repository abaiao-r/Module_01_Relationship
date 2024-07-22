/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guest <guest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:09:01 by guest             #+#    #+#             */
/*   Updated: 2024/07/22 13:11:09 by guest            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_HPP
# define WORKER_HPP

# include <iostream>
# include <string>
# include "position.hpp"
# include "statistic.hpp"

class Worker
{
    private:
        position coordonnee;
        statistic stat;
    
    public:
        Worker();
        Worker(const Worker &src);
        ~Worker();
        Worker &operator=(const Worker &rhs);

        
}