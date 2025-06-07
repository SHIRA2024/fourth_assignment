// shiraba01@gmail.com
#pragma once
#include <vector>
#include <algorithm>
#include "MyContainer.hpp"

namespace assignment4 {

template <typename T = int>
class AscendingOrderIterator {
private:
    const MyContainer<T>& container;
    std::vector<size_t> sortedIndices;
    size_t currentIndex;

public:
    /*
     Constructor:
     - Initializes the iterator with a reference to a MyContainer<T>.
     - Builds a vector of indices pointing to the elements of the container,
       sorted in ascending order based on the values they point to.
    */
    AscendingOrderIterator(const MyContainer<T>& cont) : container(cont), currentIndex(0) {
        const auto& data = container.getData();
        sortedIndices.resize(data.size());

        for (size_t i = 0; i < data.size(); ++i) {
            sortedIndices[i] = i;
        }

        std::sort(sortedIndices.begin(), sortedIndices.end(),
                  [&data](size_t a, size_t b) {
                      return data[a] < data[b];
                  });
    }

    /*
     Dereference operator (*):
     - Returns a reference to the current value the iterator points to.
     - Accesses the container using the sorted index at the current position.
    */
    const T& operator*() const {
        return container.getData()[sortedIndices[currentIndex]];
    }

    /*
     Pre-increment operator (++):
     - Advances the iterator to the next position in the sorted order.
     - Returns a reference to the updated iterator.
    */
    AscendingOrderIterator& operator++() {
        ++currentIndex;
        return *this;
    }

    /*
     Inequality operator (!=):
     - Compares two iterators.
     - Returns true if the current positions are different.
     - Typically used to determine the end of iteration in a loop.
    */
    bool operator!=(const AscendingOrderIterator& other) const {
        return currentIndex != other.currentIndex;
    }

    /*
     Static begin() method:
     - Returns an AscendingOrderIterator pointing to the beginning (smallest element).
     - Used to start a range-based iteration over the container.
    */
    static AscendingOrderIterator begin(const MyContainer<T>& cont) {
        return AscendingOrderIterator(cont);
    }

    /*
     Static end() method:
     - Returns an AscendingOrderIterator pointing past the last element.
     - Used to signal the end of iteration.
    */
    static AscendingOrderIterator end(const MyContainer<T>& cont) {
        AscendingOrderIterator it(cont);
        it.currentIndex = it.sortedIndices.size();
        return it;
    }
};

} // namespace assignment4
