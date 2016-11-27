.PHONY: build lint

build:
	g++ -std=c++11 src/*.cpp -I include -o bin/math

lint:
	cpplint --filter=-legal/copyright include/*.hpp src/*.cpp
