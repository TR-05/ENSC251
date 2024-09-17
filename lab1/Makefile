CXX      := g++
CC       := gcc

# compiler flags:
CXXFLAGS := -std=gnu++2b -pedantic-errors -Wall -Wextra -Werror

# the build target executable:
TARGET = lab1

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp

clean:
	$(RM) $(TARGET) 
 
