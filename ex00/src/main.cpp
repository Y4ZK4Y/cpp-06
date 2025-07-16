/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasamankarimi <yasamankarimi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:11:16 by yasamankari       #+#    #+#             */
/*   Updated: 2025/07/16 20:45:02 by yasamankari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "no\n";
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}


/*
Learning Objectives:
- scalar types
- casting
- string parsing stoi stof stod
- static methods in classes
- non-instantiable classes
- IO formatting

*/

/*
scalar types
the primitive types in c++ that hold a single value
char - int  - float - double
they're atomic; contain only one value

char (1 byte) -128 to 128
int (4 bytes) - −2,147,483,648 to 2,147,483,647
float (4 bytes)
double (8 bytes)
*/

/*
c++ will automatically do implicit conversion between these types
issue:
    large double -> int : might overflow
    nan -> int : not possible
    non printable chars not possible
*/

/*
char -> int, float. double : fine -  non-printable chars (like ASCII 7 or 0) can't be shown as characters.
int -> char, float, double : fine - int to char might be out of range and show garbage 0-127
float, double -> int, char : value might be out of range for int and char - decimal parts get truncated(not rounded)
float -> double :fine
double -> float : may loose precision - do using explicit cast
nan, +inf, -inf to int or char : not possible
*/

/*
casting operators:
static_cast
dynamic_cast
const_Cast
reinterpret_cast
*/


/*
non-instantiable classes
cant using new myclass or mycalss obj
only has static members
you want the class to act like a namespace or utility
don't want state or objects, only want to group functionality

make all constructors private
or delete them (in c++11 or later)

ScalarConverter() = delete;
ScalarConverter(const ScalarConverter&) = delete;
ScalarConverter& operator=(const ScalarConverter&) = delete;

alternative is to make a namespace

namespace ScalarConverter {
    void convert(const std::string& literal);
}

*/

