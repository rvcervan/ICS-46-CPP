CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant
//CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings

main: main.cpp SortedList.cpp SortedLinkedList.cpp SortedArrayList.cpp
	echo ------------compiling main.cpp to create executable program main--------------
	g++ -ggdb $(CXXFLAGS) main.cpp SortedList.cpp SortedLinkedList.cpp SortedArrayList.cpp -o main
