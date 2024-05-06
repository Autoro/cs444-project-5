CC = gcc
CCOPTS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c)
OBJ = $(SRCS:.c=.o)

.PHONY: testfs test clean pristine

testfs: testfs.o libvvsfs.a
	$(CC) $(CCOPTS) -o $@ $^

libvvsfs.a : image.o block.o
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CCOPTS) -c $^

test: testfs
	@./testfs
	@rm -f test_image.txt

clean:
	rm -f $(OBJ)

pristine: clean
	rm -f testfs libvvsfs.a
