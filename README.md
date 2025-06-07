// shiraba01@gmail.com
# Custom Iterators Project

This project demonstrates the implementation of a custom container class and several specialized iterators in C++ using templates.

## Project Structure

- `MyContainer.hpp` – Defines the generic container `MyContainer<T>`, with support for adding, removing, printing, and accessing internal data.
- `OrderIterator.hpp` – Iterates through elements in the order they were added.
- `ReverseOrderIterator.hpp` – Iterates in reverse order of insertion.
- `AscendingOrderIterator.hpp` – Iterates in ascending order of element values.
- `DescendingOrderIterator.hpp` – Iterates in descending order of element values.
- `SideCrossOrderIterator.hpp` – Iterates in a zigzag pattern: smallest, largest, second smallest, etc.
- `MiddleOutOrderIterator.hpp` – Iterates starting from the middle and expanding outward alternately left and right.
- `main.cpp` – A demonstration file that shows how to use the container and all the iterators.
- `test.cpp` – Contains unit tests for each class and function using `doctest`.
- `Makefile` – Provides commands for building, testing, memory-checking, and cleaning the project.

## Requirements

Make sure you have the following installed:

- `g++` with C++11 support or higher
- `valgrind` (for memory leak checks)
- `make` (to use the provided Makefile)

To install on Ubuntu:
```bash
sudo apt update
sudo apt install g++ valgrind make
```

## How to Use

### 1. Build and Run the Demo
```bash
make Main
```

### 2. Run Unit Tests
```bash
make test
```

### 3. Check for Memory Leaks
```bash
make valgrind
```

### 4. Clean All Generated Files
```bash
make clean
```

## Notes

- All iterators are implemented using **template classes** and must be defined in header files (`.hpp`) to allow inlining by the compiler.
- The iterators rely on an index vector to traverse the container in various orders without modifying the original container data.
