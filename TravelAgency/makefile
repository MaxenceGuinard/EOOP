CC = g++
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = a.out

default: help

compile: $(EXEC)

%.o : %.cpp
	$(CC) -o $@ -c $< -Wall -Wextra -pedantic

$(EXEC) : $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -rf *.o
	rm a.out

run:
	./a.out

help:
	@echo ""
	@echo "Use 'make' with one argument:"
	@echo ""
	@echo "  make compile"
	@echo "  make run"
	@echo "  make clean"
	@echo "  make full"
	@echo ""

full: compile run clean
