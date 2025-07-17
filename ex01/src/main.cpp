/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 11:43:06 by ykarimi       #+#    #+#                 */
/*   Updated: 2025/07/17 12:16:05 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
    Data original;
    original.id = 42;
    original.info = "Example";

    std::cout << "Original pointer: " << &original << "\n";

    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "Serialized (uintptr_t): " << raw << "\n";

    Data* restored = Serializer::deserialize(raw);
    std::cout << "Restored pointer: " << restored << "\n";

    std::cout << "Restored id: " << restored->id << "\n";
    std::cout << "Restored info: " << restored->info << "\n";

    if (restored == &original) {
        std::cout << "Deserialization successful!\n";
    } else {
        std::cout << "Deserialization failed.\n";
    }

    return 0;
}


/*
Learning Objectives:
- Serialization
- uintptr_t
*/


/*
Serialization:
process of converting data into a format that can be stored, and later reconstructed(deserialized) back into original format
examples:
    like seriliazing data into JSON or something to send it over the network.
    
    some data :
    struct User {
    std::string name;
    int age;
    };
    serialized into:
    { "name": "Alice", "age": 30 }
    or into a bunary buffer like:
    | 0x05 | A | l | i | c | e | 0x1E |


this exercise ois about: "to serialize a pointer" to an integer representation
ptr => int
int => ptr

use cases:
    - When you want to pass a pointer through an API that only takes integers
    (e.g., storing it in an opaque ID
    - When you want to "freeze" and "thaw" memory safely in lower-level systems

serialize() converts a Data* (pointer to struct) into a uintptr_t
uintptr_t Serializer::serialize(Data* ptr);

    - takes a pointer to a Data object - converts it into an integer type that
    is guaranteed to be big enough to hold a pointer
    - returns that integer

deserialize) does it in reverse
Data* Serializer::deserialize(uintptr_t raw);

*/


/*
uintptr_t
    - an unsigned integer type that can store a pointer without loss
    - defined in <cstdint>
    - to safely cast between pointers and integers (across platforms)

why not size_t or unsigned long?
nly guaranteed type for round-trip pointer → integer → pointer conversion.

*/