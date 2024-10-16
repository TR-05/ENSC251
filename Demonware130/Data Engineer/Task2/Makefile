#set to c++ 20 and add error flags
CPPFLAGS := -std=c++2a -pedantic-errors -Wall -Wextra -Werror

# Name the executable
TARGET = lab3

# Find all .cpp files and corresponding .o files
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

# Build the executable
TARGET: $(OBJS)
	g++ -o $(TARGET) $(OBJS)

# Compile .o files from .cpp files
%.o: %.cpp
	g++ -c $(CPPFLAGS) $< -o $@

# Clean up the directory
clean:
	rm -f *.o $(TARGET)

# make and run the program in one command
run:
	make
	./$(TARGET)