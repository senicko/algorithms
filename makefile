compile:
	clang++ $(file) -o ./build/main --std=c++17 -Wall

run:
	./build/main