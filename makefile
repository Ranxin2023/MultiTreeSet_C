CC=gcc
CFLAGS=-Wall -Werror
DEPS=TreeSet.h queue.h
SRCS=main.c TreeSet.c queue.c
OBJECTS=$(SRCS:.c=.o)
TARGET=tree_set

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	if exist *.o del *.o
	if exist $(TARGET).exe del $(TARGET).exe