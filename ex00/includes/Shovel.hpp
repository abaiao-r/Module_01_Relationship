/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guest <guest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:59:41 by guest             #+#    #+#             */
/*   Updated: 2024/07/23 12:04:26 by guest            ###   ########.fr       */
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
        
    public:
        Shovel(void);
        Shovel(const Shovel &src);
        ~Shovel(void);
        Shovel &operator=(const Shovel &rhs);

        void use(void);
        const size_t &getNumberOfUses(void) const;
};

#endif
