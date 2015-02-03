CC = g++
CC_CFLAGS = -Wall -Werror -std=c++11

EXEC = bin/wherewasi
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:src/%.cpp=bin/%.o)

all: $(EXEC)

$(EXEC): $(OBJECTS)
	mkdir -p bin
	$(CC) $(OBJECTS) -o $(EXEC)

$(OBJECTS): bin/%.o : src/%.cpp
	mkdir -p bin
	$(CC) $(CC_CFLAGS) -c $< -o $@

install: all
	cp $(EXEC) /usr/$(EXEC)

uninstall:
	rm /usr/$(EXEC)

clean:
	rm -f $(EXEC) $(OBJECTS)
