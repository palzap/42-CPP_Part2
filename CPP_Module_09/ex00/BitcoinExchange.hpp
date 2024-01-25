#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float> btcMap;
		std::string _file;
		
		#pragma region Copy and = Overload Operators
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange& operator=(const BitcoinExchange& obj);
		#pragma endregion

	public:
		#pragma region Orthodox Cannonical Form
		BitcoinExchange();
		BitcoinExchange(std::string file);
		~BitcoinExchange();
		#pragma endregion
		
		#pragma region Auxiliary Functions
		bool	isDigit(const std::string& str);
		bool	isLeapYear(int year);
		bool 	isFloat(const std::string& str);
		bool	checkSeparator(std::string& line, char separator, int number);
		#pragma endregion
		
		#pragma region File Reading
		void	readCSV(void);
		void	readInput(void);
		#pragma endregion

		#pragma region Input Validation
		bool	checkDate(std::string& line);
		bool	checkYear(std::string& year, std::string& date);
		bool	checkMonth(std::string& month);
		bool	checkDay(std::string& year, std::string& month, std::string& day);
		bool	checkValue(std::string& line, std::string& date);
		#pragma endregion
		
		#pragma region Calculation and Output
		void	calculateBTC(std::string& date, std::string& value);
		#pragma endregion
		
		#pragma region Excepetions
		class CantOpenFileException : public std::exception
		{
			public:
				virtual const char *what() const throw(){return "Can't open file!";}
		};
		class FormatException : public std::exception
		{
			public:
				virtual const char *what() const throw(){return "Incorrect format in input file!";}
		};
		#pragma endregion
};

#endif