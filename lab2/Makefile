CPPFLAGS := -std=gnu++2b -pedantic-errors -Wall -Wextra -Werror -stdlib=libc++

# Build the executable
carTest: lab2.o Car.o
	g++ -o carTest lab2.o Car.o

# Compile Car.o
Car.o: Car.cpp
	g++ -c $(CPPFLAGS) Car.cpp

# Compile lab2.o
lab2.o: lab2.cpp
	g++ -c $(CPPFLAGS) lab2.cpp

# Clean up the directory
clean:
	rm -f lab2 *.o carTest

run:
	make clean
	make
	./carTest