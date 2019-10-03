run:
	g++ -std=c++11 -O3 -march=native -Iinclude/ main.cpp module/* -o main && ./main

python:
	g++ -O3 -Wall -shared -std=c++11 -fPIC `python -m pybind11 --includes` clsocpp.cpp module/* -o clsocpp`python3-config --extension-suffix` -I/home/reupiey/anaconda3/envs/py37/include -Iinclude