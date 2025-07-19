# compiler and flags
CXX = g++
CXXFLAGS = -Iinclude -std=c++20

# source files
SRC = src/main.cpp src/glad.c

# output binary
OUT = build/main

# libraries
LIBS = -Llib -lglfw3 -ldl -lm -lX11 -lpthread

# build rule
$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LIBS) -o $(OUT)

# clean rule
clean:
	rm -f $(OUT)
