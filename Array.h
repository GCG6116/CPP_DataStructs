#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array {
private:
    int size;
    int* array;
    bool* isOccupied; // Tracks which specific slots are in use

public:
    // () zero-initializes both arrays (all bools start as false)
    Array(int size) 
        : size{size}, array{new int[size]()}, isOccupied{new bool[size]()}{}

    // Destructor (clean up both dynamic arrays)
    ~Array() {
        delete[] array;
        delete[] isOccupied;
    }

    // Rule of Three
    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    int getSize() const { return size; }

    int* getArray() const { return array; }

    int getArrayValue(int pos) const { return array[pos]; }

    // 1. Puts the value in the first free spot found
    void setArrayValue(int value) {
        for (int i = 0; i < size; i++) {
            if (!isOccupied[i]) { // Check the tracker 
                array[i] = value;
                isOccupied[i] = true;
                return; // Exit the function immediately once placed
            }
        }
        // Only runs if the loop finishes without finding ANY free spot
        std::cout << "Array is full\n";
    }

    // 2. Puts the value at a specific position and marks it occupied
    void setArrayValue(int pos, int value) {
        if (pos >= 0 && pos < size) {
            array[pos] = value;
            isOccupied[pos] = true;
        } else {
            std::cout << "Index out of bounds\n";
        }
    }

    void printArray() const {
        for (int i = 0; i < size; i++) {
            std::cout << array[i] << '\n';
        }
    }
};

#endif // ARRAY_H
