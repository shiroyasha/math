.PHONY: build lint

build:
	g++ -std=c++11 src/*.cc -I include -o bin/math

lint:
	cpplint --filter=-legal/copyright include/*.hh src/*.cc
