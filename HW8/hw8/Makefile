CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant -ggdb
//CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings

main: main.cpp vertex.h vertex.cpp edge.h edge.cpp graph.h graph.cpp
	echo ------------compiling main.cpp to create executable program kruskals--------------
	g++ -ggdb $(CXXFLAGS) main.cpp vertex.h vertex.cpp edge.h edge.cpp graph.h graph.cpp  -o kruskals


