#Makefile
#To execute any of these functions, run $make "function" in the terminal.
#Example: $make test
#If you just run make it will only execute the first function.

#Compile and run main
main: main.cpp puzzle.cpp
	g++ -std=c++11 -o main main.cpp
	./main
#Clean directory and remove object files
clean:
	-rm -f *.o main
