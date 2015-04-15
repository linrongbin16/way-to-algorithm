#generate a make file for test

CC=gcc
CPP=g++

HEADS=general_head.h com_locla.h

FLAGS=-Wall
COMPIL=-c

OBJECTS=1_combinatorial_mathematics_introduction.o 2_full_permutation.o 3_combination.o \
	4_permutation_group.o 5_generate_func.o print_status.o test.o

ALL:test.exe

test.exe : $(OBJECTS)
	$(CPP) $(OBJECTS)  -o test.exe

%.o:%.cpp $(HEADS)
	$(CPP) $(COMPIL) $(FLAGS)  $< -o $@

.PHONY:clean

clean:
	del test.exe $(OBJECTS)
