CC = clang
CFLAGS=  -Wall
LIBS = -lnubo -lm -lGL -lglfw -ldl

BD = ./build
NUBO_LIB = ../lib/build
NUBO_LIB_INC = ../lib/include

.PHONY: all
all: clean nubo

nubo: main.c
	$(CC) $(CFLAGS) -L$(NUBO_LIB) -I$(NUBO_LIB_INC) $(LIBS) -o $(BD)/$@ $^

.PHONY: clean
clean:
	rm -f $(BD)/*
