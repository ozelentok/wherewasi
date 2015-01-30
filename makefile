SOURCES = $(wildcard *.cpp)
OBJS = $(SOURCES:.cpp=.o)
CC = g++
CFLAGS = -Wall -Werror -std=c++11 -O2 -g

all: wherewasi 

wherewasi: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)
	strip $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJS) wherewasi
