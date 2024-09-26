#set to c++ 20 and add error flags
CPPFLAGS := -std=c++2a -pedantic-errors -Wall -Wextra -Werror
COMPILER := g++

# Name the executable
TARGET = project

# Directories for object files and target
OBJDIR := obj
BINDIR := bin

# Find all .cpp files and corresponding .o files
SRCS := $(wildcard *.cpp)
SRCS += $(shell find src -name '*.cpp') # for larger projects target src folder and subfolders
INCLUDES := $(shell find include -name '*.h') # not sure if this works
OBJS := $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))

# Create directories if they don't exist
$(shell mkdir -p $(OBJDIR) $(BINDIR))
$(shell find src -type d -exec mkdir -p $(OBJDIR)/{} \;)

# Build the executable
$(BINDIR)/$(TARGET): $(OBJS) $(INCLUDES)
	$(COMPILER) -o $@ $(OBJS)

# Compile .o files from .cpp files
$(OBJDIR)/%.o: %.cpp
	$(COMPILER) -c -g $(CPPFLAGS) $< -o $@

# Clean up the directory
clean:
	rm -rf $(OBJDIR)/* $(BINDIR)/$(TARGET)

# make and run the program in one command
run:
	make clean
	make
	./$(BINDIR)/$(TARGET)