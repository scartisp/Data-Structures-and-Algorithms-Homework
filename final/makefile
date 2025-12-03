compiler = g++
flags = -Wall -std=c++17
compile = $(compiler) $(flags) -c
link = $(compiler) $(flags)
TXT_FILES := $(wildcard *.txt)

all: cartis_simion_QuickSort

inputFileGenerator.o : inputFileGenerator.cpp inputFileGenerator.h
	$(compile) $<

cartis_simion_quicksort.o : cartis_simion_quicksort.cpp cartis_simion_quicksort.h
	$(compile) $<

cartis_simion_QuickSort : inputFileGenerator.o cartis_simion_quicksort.o
	$(link) $^ -o $@

clean :
	rm *.o cartis_simion_QuickSort $(TXT_FILES)