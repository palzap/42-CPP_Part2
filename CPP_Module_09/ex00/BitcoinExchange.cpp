
#include "BitcoinExchange.hpp"

#pragma region Orthodox Cannonical Form
BitcoinExchange::BitcoinExchange() : _file("Default")
{
	readCSV();
	readInput();
}

BitcoinExchange::BitcoinExchange(std::string file) : _file(file)
{
	readCSV();
	readInput();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
	(void)obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
	(void)obj;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}
#pragma endregion

#pragma region Auxiliary Functions
bool BitcoinExchange::isDigit(const std::string& str)
{
  for (size_t i = 0; i < str.length(); ++i)
  	if (!isdigit(str[i]))
      return false;
  return true;
}

bool BitcoinExchange::isLeapYear(int year)
{
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	else
  	return false;
}

bool BitcoinExchange::isFloat(const std::string& str) {
    int dots = 0;

    bool dotAtStartOrEnd = (str.length() > 0 && str[0] == '.') || (str.length() > 1 && str[str.length() - 1] == '.');

    for (size_t i = 0; i < str.length(); ++i) {
        if (std::isdigit(str[i])) {
        } else if (str[i] == '.') {
            dots++;
        } else {
            return false;
        }
    }
	if (dots > 1 || dotAtStartOrEnd)
		return false;

    return true;
}

bool BitcoinExchange::checkSeparator(std::string& line, char separator, int number)
{
	int sepNumber = 0;
	for (size_t i = 0; i < line.length(); i++)
		if (line[i] == separator)
			sepNumber++;
	if (sepNumber != number)
		return false;
	return true;
}
#pragma endregion

#pragma region File Reading
void BitcoinExchange::readCSV(void)
{
	std::ifstream inputFile("data.csv");
	if (!inputFile.is_open())
	throw CantOpenFileException();

	std::string line;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		std::istringstream iss(line);
		
		std::string date;
		float value;
		
		std::getline(iss, date, ',');
		iss >> value;
		btcMap[date] = value;
	}

	inputFile.close();
}

void	BitcoinExchange::readInput(void)
{
	std::ifstream inputFile(this->_file.c_str());
	if(!inputFile.is_open())
		throw CantOpenFileException();
	std::string line;
	if (!std::getline(inputFile, line))
		return ;
	if(line != "date | value")
		throw FormatException();
	while(std::getline(inputFile, line))
		if (!checkSeparator(line, '|', 1) || !checkDate(line))
			std::cout << "Bad input => " << line << std::endl;
}
#pragma endregion

#pragma region Input Validation
bool BitcoinExchange::checkDate(std::string& line)
{
	size_t pos = line.find('|');
	std::string date = line.substr(0, pos);

	date.erase(std::remove_if(date.begin(), date.end(), ::isspace), date.end());

	if (!checkSeparator(date, '-', 2))
		throw FormatException();

	std::istringstream dateStream(date);
	std::string year, month, day;

	std::getline(dateStream, year, '-');
	std::getline(dateStream, month, '-');
	std::getline(dateStream, day);

	if (year.length() != 4 || month.length() != 2 || day.length() != 2)
		return false;

	if(!checkYear(year, date)|| !checkMonth(month) || !checkDay(year, month, day))
		return false;

	if (!checkValue(line, date))
		return false;
	return true;
}

bool BitcoinExchange::checkYear(std::string& year, std::string& date)
{
	if (!isDigit(year))
		return false;
	if (atoi(year.c_str()) < 2009 || date == "2009-01-01")
		return false;
	return true;
}

bool	BitcoinExchange::checkMonth(std::string& month)
{
	if (!isDigit(month))
		return false;
	if (atoi(month.c_str()) < 1 || atoi(month.c_str()) > 12)
		return false;
	return true;
}

bool	BitcoinExchange::checkDay(std::string& year, std::string& month, std::string& day)
{
	if (!isDigit(day))
		return false;

	switch (std::atoi(month.c_str())) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return (day <= "31");
		case 4: case 6: case 9: case 11:
			return (day <= "30");
		case 2:
			if (isLeapYear(std::atoi(year.c_str()))) {
				return (std::atoi(day.c_str()) <= 29);
			} else {
				return (std::atoi(day.c_str()) <= 28);
			}
		default:
			return false;
	}
	return true;
}

bool	BitcoinExchange::checkValue(std::string& line, std::string& date)
{
	size_t pos = line.find('|');

	std::string value = line.substr(pos + 1);

	value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());

	if (!isFloat(value))
		return false;

	if(value.length() <= 0 || atof(value.c_str()) < 0.0 || atof(value.c_str()) > 1000.0)
		return false;

	calculateBTC(date, value);
	return true;
}
#pragma endregion

#pragma region Calculation and Output
void	BitcoinExchange::calculateBTC(std::string& date, std::string& value)
{
	float valueMult;

	std::map<std::string, float>::iterator it;
	for (it = btcMap.begin(); it != btcMap.end(); ++it)
	{
		if (date < it->first)
		{
			--it;
			valueMult = it->second;
			break;
		}
	}
	if(it == btcMap.end())
	{
		--it;
		valueMult = it->second;
	}
	float finalValue = atof(value.c_str()) * valueMult;
	std::cout << date << " => " << value << " = " << std::setprecision(7) << finalValue << std::endl;
}
#pragma endregion
