#include "Array.h"

int main() {
    Array arr(3);
    arr.setArrayValue(1, 10); // Sets index 1 to 10 (index 0 is still free)
    arr.setArrayValue(5);     // Finds index 0 is free, puts 5 there
    arr.setArrayValue(20);    // Skips 0 and 1, puts 20 in index 2
    arr.setArrayValue(99);    // Prints: "arr is full"

    arr.printArray();         // Prints: 5, 10, 20
    return 0;
}