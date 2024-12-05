#set to c++ 20 and add error flags
CPPFLAGS := -std=c++2a #-pedantic-errors -Wall -Wextra -Werror

# Name the executable
TARGET = 2dmp
OUTDIR = build

# Find all .cpp files and corresponding .o files
SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,$(OUTDIR)/%.o,$(SRCS))

# Create the output directory if it doesn't exist
$(OUTDIR):
	mkdir -p $(OUTDIR)

# Build the executable
$(OUTDIR)/$(TARGET): $(OBJS)
	g++ -o $(OUTDIR)/$(TARGET) $(OBJS)

# Compile .o files from .cpp files
$(OUTDIR)/%.o: %.cpp | $(OUTDIR)
	g++ -c $(CPPFLAGS) $< -o $@

# Clean up the directory
clean:
	rm -rf $(OUTDIR)

# make and run the program in one command
run:
#	make clean
	make $(OUTDIR)/$(TARGET)
	./$(OUTDIR)/$(TARGET)