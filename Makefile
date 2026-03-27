CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = lucidsh

all: $(TARGET)

$(TARGET): main.c template.c
	$(CC) $(CFLAGS) $^ -o $(TARGET)

clean:
	rm -f $(TARGET)
