
# TODO: add targets to compile LinkedList.c

# TODO: add a target for each .input file in the Data directory to run the compiled LinkedList program with the tests in ./Data

# TODO: add a target that can run all the tests above.


COMPILER = gcc

C_FLAGS = -Wall -Wextra -g

help:
	@printf "available command:\n"
	@printf "	make help               (this command)\n"
	@printf "	make Stack         (to build your C program)\n"
	@printf "	make test               (to run every test case)\n"

Stack: Stack.o
	$(COMPILER) $(C_FLAGS) -o Stack Stack.o

Stack.o: Stack.c
	$(COMPILER) $(C_FLAGS) -c Stack.c

test: test1

test1: Stack Data/test1.input Data/test1.expected
		./Stack < Data/test1.input > test1.result
		./TestPassed.sh test1.result Data/test1.expected

test2: Stack Data/test2.input Data/test2.expected
		./Stack < Data/test2.input > test1.result
		./TestPassed.sh test2.result Data/test2.expected
