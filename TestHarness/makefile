CC=g++
MKDIR=mkdir

TestHarness.out: TestHarness.o
	$(CC) -std=c++11 -Wall TestHarness.o Engine.o TerminalInitException.o Point.o ArgumentRangeException.o -o TestHarness.out -lncurses

TestHarness.o: Engine.o
	$(CC) -std=c++11 -Wall -c TestHarness.cpp -o TestHarness.o -I../Outmoded/include

Engine.o: TerminalInitException.o Point.o
	$(CC) -std=c++11 -Wall -static -c -I../Outmoded/include ../Outmoded/src/Engine.cpp -o Engine.o

TerminalInitException.o:
	$(CC) -std=c++11 -Wall -static -c -I../Outmoded/include ../Outmoded/src/Exceptions/TerminalInitException.cpp -o TerminalInitException.o

Point.o: ArgumentRangeException.o
	$(CC) -std=c++11 -Wall -static -c -I../Outmoded/include ../Outmoded/src/Point.cpp -o Point.o

ArgumentRangeException.o: dir
	$(CC) -std=c++11 -Wall -static -c -I../Outmoded/include ../Outmoded/src/Exceptions/ArgumentRangeException.cpp -o ArgumentRangeException.o

dir:
	mkdir -p build

clean:
	rm *.o \
	rm -rf build