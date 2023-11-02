/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:14:45 by pealexan          #+#    #+#             */
/*   Updated: 2023/11/02 11:00:08 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string name);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
	~PresidentialPardonForm();

	virtual void executeForm() const;

private:
	std::string _target;
};

#endif