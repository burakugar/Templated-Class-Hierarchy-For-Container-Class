all: compile run

compile:
	g++ -o a -std=c++11 main.cpp
run:
	./a