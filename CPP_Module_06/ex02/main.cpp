/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:25:56 by pealexan          #+#    #+#             */
/*   Updated: 2023/11/08 12:45:17 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <unistd.h>

int main(void)
{
	std::srand(std::time(NULL));

	Base *base1 = generate();
	sleep(1);
	Base *base2 = generate();
	sleep(1);
	Base *base3 = generate();

	identify(base1);
	identify(base2);
	identify(base3);

	Base &base11 = *base1;
	Base &base22 = *base2;
	Base &base33 = *base3;

	identify(base11);
	identify(base22);
	identify(base33);

	Base *bad1 = NULL;
	Base bad2;

	identify(bad1);
	identify(bad2);

	delete base1;
	delete base2;
	delete base3;
}