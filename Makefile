CXX=g++
WARNING_FLAGS=-Wall -Wextra -Werror -pedantic
STD=-std=c++23

main:
	$(CXX) $(WARNING_FLAGS) $(STD) src/main.cpp -o build/main

clean:
	rm build/main
