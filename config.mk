CC := gcc
CFLAGS := -Wall -pedantic
BIN_NAME := mycc
OBJ = $(patsubst %.c,%.o,$(wildcard *.c))
