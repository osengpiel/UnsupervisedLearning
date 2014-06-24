OBJS = main.o SOM.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -std=c++0x
LFLAGS = -Wall $(DEBUG)

main : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o program

main.o : main.cpp SOM/SOM.h SOM/SOM.cpp
	$(CC) $(CFLAGS) main.cpp

SOM.o : SOM/SOM.h SOM/SOM.cpp
	$(CC) $(CFLAGS) SOM/SOM.cpp SOM/SOM.h
