
#Basic Makefile for an OpenGL application

COMPILER := g++
COMPILER_FLAGS := -std=c++17

EXE := program
SRC_DIR := ./src
SRC := $(SRC_DIR)/*.cpp
TEST := test.out
SRC_OBJECT := ./*.o


compile: $(EXE)

$(EXE): $(SRC_OBJECT) 
	$(COMPILER) $(COMPILER_FLAGS) $(SRC_OBJECT) -o $(EXE)
	rm ./*.o

$(SRC_OBJECT): $(SRC) 
	$(COMPILER) $(COMPILER_FLAGS) $(SRC) -c 

run: 
	./$(EXE)

testing:
	$(COMPILER) test.cpp -o $(TEST)
	./$(TEST)

clean:
	rm $(EXE) 






