CXX      := g++
CC       := gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CXXFLAGS := -std=gnu++2b -pedantic-errors -Wall -Wextra -Werror

# the build target executable:
TARGET = lab1

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp

clean:
	$(RM) $(TARGET) 
 
