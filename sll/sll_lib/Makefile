CC = gcc
CFLAGS = -fPIC -Wall -Wextra -O2
LDFLAGS = -shared
TARGET = libsll_lib.so
SRC = sll_lib.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	   $(CC) $(LDFLAGS) -o  $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(TARGET)
