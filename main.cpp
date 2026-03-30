#include <iostream>
#include <vector>
#include "vectorops.h"

int main()
{
    std::vector<int> numbers = {9, 3, 12, 1, 7, 15, 4};

    std::cout << "Original vector: ";
    vectorops::display(numbers);

    vectorops::sortVector(numbers, true);
    std::cout << "Sorted ascending: ";
    vectorops::display(numbers);

    vectorops::sortVector(numbers, false);
    std::cout << "Sorted descending: ";
    vectorops::display(numbers);

    // vectorops::addToEach(numbers, 5);
    // std::cout << "After adding 5 to each element: ";
    // vectorops::display(numbers);

    // std::cout << "Count greater than 10: "
    //           << vectorops::countGreaterThan(numbers, 10)
    //           << std::endl;

    // if (vectorops::saveToFile(numbers, "numbers.txt"))
    // {
    //     std::cout << "Vector saved to numbers.txt" << std::endl;
    // }

    // std::vector<int> loaded = vectorops::loadFromFile("numbers.txt");
    // std::cout << "Loaded vector: ";
    // vectorops::display(loaded);

    return 0;
}
