/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:59:41 by guest             #+#    #+#             */
/*   Updated: 2024/08/14 20:04:29 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOVEL_HPP
# define SHOVEL_HPP

# include <iostream>
# include "ATool.hpp"
# include "colours.hpp"


class Shovel : public ATool
{       
    public:
        Shovel(void);
        Shovel(const Shovel &src);
        Shovel &operator=(const Shovel &rhs);
        ~Shovel(void);

        // use is basically a setter for numberOfUses
        void use(void);
};

#endif
