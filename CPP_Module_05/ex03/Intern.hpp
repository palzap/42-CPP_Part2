/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:29:34 by pealexan          #+#    #+#             */
/*   Updated: 2023/11/02 14:46:32 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &src);
        Intern& operator=(const Intern& src);
        ~Intern();
        
        AForm *makeForm(const std::string& name, const std::string& target);

        AForm *makeShrubberyCreation(const std::string& target);
        AForm *makeRobotomyRequest(const std::string& target);
        AForm *makePresidentialPardon(const std::string& target);
};

#endif