LIB_DIR = ./lib/build
SAMPLE_DIR = ./sample/build

.PHONY: all
all: build

build:
	cd lib; make all; cp build/libnubo.so ~/libs
	cd sample; make all; cd ..;

.PHONY: clean
clean:
	rm -f $(SAMPLE_DIR)/* $(LIB_DIR)/*
