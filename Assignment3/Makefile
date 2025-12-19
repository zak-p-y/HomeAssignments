CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g
TARGET = main
TEST_TARGET = test
SOURCES = Autobot.cpp Battery.cpp Car.cpp Decepticon.cpp main.cpp Transformer.cpp Weapon.cpp
TEST_SOURCES = test.cpp Autobot.cpp Battery.cpp Car.cpp Decepticon.cpp Transformer.cpp Weapon.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: Autobot.o Battery.o Car.o Decepticon.o Transformer.o Weapon.o test.o
	g++ test.o Autobot.o Battery.o Car.o Decepticon.o Transformer.o Weapon.o -lgtest -lgtest_main -pthread -o test


clean:
	rm -f *.o $(TARGET) $(TEST_TARGET)
