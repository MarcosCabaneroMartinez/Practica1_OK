bin/testListArray: testListArray.cpp ListArray. List.h
	mkdir -p bin
	g++ -o bin/testListArray.cpp ListArray.h

bin/testNode:testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h

clean:
	rm -r *.o *.gch bin

