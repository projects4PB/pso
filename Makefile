CC=gcc
CFLAGS=-Wall -g
LDFLAGS=-lgslcblas -lgsl -lm

demo: demo.c pso.c
