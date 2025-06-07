// shiraba01@gmail.com
#pragma once
#include <vector>
#include "MyContainer.hpp"

namespace assignment4 {

template <typename T = int>
class OrderIterator {
private:
    const MyContainer<T>& container;
    std::vector<size_t> indices;
    size_t currentIndex;

public:
    /*
     Constructor:
     - Initializes the iterator with a reference to a MyContainer<T>.
     - Fills the internal index vector with sequential indices [0, 1, 2, ..., n-1],
       reflecting the original insertion order of elements in the container.
    */
    OrderIterator(const MyContainer<T>& cont) : container(cont), currentIndex(0) {
        const auto& data = container.getData();
        indices.resize(data.size());

        for (size_t i = 0; i < data.size(); ++i) {
            indices[i] = i; // Original insertion order
        }
    }

    /*
     Dereference operator (*):
     - Returns the current value in the iteration according to original insertion order.
    */
    const T& operator*() const {
        return container.getData()[indices[currentIndex]];
    }

    /*
     Pre-increment operator (++):
     - Advances the iterator to the next element in the original order.
     - Returns a reference to the updated iterator.
    */
    OrderIterator& operator++() {
        ++currentIndex;
        return *this;
    }

    /*
     Inequality operator (!=):
     - Compares the iterator’s current position with another iterator.
     - Returns true if they point to different positions.
    */
    bool operator!=(const OrderIterator& other) const {
        return currentIndex != other.currentIndex;
    }

    /*
     Static begin() method:
     - Returns an OrderIterator positioned at the beginning of the container.
    */
    static OrderIterator begin(const MyContainer<T>& cont) {
        return OrderIterator(cont);
    }

    /*
     Static end() method:
     - Returns an OrderIterator positioned past the last element.
     - Used to indicate the end of the iteration.
    */
    static OrderIterator end(const MyContainer<T>& cont) {
        OrderIterator it(cont);
        it.currentIndex = it.indices.size();
        return it;
    }
};

} // namespace assignment4
