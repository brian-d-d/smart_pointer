C++ = clang++
C++FLAGS = -std=c++2b

all: objects
	$(C++) $(C++FLAGS) myshared_ptr.o main.o -I . -lgmock_main -lgmock -lgtest -lgtest_main -o main

objects: 
	$(C++) $(C++FLAGS) myshared_ptr.cpp -I . -c -o myshared_ptr.o
	$(C++) $(C++FLAGS) main.cpp -I . -c -o main.o

