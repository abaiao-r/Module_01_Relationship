/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hammer.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 20:03:03 by abaiao-r          #+#    #+#             */
/*   Updated: 2024/08/14 20:04:47 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HAMMER_HPP
# define HAMMER_HPP

# include <iostream>
# include "ATool.hpp"
# include "colours.hpp"

class Hammer : public ATool
{       
    public:
        Hammer(void);
        Hammer(const Hammer &src);
        Hammer &operator=(const Hammer &rhs);
        ~Hammer(void);

        // use is basically a setter for numberOfUses
        void use(void);
};

#endif
