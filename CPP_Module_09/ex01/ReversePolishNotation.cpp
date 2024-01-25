/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReversePolishNotation.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:40:01 by pealexan          #+#    #+#             */
/*   Updated: 2024/01/25 15:23:37 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReversePolishNotation.hpp"

#pragma region Orthodox Cannonical Form
ReversePolishNotation::ReversePolishNotation() : _expression("Default")
{
	executeRPN();
}

ReversePolishNotation::ReversePolishNotation(std::string input) : _expression(input)
{
	if(this->isValidExpression() == false)
		throw WrongExpressionException();
	executeRPN();
}

ReversePolishNotation::ReversePolishNotation(const ReversePolishNotation& obj)
{
	(void)obj;
}

ReversePolishNotation& ReversePolishNotation::operator=(const ReversePolishNotation& obj)
{
	(void)obj;
	return (*this);
}

ReversePolishNotation::~ReversePolishNotation(){}
#pragma endregion

#pragma region Input Validation
bool ReversePolishNotation::isValidExpression()
{
	std::istringstream iss(_expression);
	std::string index;
	while (iss >> index)
	{
	if (!((index.size() == 1 && isdigit(index[0])) || (index.size() == 1 && std::string("+-*/").find(index[0]) != std::string::npos)))
		return false;
	}
	return true;
}
#pragma endregion

#pragma region Execution and Output
void ReversePolishNotation::executeRPN(void)
{
	std::istringstream iss(_expression);
	std::string index;

	while(iss >> index)
	{
		if(isdigit(index[0]))
			_stack.push(std::atof(index.c_str()));
		else
		{
			if(_stack.empty())
				throw WrongExpressionException();
			double value2 = _stack.top();
			_stack.pop();
			if(_stack.empty())
				throw WrongExpressionException();
			double value1 = _stack.top();
			_stack.pop();
			if(index == "+")
				_stack.push(value1 + value2);
			else if(index == "-")
				_stack.push(value1 - value2);
			else if(index == "*")
				_stack.push(value1 * value2);
			else if(index == "/")
				_stack.push(value1 / value2);
			else
				throw WrongExpressionException();
		}
	}
	if (!_stack.empty())
		std::cout << _stack.top() << std::endl;
}
#pragma endregion