C++ = clang++
C++FLAGS = -std=c++11 -I ../smart_ptr/ 
SRC_PREFIX = /Users/admin/Documents/learning/implement_smartptr/cmake_implementation/../

main: objects
	$(C++) $(C++FLAGS) Main.o MySmart_Ptr.o -o $(SRC_PREFIX)Main

objects: 
	$(C++) $(C++FLAGS) -c $(SRC_PREFIX)main.cpp -o Main.o
	$(C++) $(C++FLAGS) -c $(SRC_PREFIX)smart_ptr/mysmart_ptr.cpp -o MySmart_Ptr.o
