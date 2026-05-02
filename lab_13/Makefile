.PHONY: all clean 

CC = gcc
CFLAGS = -Wall
TARGET = main
INCLUDES = -I./include

all: $(TARGET)

$(TARGET): main.o libcar.a
	$(CC) $(CFLAGS) main.o -o $@ -L. -lcar

libcar.a: car.o
	ar rcs $@ car.o

%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean:
	rm -rf *.o libcar.a $(TARGET)