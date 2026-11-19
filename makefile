run:
	@mkdir -p build
	@g++ ./src/main.cpp ./src/function.cpp ./src/vec.cpp -o build/main -I include/
	@./build/main

clean:
	rm -rf build
