# shiraba01@gmail.com

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Files
MAIN_SRC = main.cpp
TEST_SRC = test.cpp
HEADERS = $(wildcard *.hpp)

# Executables
MAIN_EXEC = main_exec
TEST_EXEC = test_exec

# Default target
all: $(MAIN_EXEC)

# Build main executable
$(MAIN_EXEC): $(MAIN_SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(MAIN_EXEC) $(MAIN_SRC)

# Build test executable
$(TEST_EXEC): $(TEST_SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) $(TEST_SRC)

# Run main demo
.PHONY: Main
Main: $(MAIN_EXEC)
	./$(MAIN_EXEC)

# Run tests
.PHONY: test
test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Run valgrind on tests
.PHONY: valgrind
valgrind: $(TEST_EXEC)
	valgrind --leak-check=full --track-origins=yes ./$(TEST_EXEC)

# Clean build files
.PHONY: clean
clean:
	rm -f $(MAIN_EXEC) $(TEST_EXEC)
