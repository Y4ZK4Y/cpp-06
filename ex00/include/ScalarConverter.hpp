/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasamankarimi <yasamankarimi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:12:16 by yasamankari       #+#    #+#             */
/*   Updated: 2025/07/16 20:44:34 by yasamankari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

enum ScalarType {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_PSEUDO,
    TYPE_INVALID
};

class ScalarConverter {
public:
    static void         convert(const std::string& literal);

private:
    // prevents instantiation
    ScalarConverter() = delete;
    ScalarConverter(const ScalarConverter&) = delete;
    ScalarConverter& operator=(const ScalarConverter&) = delete;
    ~ScalarConverter() = delete;

    /* Validation Helpers */
    static bool         isPseudoLiteral(const std::string& str);
    static bool         isConvertibleInt(double val);
    static bool         isConvertibleChar(double val);
    static bool         isPrintableChar(double val);

    /* Output Functions */
    static void         printChar(double value);
    static void         printInt(double value);
    static void         printFloat(double value) ;
    static void         printDouble(double value);

    /* Type Detection */
    static ScalarType   detectType(const std::string& literal);

    /* Conversion Logic */
    static double       convertToDouble(const std::string& literal, ScalarType type);
};


/*
Write a class ScalarConverter that will contain only one static method "convert"
that will take as a parameter a string representation of a C++ literal in its most common
form and output its value in the following series of scalar types:
• char
• int
• float
• double

must not be instantiable by users.

doesn’t need to store anything at all
non-displayable characters shouldn’t be used as
inputs.
*/

/*

the delete keyword is for c++11 or later
tells the compiler to NEVER generate the function*/
