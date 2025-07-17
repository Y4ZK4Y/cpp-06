/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasamankarimi <yasamankarimi@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/16 18:12:12 by yasamankari   #+#    #+#                 */
/*   Updated: 2025/07/17 11:39:17 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cctype>
#include <stdexcept>

/* -------------------------- Validation Helpers -------------------------- */
bool ScalarConverter::isPrintableChar(double value) {
    if (!isConvertibleChar(value))
        return false;
    char c = static_cast<char>(value);
    return std::isprint(c);
}

/* char must be within 0-127 (ASCII range) */
bool ScalarConverter::isConvertibleChar(double value) {
    if (std::isnan(value) || std::isinf(value))
        return false;
    return (value >= 0 && value <= 127);
}

/* can't convert NaN or inf to int - has to be within int range */
bool ScalarConverter::isConvertibleInt(double value) {
    if (std::isnan(value) || std::isinf(value))
        return false;
    int const intMin = std::numeric_limits<int>::min();
    int const intMax = std::numeric_limits<int>::max();
    bool isInIntRange = value >= intMin && value <= intMax;
    return isInIntRange;
}

bool ScalarConverter::isPseudoLiteral(const std::string& str) {
    return (str == "nan" || str == "nanf" || str == "+inf" ||
            str == "+inff" || str == "-inf" || str == "-inff");    
}

/* -------------------------- Output Helpers -------------------------- */
void ScalarConverter::printChar(double value) {
    std::cout << "Char: ";
    if (!isConvertibleChar(value))
        std::cout << "Impossible\n";
    else if (!isPrintableChar(value))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(value) << "'\n";
}

void ScalarConverter::printInt(double value) {
    std::cout << "Int: ";
    if (!isConvertibleInt(value))
        std::cout << "Impossible\n";
    else
        std::cout << static_cast<int>(value) << "\n";
}

void ScalarConverter::printFloat(double value) {
    std::cout << "Float: ";
    std::cout << std::fixed << std::setprecision(1)
              << static_cast<float>(value) << "f\n";
}

void ScalarConverter::printDouble(double value) {
    std::cout << "Double: ";
    std::cout << std::fixed << std::setprecision(1)
              << value << "\n";
}

/* -------------------------- Type Detection -------------------------- */

ScalarType ScalarConverter::detectType(const std::string& literal) {
    if (literal.empty())
        return TYPE_INVALID;

    if (isPseudoLiteral(literal))
        return TYPE_PSEUDO;

    // Single printable non-digit char (like 'a', '*')
    if (literal.size() == 1 && !std::isdigit(literal[0]))
        return TYPE_CHAR;

    // Check if it's a float with 'f' suffix
    if (literal.back() == 'f') {
        std::string core = literal.substr(0, literal.size() - 1);
        try {
            size_t idx;
            std::stof(core, &idx);
            if (idx == core.size())
                return TYPE_FLOAT;
        } catch (...) {
            return TYPE_INVALID;
        }
    }

    // Check if it's a double
    try {
        size_t idx;
        std::stod(literal, &idx);
        if (idx == literal.size())
            return TYPE_DOUBLE;
    } catch (...) {
        return TYPE_INVALID;
    }
    return TYPE_INVALID;
}

/* -------------------------- Conversion Functuons -------------------------- */
double ScalarConverter::convertToDouble(const std::string& literal, ScalarType type) {
    switch (type) {
        case TYPE_CHAR:
            return static_cast<double>(literal[0]);

        case TYPE_PSEUDO:
            if (literal == "nan" || literal == "nanf")
                return std::numeric_limits<double>::quiet_NaN();
            if (literal == "+inf" || literal == "+inff")
                return std::numeric_limits<double>::infinity();
            if (literal == "-inf" || literal == "-inff")
                return -std::numeric_limits<double>::infinity();
            break;

        case TYPE_FLOAT: {
            std::string core = literal.substr(0, literal.size() - 1);
            return static_cast<double>(std::stof(core));
        }

        case TYPE_DOUBLE:
            return std::stod(literal);

        default:
            throw std::invalid_argument("Invalid type");
    }

    throw std::invalid_argument("Unreachable path in convertToDouble()");
}

void ScalarConverter::convert(const std::string& literal) {
    if (literal.empty()) {
        std::cerr << "Invalid input: (empty string)\n";
        return;
    }

    ScalarType type = detectType(literal);
    if (type == TYPE_INVALID) {
        std::cerr << "Invalid input: " << literal << "\n";
        return;
    }

    double value = convertToDouble(literal, type);
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}


/*
<limits>
std::numeric_limits<int>::min();
std::numeric_limits<int>::max();
std::numeric_limits<double>::infinity();
std::numeric_limits<double>::quiet_NaN();


conversions
std::stoi(), std::stof(), std::stod()

exception
std::invalid_argument
std::out_of_range

formatting:
std::setprecision


*/