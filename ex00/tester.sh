#!/bin/bash

# Path to your compiled converter
CONVERTER=./convert

# List of test cases
test_cases=(
    # Character tests
    "a"
    "Z"
    "7"
    "*"
    "@"
    # Integer tests
    "0"
    "42"
    "-42"
    "2147483647"
    "-2147483648"
    "2147483648"
    "-2147483649"
    # Float tests
    "0.0f"
    "42.5f"
    "-3.14f"
    "1e10f"
    "nanf"
    "+inff"
    "-inff"
    # Double tests
    "0.0"
    "42.5"
    "-3.14159"
    "1e100"
    "nan"
    "+inf"
    "-inf"
    # Invalid input
    "abc"
    "4.2.1"
    "4.2ff"
    "'a'"
    ""
    "   "
    "--42"
    "3.14.15"
    # Very large/small
    "1e20"
    "-1e20"
    "1e-324"
)

# Function to run a single test case
run_test() {
    local input="$1"
    echo "=============================="
    echo "TEST INPUT: \"$input\""
    echo "------------------------------"
    $CONVERTER "$input"
    echo "=============================="
    echo
}

# Make sure the binary exists
if [ ! -x "$CONVERTER" ]; then
    echo "Error: $CONVERTER not found or not executable"
    exit 1
fi

# Run all test cases
for test_case in "${test_cases[@]}"; do
    run_test "$test_case"
done
