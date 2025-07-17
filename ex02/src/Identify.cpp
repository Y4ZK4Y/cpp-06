/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Identify.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 14:02:28 by ykarimi       #+#    #+#                 */
/*   Updated: 2025/07/17 14:16:58 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base * generate(void) {
    int rando = std::rand() % 3;
    switch (rando) {
        case 0: std::cout << "Gen function, A:\n";
            return new A;
        case 1: std::cout << "Gen function, B:\n";
            return new B;
        case 2: std::cout << "Gen function, C:\n";
            return new C;
    }
    return nullptr;
}

void identify(Base* p) {
    if (A* a = dynamic_cast<A*>(p))
        std::cout << "Type: A\n";
    else if (B* b = dynamic_cast<B*>(p))
        std::cout << "Type: B\n";
    else if (C* c = dynamic_cast<C*>(p))
        std::cout << "Type: C\n";
    else
        std::cout << "Type: Unknown\n";
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type: A\n";
    } catch (...) {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "Type: B\n";
        } catch (...) {
            try {
                (void)dynamic_cast<C&>(p);
                std::cout << "Type: C\n";
            } catch (...) {
                std::cout << "Type: Unknown\n";
            }
        }
    }
}
