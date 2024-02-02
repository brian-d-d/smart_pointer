C++ = clang++
C++FLAGS = -std=c++2b

all: objects
	$(C++) $(C++FLAGS) mysmart_ptr.o main.o -I . -o main

objects: 
	$(C++) $(C++FLAGS) mysmart_ptr.cpp -I . -c -o mysmart_ptr.o
	$(C++) $(C++FLAGS) main.cpp -I . -c -o main.o

