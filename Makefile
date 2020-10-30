all: date

test: date_test
	./date_test

date.o: date.h date.cpp
	g++ -std=c++14 -Wall -c date.cpp

datecalc.o: datecalc.h datecalc.cpp
	g++ -std=c++14 -Wall -c datecalc.cpp

date_test.o: date.h datecalc.h date_test.cpp
	g++ -std=c++14 -Wall -c date_test.cpp

main.o: datecalc.h date.h main.cpp
	g++ -std=c++14 -Wall -c main.cpp

date: date.o main.o
	g++ -std=c++14 -Wall date.o main.o -o date

date_test: date.o datecalc.o date_test.o
	g++ -pthread -std=c++14 -Wall date.o datecalc.o date_test.o -lgtest_main -lgtest -lpthread -o date_test


clean:
	rm -f *.o date date_test

	#datetest
