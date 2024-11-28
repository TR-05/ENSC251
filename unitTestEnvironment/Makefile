GTEST_DIR = /opt/homebrew/include/gtest
GTEST_LIB = /opt/homebrew/lib

# Set to C++20 and add error flags
CPPFLAGS := -std=c++2a -pedantic-errors -Wall -Wextra -Werror -I$(GTEST_DIR)
LDFLAGS = -L$(GTEST_LIB) -lgtest -lgtest_main -pthread

# Name the executable
TARGET = carTest

# Find all .cpp files and corresponding .o files
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

# Build the executable
$(TARGET): $(OBJS)
	g++ -o $(TARGET) $(OBJS) $(LDFLAGS)

# Compile .o files from .cpp files
%.o: %.cpp
	g++ -c $(CPPFLAGS) $< -o $@

# Clean up the directory
clean:
	rm -f *.o $(TARGET)

# Make and run the program in one command
run: clean $(TARGET)
	./$(TARGET)