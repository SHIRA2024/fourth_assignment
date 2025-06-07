// shiraba01@gmail.com
#pragma once
#include <vector>
#include "MyContainer.hpp"

namespace assignment4 {

template <typename T = int>
class ReverseOrderIterator {
private:
    const MyContainer<T>& container;
    std::vector<size_t> reverseIndices;
    size_t currentIndex;

public:
    /*
     Constructor:
     - Initializes the iterator with a reference to a MyContainer<T>.
     - Builds a vector of indices representing the reverse order of insertion.
     - For a container of size n, reverseIndices will be [n-1, n-2, ..., 0].
    */
    ReverseOrderIterator(const MyContainer<T>& cont) : container(cont), currentIndex(0) {
        const auto& data = container.getData();
        reverseIndices.resize(data.size());

        for (size_t i = 0; i < data.size(); ++i) {
            reverseIndices[i] = data.size() - 1 - i; // Fill from end to start
        }
    }

    /*
     Dereference operator (*):
     - Returns the current element in the reverse iteration.
    */
    const T& operator*() const {
        return container.getData()[reverseIndices[currentIndex]];
    }

    /*
     Pre-increment operator (++):
     - Advances the iterator to the next element in reverse order.
     - Returns a reference to the updated iterator.
    */
    ReverseOrderIterator& operator++() {
        ++currentIndex;
        return *this;
    }

    /*
     Inequality operator (!=):
     - Compares two iterators for inequality based on current index.
     - Returns true if the positions are different.
    */
    bool operator!=(const ReverseOrderIterator& other) const {
        return currentIndex != other.currentIndex;
    }

    /*
     Static begin() method:
     - Returns a ReverseOrderIterator positioned at the last inserted element (start of reverse traversal).
    */
    static ReverseOrderIterator begin(const MyContainer<T>& cont) {
        return ReverseOrderIterator(cont);
    }

    /*
     Static end() method:
     - Returns a ReverseOrderIterator positioned past the first element (end of traversal).
     - Used to mark the end of iteration.
    */
    static ReverseOrderIterator end(const MyContainer<T>& cont) {
        ReverseOrderIterator it(cont);
        it.currentIndex = it.reverseIndices.size();
        return it;
    }
};

} // namespace assignment4
