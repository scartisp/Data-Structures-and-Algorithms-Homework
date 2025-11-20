compiler = g++
flags = -Wall -std=c++17
compile = $(compiler) $(flags) -c
link = $(compiler) $(flags)

quicksort.o : quicksort.cc quicksort.h
	$(compile) $<

quicksort : quicksort.o
	$(link) $^ -o $@
	./$@

clean :
	rm *.o quicksort