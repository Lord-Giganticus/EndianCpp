target := EndianCpp

ifeq ($(OS),Windows_NT)
	target := $(addsuffix .dll, $(target))
	else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
		target := $(addsuffix .dylib, $(target))
		else
		target := $(addsuffix .so, $(target))
	endif
endif


all:
	g++ -I include -shared source/*.cpp -o $(target)