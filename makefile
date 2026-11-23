run:
	@mkdir -p build
	@g++ ./src/main.cpp ./src/function.cpp ./src/gradient.cpp ./src/vec.cpp -o build/main -I include/ -Wall
	@./build/main

clean:
	rm -rf build
