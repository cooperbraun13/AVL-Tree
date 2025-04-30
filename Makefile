all: compile run clean

compile: 
	@g++ -std=c++11 avl_node.cpp avl_tree.cpp main.cpp -o avl

run:
	@./avl

clean:
	@rm avl

test: test_compile test_run test_clean

test_compile:
	@g++ -std=c++11 avl_node.cpp avl_tree.cpp test_avl_tree.cpp -o test

test_run:
	@./test

test_clean:
	@rm test