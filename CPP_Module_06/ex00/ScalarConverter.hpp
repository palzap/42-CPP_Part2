/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:11:22 by pealexan          #+#    #+#             */
/*   Updated: 2023/11/08 12:29:25 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <cstdlib>

typedef enum
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO
} t_type;

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &src);
    ScalarConverter &operator=(const ScalarConverter &src);
    ~ScalarConverter();

public:
    static bool isChar(const std::string &input);
    static bool isInt(const std::string &input);
    static bool isFloat(const std::string &input);
    static bool isDouble(const std::string &input);
    static bool isPseudo(const std::string &input);

    static void printInput(long double num, const std::string &input);
    static void printChar(char c, const std::string &input);
    static void printInt(int i, const std::string &input);
    static void printFloat(float f, const std::string &input);
    static void printDouble(double d, const std::string &input);
    static void printPseudo(const std::string &input);

    static bool check_overflow(const std::string &str, t_type type);

    static void convert(const std::string &input);
};

#endif