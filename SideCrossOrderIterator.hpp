// shiraba01@gmail.com
#pragma once
#include <vector>
#include <algorithm>
#include "MyContainer.hpp"

namespace assignment4 {

template <typename T = int>
class SideCrossOrderIterator {
private:
    const MyContainer<T>& container;
    std::vector<size_t> sideCrossIndices;
    size_t currentIndex;

public:
    /*
     Constructor:
     - Initializes the iterator with a reference to a MyContainer<T>.
     - Sorts the container indices in ascending order by value.
     - Builds the iteration order in a "zigzag" pattern:
       starting from the smallest element, then the largest, then second smallest, etc.
       For example, if sorted = [1, 2, 6, 7, 15] → iteration order: [1, 15, 2, 7, 6].
    */
    SideCrossOrderIterator(const MyContainer<T>& cont) : container(cont), currentIndex(0) {
        const auto& data = container.getData();
        std::vector<size_t> sortedIndices(data.size());

        for (size_t i = 0; i < data.size(); ++i) {
            sortedIndices[i] = i;
        }

        std::sort(sortedIndices.begin(), sortedIndices.end(),
                  [&data](size_t a, size_t b) {
                      return data[a] < data[b];
                  });

       
        size_t left = 0;
        size_t right = sortedIndices.size() - 1;
        bool takeLeft = true;

        while (left <= right) {
            if (takeLeft) {
                sideCrossIndices.push_back(sortedIndices[left]);
                ++left;
            } else {
                sideCrossIndices.push_back(sortedIndices[right]);
                if (right == 0) break;
                --right;
            }
            takeLeft = !takeLeft;
        }
    }

    /*
     Dereference operator (*):
     - Returns the current value in the side-cross traversal order.
    */
    const T& operator*() const {
        return container.getData()[sideCrossIndices[currentIndex]];
    }

    /*
     Pre-increment operator (++):
     - Advances the iterator to the next element in the side-cross sequence.
     - Returns a reference to the updated iterator.
    */
    SideCrossOrderIterator& operator++() {
        ++currentIndex;
        return *this;
    }

    /*
     Inequality operator (!=):
     - Compares the current index of two iterators.
     - Returns true if they are at different positions.
    */
    bool operator!=(const SideCrossOrderIterator& other) const {
        return currentIndex != other.currentIndex;
    }

    /*
     Static begin() method:
     - Returns a SideCrossOrderIterator positioned at the start of the zigzag traversal.
    */
    static SideCrossOrderIterator begin(const MyContainer<T>& cont) {
        return SideCrossOrderIterator(cont);
    }

    /*
     Static end() method:
     - Returns a SideCrossOrderIterator positioned past the last element.
     - Used to signal the end of the iteration.
    */
    static SideCrossOrderIterator end(const MyContainer<T>& cont) {
        SideCrossOrderIterator it(cont);
        it.currentIndex = it.sideCrossIndices.size();
        return it;
    }
};

} // namespace assignment4
