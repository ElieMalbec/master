CPP=g++ --std=c++11 -Wall -Wextra 

all:point

point : test.o point.o
	g++ -o point Test.o Point.o
	
test.o : Test.cpp
	${CPP} -c Test.cpp

point.o : Point.cpp
	${CPP} -c Point.cpp

clean :
	rm -f *.o
