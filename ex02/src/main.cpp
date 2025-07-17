/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 13:46:57 by ykarimi       #+#    #+#                 */
/*   Updated: 2025/07/17 14:21:21 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Identify.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Base* obj = generate();

    identify(obj);     // pointer version
    identify(*obj);    // reference version

    delete obj;
    return 0;
}


/*
Learning objectives:

    - dynamic cast
    -typeid
    - rand()
    - std::bad_cast
*/