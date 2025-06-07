// shiraba01@gmail.com
#pragma once
#include <vector>
#include "MyContainer.hpp"

namespace assignment4 {

template <typename T = int>
class MiddleOutOrderIterator {
private:
    const MyContainer<T>& container;
    std::vector<size_t> middleOutIndices;
    size_t currentIndex;

public:
    /*
     Constructor:
     - Initializes the iterator with a reference to a MyContainer<T>.
     - Builds a list of indices that represent the middle-out traversal order.
     - Starts from the middle index and alternates between right and left indices.
     - If the container is empty, initialization is skipped.
    */
    MiddleOutOrderIterator(const MyContainer<T>& cont) : container(cont), currentIndex(0) {
        const auto& data = container.getData();
        size_t n = data.size();

        if (n == 0) return;

        // Create indices representing the original order
        std::vector<size_t> indices(n);
        for (size_t i = 0; i < n; ++i) {
            indices[i] = i;
        }

        // Determine the middle index (rounded down)
        size_t middle = n / 2;

        // Build the middle-out order: middle, right, left, right, left...
        middleOutIndices.push_back(indices[middle]);

        size_t left = (middle == 0) ? 0 : middle - 1;
        size_t right = middle + 1;
        bool goLeft = false;

        while (middleOutIndices.size() < n) {
            if (goLeft && left < middle) {
                middleOutIndices.push_back(indices[left--]);
            } else if (!goLeft && right < n) {
                middleOutIndices.push_back(indices[right++]);
            }
            goLeft = !goLeft;
        }
    }

    /*
     Dereference operator (*):
     - Returns the current element in the middle-out traversal order.
    */
    const T& operator*() const {
        return container.getData()[middleOutIndices[currentIndex]];
    }

    /*
     Pre-increment operator (++):
     - Moves the iterator to the next index in the middle-out order.
     - Returns a reference to the updated iterator.
    */
    MiddleOutOrderIterator& operator++() {
        ++currentIndex;
        return *this;
    }

    /*
     Inequality operator (!=):
     - Compares the position of two iterators.
     - Returns true if the current indices are different.
    */
    bool operator!=(const MiddleOutOrderIterator& other) const {
        return currentIndex != other.currentIndex;
    }

    /*
     Static begin() method:
     - Returns a MiddleOutOrderIterator initialized at the beginning of traversal (middle element).
    */
    static MiddleOutOrderIterator begin(const MyContainer<T>& cont) {
        return MiddleOutOrderIterator(cont);
    }

    /*
     Static end() method:
     - Returns a MiddleOutOrderIterator positioned after the last element in the traversal.
     - Used to indicate end of iteration.
    */
    static MiddleOutOrderIterator end(const MyContainer<T>& cont) {
        MiddleOutOrderIterator it(cont);
        it.currentIndex = it.middleOutIndices.size();
        return it;
    }
};

} // namespace assignment4
