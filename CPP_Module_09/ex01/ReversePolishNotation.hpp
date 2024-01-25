#ifndef REVERSEPOLISHNOTATION_HPP
#define REVERSEPOLISHNOTATION_HPP

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stack>

class ReversePolishNotation
{
	private:
		std::string _expression;
		std::stack<double> _stack;

		#pragma region Copy and = Overload Operators
		ReversePolishNotation(const ReversePolishNotation& obj);
		ReversePolishNotation& operator=(const ReversePolishNotation& obj);
		#pragma endregion

	public:
		#pragma region Orthodox Cannonical Form
		ReversePolishNotation();
		ReversePolishNotation(std::string input);
		~ReversePolishNotation();
		#pragma endregion

		#pragma region Input Validation
		bool	isValidExpression();
		#pragma endregion

		#pragma region Execution and Output
		void	executeRPN(void);
		#pragma endregion

		#pragma region Exceptions
		class WrongExpressionException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Incorrect expression!";
				}
		};
		#pragma endregion
};

#endif