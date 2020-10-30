all: date

# test: triangle_test
# 	./triangle_test

date.o: date.h date.cpp
	g++ -std=c++14 -Wall -c date.cpp

datecalc.o: datecalc.h datecalc.cpp
	g++ -std=c++14 -Wall -c datecalc.cpp

# triangle_test.o: triangle.h triangle_test.cpp
# 	g++ -std=c++14 -Wall -c triangle_test.cpp

main.o: datecalc.h date.h main.cpp
	g++ -std=c++14 -Wall -c main.cpp

date: date.o main.o
	g++ -std=c++14 -Wall date.o main.o -o date

# triangle_test: triangle.o triangle_test.o
# 	g++ -pthread -std=c++14 -Wall triangle.o triangle_test.o -lgtest_main -lgtest -lpthread -o triangle_test

clean:
	rm -f *.o date

	#datetest
