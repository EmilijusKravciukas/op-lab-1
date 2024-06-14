# Define the compiler and the flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Define the source files
SRC = $(wildcard *.cpp)

# Define the source files for main and test
SRC_MAIN = $(filter-out tests.cpp, $(SRC))
SRC_TEST = tests.cpp

# Define the header files
HEADERS = $(wildcard *.h)

# Define the object files
OBJ_MAIN = $(SRC_MAIN:.cpp=.o)
OBJ_TEST = $(SRC_TEST:.cpp=.o)

# Define the executable files
EXE_MAIN = StudApp.exe
EXE_TEST = TestApp.exe

# Default target: build both executables
all: $(EXE_MAIN) $(EXE_TEST)

# Rule to build the main executable
$(EXE_MAIN): $(OBJ_MAIN)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build the test executable
$(EXE_TEST): $(OBJ_TEST)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ_MAIN) $(OBJ_TEST) $(EXE_MAIN) $(EXE_TEST)

test: $(EXE_TEST)
	./$(EXE_TEST)

run: $(EXE_MAIN)
	./$(EXE_MAIN)

# Phony targets
.PHONY: all clean test run
