/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATool.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:46:59 by abaiao-r          #+#    #+#             */
/*   Updated: 2024/08/14 19:31:39 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOL_HPP
# define TOOL_HPP

# include <iostream>
# include <string>
# include "colours.hpp"

class Worker;

class ATool
{
    protected:
        std::string type;
        size_t numberOfUses;
        static size_t nextId;
        const size_t idTool;
        Worker *owner; // Pointer to the worker that owns the tool

    public:
        ATool(void);
        ATool(std::string const &type);
        ATool(ATool const &src);
        ATool &operator=(ATool const &src);
        virtual ~ATool(void);

        // Getters
        const std::string &getType(void) const;
        const size_t &getNumberOfUses(void) const;
        const size_t &getIdTool(void) const;
        Worker *getOwner(void) const;
        void printToolInfo(void) const;

        // Setters
        void setOwner(Worker *newOwner);
        virtual void use(void) = 0;

};

#endif
