CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant -ggdb
//CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings

main: main.cpp Sorter.cpp QuickSorter.cpp HeapSorter.cpp InsertionSorter.cpp Sorter.h QuickSorter.h HeapSorter.h InsertionSorter.h Timer.h
	echo ------------compiling main.cpp to create executable program main--------------
	g++ -ggdb $(CXXFLAGS) main.cpp Sorter.cpp QuickSorter.cpp HeapSorter.cpp InsertionSorter.cpp Sorter.h QuickSorter.h HeapSorter.h InsertionSorter.h Timer.h -o main
