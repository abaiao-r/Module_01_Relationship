/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guest <guest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:59:41 by guest             #+#    #+#             */
/*   Updated: 2024/08/02 13:04:45 by guest            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOVEL_HPP
# define SHOVEL_HPP

# include <iostream>
# include "../includes/colours.hpp"

class Shovel
{
    private:
        size_t numberOfUses;
        static size_t nextId;
        const size_t idShovel;
        
    public:
        Shovel(void);
        Shovel(const Shovel &src);
        ~Shovel(void);
        Shovel &operator=(const Shovel &rhs);

        // use is basically a setter for numberOfUses
        void use(void);

        // Getters
        const size_t &getNumberOfUses(void) const;
        const size_t &getIdShovel(void) const;
};

#endif
