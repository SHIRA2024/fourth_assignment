// shiraba01@gmail.com
#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>

namespace assignment4 {

template <typename T = int>
class MyContainer {
private:
    std::vector<T> data; // Internal storage for elements

public:
    /*
     Default constructor:
     - Initializes an empty container.
     - Uses default vector initialization.
    */
    MyContainer() = default;

    /*
     Adds an element to the container.
     @param value: The value to be added to the container.
     - Appends the value to the internal vector.
    */
    void add(const T& value) {
        data.push_back(value);
    }

    /*
     Removes all occurrences of a given value from the container.
     @param value: The value to remove.
     @throws std::runtime_error if the value does not exist in the container.
     - Iterates through the container and builds a filtered list without the target value.
     - Replaces the internal data with the filtered result.
    */
    void remove(const T& value) {
        bool found = false;
        std::vector<T> filtered;

        for (const T& item : data) {
            if (item != value) {
                filtered.push_back(item);
            } else {
                found = true;
            }
        }

        if (!found) {
            throw std::runtime_error("Value not found in container");
        }

        data = filtered;
    }

    /*
     Output stream operator.
     @param os: The output stream.
     @param container: The container to print.
     @return The updated output stream.
     - Prints the elements in the container in a readable format: [val1, val2, ...]
    */
    friend std::ostream& operator<<(std::ostream& os, const MyContainer<T>& container) {
        os << "[";
        for (size_t i = 0; i < container.data.size(); ++i) {
            os << container.data[i];
            if (i != container.data.size() - 1)
                os << ", ";
        }
        os << "]";
        return os;
    }


        /**
     * @brief Returns the number of elements currently stored in the container.
     * 
     * @return std::size_t The number of elements in the container.
     */

     size_t size() const {
        return data.size();
    }

    /*
     Provides access to the internal vector (read-only).
     @return A const reference to the internal vector storing container elements.
     - Used by iterators to access the container's data without modifying it.
    */
    const std::vector<T>& getData() const {
        return data;
    }
};

} // namespace assignment4
