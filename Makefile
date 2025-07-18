CXX=g++
WARNING_FLAGS=-Wall -Wextra -Werror -pedantic

main:
	$(CXX) $(WARNING_FLAGS) main.cpp -o main
