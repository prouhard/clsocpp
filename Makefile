run:
	g++ -std=c++11 -O3 -march=native -Iinclude/ main.cpp lib/* -o main && ./main
