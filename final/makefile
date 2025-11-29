compiler = g++
flags = -Wall -std=c++17
compile = $(compiler) $(flags) -c
link = $(compiler) $(flags)
TXT_FILES := $(wildcard *_randomNumbers_*.txt)

all: quicksort

cartis_simion_quicksort.o : cartis_simion_quicksort.cc cartis_simion_quicksort.h
	$(compile) $<

inputFileGenerator.o : inputFileGenerator.cc inputFileGenerator.h
	$(compile) $<

quicksort : cartis_simion_quicksort.o inputFileGenerator.o
	$(link) $^ -o $@
	./$@

clean :
	rm *.o quicksort $(TXT_FILES)