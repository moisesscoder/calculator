# Define compiler and linker
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -pthread
LDFLAGS = -pthread

# Define source directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Find all .cpp files in src and tests directories
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Generate object file names
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Define executable names
TARGET = $(BIN_DIR)/calculator

.PHONY: all clean unittest lint format-check check

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(OBJS)
	@echo "Building app..."
	@mkdir -p $(@D)
	$(CXX) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR) -c $< -o $@

unittest: $(TEST_TARGET)
	@if [ -f tests/Makefile ]; then \
		echo "Running unit tests"; \
		make -C tests; \
	fi

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@if [ -f tests/Makefile ]; then \
		make -C tests clean; \
	fi

# Linter target using clang-tidy
lint:
	@echo "Running C++ linter (clang-tidy)..."
	clang-tidy $(SRCS) -checks="cppcoreguidelines*" -warnings-as-errors='*' -- -std=c++17

# Formatter check target using clang-format
format-check:
	@echo "Checking C++ formatting (clang-format)..."
	clang-format --style=google -dry-run $(SRCS)

# Example of integrating format-check into a 'check' target
check: lint format-check
