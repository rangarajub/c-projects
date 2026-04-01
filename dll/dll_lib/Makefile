CC = gcc
CFLAGS = -fPIC -Wall -Wextra -O2
LDFLAGS = -shared
TARGET = libdll_lib.so
SRC = dll_lib.c
#OBJ = $(SRC:.c=.o)
OBJ = dll_lib.o

all: $(TARGET)
#all: libdll_lib.so$

$(TARGET): $(OBJ)
	   $(CC) $(LDFLAGS) -o  $@ $^
#$(TARGET): dll_lib.o
#	   gcc -shared -o  libdll_lib.so dll_lib.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
#%.o: %.c
#	gcc -fPIC -Wall -Wextra -O2 -c dll_lib.c -o dll_lib.o

clean:
	rm -rf $(OBJ) $(TARGET)
