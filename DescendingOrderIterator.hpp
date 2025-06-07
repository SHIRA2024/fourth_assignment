// shiraba01@gmail.com
#pragma once
#include <vector>
#include <algorithm>
#include "MyContainer.hpp"

namespace assignment4 {

template <typename T = int>
class DescendingOrderIterator {
private:
    const MyContainer<T>& container;
    std::vector<size_t> sortedIndices;
    size_t currentIndex;

public:
    /*
     Constructor:
     - Initializes the iterator with a reference to a MyContainer<T>.
     - Builds a vector of indices representing the positions of elements in descending order.
     - Uses std::sort to sort the indices based on the values in the container, from largest to smallest.
    */
    DescendingOrderIterator(const MyContainer<T>& cont) : container(cont), currentIndex(0) {
        const auto& data = container.getData();
        sortedIndices.resize(data.size());

        for (size_t i = 0; i < data.size(); ++i) {
            sortedIndices[i] = i;
        }

        std::sort(sortedIndices.begin(), sortedIndices.end(),
                  [&data](size_t a, size_t b) {
                      return data[a] > data[b]; 
                  });
    }

    /*
     Dereference operator (*):
     - Returns a reference to the current value the iterator points to in descending order.
    */
    const T& operator*() const {
        return container.getData()[sortedIndices[currentIndex]];
    }

    /*
     Pre-increment operator (++):
     - Advances the iterator to the next element in the descending sequence.
     - Returns a reference to the updated iterator.
    */
    DescendingOrderIterator& operator++() {
        ++currentIndex;
        return *this;
    }

    /*
     Inequality operator (!=):
     - Compares two iterators based on their current position.
     - Returns true if the positions differ.
     - Typically used to check for end of iteration.
    */
    bool operator!=(const DescendingOrderIterator& other) const {
        return currentIndex != other.currentIndex;
    }

    /*
     Static begin() method:
     - Returns a DescendingOrderIterator pointing to the first element (largest).
     - Used to initiate a for loop over the container in descending order.
    */
    static DescendingOrderIterator begin(const MyContainer<T>& cont) {
        return DescendingOrderIterator(cont);
    }

    /*
     Static end() method:
     - Returns a DescendingOrderIterator pointing past the last element.
     - Used to signal the end of iteration.
    */
    static DescendingOrderIterator end(const MyContainer<T>& cont) {
        DescendingOrderIterator it(cont);
        it.currentIndex = it.sortedIndices.size();
        return it;
    }
};

} // namespace assignment4
