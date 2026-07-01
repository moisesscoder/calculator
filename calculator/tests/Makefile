# Define compiler and linker
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -pthread
LDFLAGS = -pthread

# Define source directories
SRC_DIR = ../src
OBJ_DIR = obj
BIN_DIR = bin

# Define GTest location (adjust as needed)
GTEST_DIR = /usr/local/include/gtest
GTEST_LIB_DIR = /usr/local/lib

# Find all .cpp files in src and tests directories
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
SRCS := $(filter-out $(SRC_DIR)/main.cpp, $(SRCS))

TEST_SRCS = $(wildcard *.cpp)

# Generate object file names
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
TEST_OBJS = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TEST_SRCS))

# Define executable names
TEST_TARGET = $(BIN_DIR)/unittest

.PHONY: all

all: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(OBJS) $(TEST_OBJS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -DUNITTEST -I$(GTEST_DIR) $(LDFLAGS) $^ -L$(GTEST_LIB_DIR) -lgtest -lgtest_main -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
