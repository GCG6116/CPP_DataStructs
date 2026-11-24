#include <iostream>
#include <cassert>
#include "LinkedList.h"

int main() {
    // Test 1:.Adding to an initially empty list (tests the head == nullptr case)
    LinkedList list;
    list.Add(10);
    assert(list.get(0) == 10);
    std::cout << "Test 1 passed:.Added first element." << std::endl;

    // Test 2:.Adding a second element (tests transitioning from 1 node to 2)
    list.Add(20);
    assert(list.get(0) == 10);
    assert(list.get(1) == 20);
    std::cout << "Test 2 passed:.Added second element." << std::endl;

    // Test 3:.Adding multiple elements (tests the while loop traversal)
    list.Add(30);
    list.Add(40);
    assert(list.get(2) == 30);
    assert(list.get(3) == 40);
    std::cout << "Test 3 passed:.Added multiple elements." << std::endl;

    // Test 4: Negative numbers and zero (ensures 0 isn't confused with nullptr)
    list.Add(0);
    list.Add(-99);
    assert(list.get(4) == 0);
    assert(list.get(5) == -99);
    std::cout << "Test 4 passed: Zero and negative values handled." << std::endl;

    // Test 5: Independent list instances (ensures no shared/global state bugs)
    LinkedList secondList;
    secondList.Add(500);
    assert(secondList.get(0) == 500);
    assert(list.get(0) == 10); // Original list should remain untouched
    std::cout << "Test 5 passed: Separate list instances are independent." << std::endl;

    // Visual check
    std::cout << "\nFinal list contents: ";
    list.print(); // Expected: 10 -> 20 -> 30 -> 40 -> 0 -> -99 -> nullptr

    std::cout << "\nAll tests passed!" << std::endl;
    return 0;
}