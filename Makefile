bin/TestListArray: TestListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/TestListArray TestListArray.cpp ListArray.h

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h
bin/testListLinked: testListLinked.cpp ListLinked.h List.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp ListLinked.h
Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp
bin/testPoint2D: testPoint2D.cpp Point2D.o
	g++ -c testPoint2D.cpp
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.o Point2D.o
clean:
	rm -r *.o *.gch bin
