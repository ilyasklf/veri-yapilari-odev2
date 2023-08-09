hepsi: derle calistir

derle:
	g++ -I./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I./include/ -o ./lib/BST.o -c ./src/BST.cpp
	g++ -I./include/ -o ./lib/Test.o -c ./src/Test.cpp

	g++ -I./include/ -o ./bin/Test ./lib/Node.o ./lib/Stack.o  ./lib/BST.o  ./src/Test.cpp

calistir:
	./bin/Test
