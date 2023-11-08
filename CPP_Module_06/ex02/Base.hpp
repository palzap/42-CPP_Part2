/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:25:51 by pealexan          #+#    #+#             */
/*   Updated: 2023/11/08 12:39:41 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <ctime>
#include <cstdlib>
#include <iostream>

class Base
{
public:
	virtual ~Base();
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif