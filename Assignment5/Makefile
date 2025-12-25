COMPILER = g++
FLAGS = -Wall -g -std=c++17
GTEST_FLAGS = -lgtest -lgtest_main -pthread

CORE_SRC = main.cpp
CORE_OBJ = $(CORE_SRC:.cpp=.o)

UNIT_SRC = test_matrix.cpp test_rational.cpp
UNIT_OBJ = $(UNIT_SRC:.cpp=.o)

TARGET = main
TEST_TARGET = run_tests

.PHONY: all clean test

all: $(TARGET) $(TEST_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TARGET): $(CORE_OBJ)
	$(COMPILER) $(FLAGS) -o $@ $^

$(TEST_TARGET): $(UNIT_OBJ)
	$(COMPILER) $(FLAGS) -o $@ $^ $(GTEST_FLAGS)

%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET) $(TEST_TARGET)
