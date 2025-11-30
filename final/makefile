compiler = g++
flags = -Wall -std=c++17
compile = $(compiler) $(flags) -c
link = $(compiler) $(flags)
TXT_FILES := $(wildcard *.txt)

all: quicksort

inputFileGenerator.o : inputFileGenerator.cc inputFileGenerator.h
	$(compile) $<

cartis_simion_quicksort.o : cartis_simion_quicksort.cc cartis_simion_quicksort.h
	$(compile) $<

quicksort : inputFileGenerator.o cartis_simion_quicksort.o
	$(link) $^ -o $@

clean :
	rm *.o quicksort $(TXT_FILES)