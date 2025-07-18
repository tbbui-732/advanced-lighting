CXX=g++
WARNING_FLAGS=-Wall -Wextra -Werror -pedantic
STD=-std=c++23

main:
	$(CXX) $(WARNING_FLAGS) $(STD) main.cpp -o main

clean:
	rm main
