CC=g++
RM=rm
CFLAGS=-c -Wall -I.

all:student

student: student.o main.o
	$(CC) $^ -o $@

student.o: student.cpp
	$(CC) $(CFLAGS) $^

main.o: main.cpp
	$(CC) $(CFLAGS) $^

clean:
	$(RM) *.o student


