CXXFLAGS = 

main.exe: main.o existing_node_exception.o empty_tree_exception.o
	g++ main.o existing_node_exception.o empty_tree_exception.o -o main.exe -std=c++0x

main.o: main.cpp
	g++ -c main.cpp -o main.o -std=c++0x

existing_node_exception.o: existing_node_exception.cpp
	g++ -c existing_node_exception.cpp -o existing_node_exception.o

empty_tree_exception.o: empty_tree_exception.cpp
	g++ -c empty_tree_exception.cpp -o empty_tree_exception.o

.PHONY:
clean:
	rm *.exe *.o
