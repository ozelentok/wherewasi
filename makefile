SOURCES = $(wildcard *.cpp)
OBJS = $(SOURCES:.cpp=.o)
CC = g++
CFLAGS = -Wall -Werror -std=c++11 -O2

all: wherewasi 

wherewasi: $(OBJS)
	$(CC) -o $@ $(OBJS)
	strip $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJS) wherewasi
