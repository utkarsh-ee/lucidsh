
---

# ⚙️ Makefile

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = lucidsh

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET)
