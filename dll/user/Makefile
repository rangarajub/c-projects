# Variables

CC = gcc
CFLAGS = -Wall -Wextra -I.
LDFLAGS = -L. -ldll_lib -Wl,-rpath,.
TARGET = myapp
SRC = main.c
OBJ = $(SRC:.c=.o)

# Default Target

all: $(TARGET)

# Link the application

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

# Compile main.c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(TARGET)
