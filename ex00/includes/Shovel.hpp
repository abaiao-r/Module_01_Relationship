/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:59:41 by guest             #+#    #+#             */
/*   Updated: 2024/08/09 18:41:02 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOVEL_HPP
# define SHOVEL_HPP

# include <iostream>
# include "colours.hpp"


class Worker;

class Shovel
{
    private:
        size_t numberOfUses;
        static size_t nextId;
        const size_t idShovel;
        Worker *owner; // Pointer to the worker that owns the shovel
        
    public:
        Shovel(void);
        Shovel(const Shovel &src);
        ~Shovel(void);
        Shovel &operator=(const Shovel &rhs);


        // Getters
        const size_t &getNumberOfUses(void) const;
        const size_t &getIdShovel(void) const;
        Worker *getOwner(void) const;

        // use is basically a setter for numberOfUses
        void use(void);
        // Setters
        void setOwner(Worker *owner);
};

#endif
