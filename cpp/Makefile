all: main.o
	g++ -O2 -o fb_test main.o

main.o: FORCE
	g++ -c -O2 -o main.o main.cc

clean:
	rm *.o
	rm fb_test

FORCE:
