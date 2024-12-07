#set to c++ 20 and add error flags
CPPFLAGS := -std=c++17

# Name the executable
TARGET = 2dmp
OUTDIR = build

# Find all .cpp files and corresponding .o files
SRCS := $(wildcard src/*.cpp) main.cpp
OBJS := $(patsubst src/%.cpp,$(OUTDIR)/src/%.o,$(SRCS))

# Create the output directory if it doesn't exist
$(OUTDIR):
	mkdir -p $(OUTDIR)/src

# Build the executable
$(OUTDIR)/$(TARGET): $(OBJS)
	g++ $(CPPFLAGS) -o $(OUTDIR)/$(TARGET) $(OBJS)

# Compile .o files from .cpp files
$(OUTDIR)/src/%.o: src/%.cpp | $(OUTDIR)
	g++ -c $(CPPFLAGS) $< -o $@

# Clean up the directory
clean:
	rm -rf $(OUTDIR)

# make and run the program in one command
run:
	make clean
	make $(OUTDIR)/$(TARGET)
	./$(OUTDIR)/$(TARGET)