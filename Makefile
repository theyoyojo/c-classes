CC = gcc
CFLAGS = -g -Wall
OBJECTS = main.o vstring.o

driver: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o driver 
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
vstring.o: vstring.c
	$(CC) $(CFLAGS) -c vstring.c -o vstring.o
clean:
	rm driver $(OBJECTS)