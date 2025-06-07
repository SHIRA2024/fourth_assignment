// shiraba01@gmail.com

#include <iostream>
#include "MyContainer.hpp"
#include "AscendingOrderIterator.hpp"
#include "DescendingOrderIterator.hpp"
#include "OrderIterator.hpp"
#include "ReverseOrderIterator.hpp"
#include "MiddleOutOrderIterator.hpp"
#include "SideCrossOrderIterator.hpp"

using namespace assignment4;

int main() {
    MyContainer<int> container;

    // Add elements
    container.add(5);
    container.add(2);
    container.add(9);
    container.add(1);
    container.add(7);

    std::cout << "Original container: " << container << "\n\n";

    // Ascending Order
    std::cout << "Ascending Order: ";
    for (auto it = AscendingOrderIterator<int>::begin(container); it != AscendingOrderIterator<int>::end(container); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Descending Order
    std::cout << "Descending Order: ";
    for (auto it = DescendingOrderIterator<int>::begin(container); it != DescendingOrderIterator<int>::end(container); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Order of Insertion
    std::cout << "Insertion Order: ";
    for (auto it = OrderIterator<int>::begin(container); it != OrderIterator<int>::end(container); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Reverse Order of Insertion
    std::cout << "Reverse Order: ";
    for (auto it = ReverseOrderIterator<int>::begin(container); it != ReverseOrderIterator<int>::end(container); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Middle-Out Order
    std::cout << "Middle-Out Order: ";
    for (auto it = MiddleOutOrderIterator<int>::begin(container); it != MiddleOutOrderIterator<int>::end(container); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Side-Cross Order
    std::cout << "Side-Cross Order: ";
    for (auto it = SideCrossOrderIterator<int>::begin(container); it != SideCrossOrderIterator<int>::end(container); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Remove a value and display container
    try {
        container.remove(2);
        std::cout << "\nAfter removing 2: " << container << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
