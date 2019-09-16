run:
	clang++ -std=c++17 -march=native -Iinclude/ main.cpp lib/* -o main && ./main
