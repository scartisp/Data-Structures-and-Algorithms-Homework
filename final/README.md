# Data Structures and algorithms final project: quicksort time efficency

this project implements and measures the time efficiency of quicksort using the median-of-three method by reading from file(s) containing unsorted floating point numbers, sorting the numbers using quicksort, and creating an output file containing the sorted numbers. Additionally, a file containing the exeuction time is created. all input and output files are .txt ASCII plain text.

The example will generate 25 .txt files for each input size; 10, 100, 1000 (75 input .txt files in total). The files will contain random, unsorted floating point numbers ranging from -100 to 100 and are seperated by a space.

the example will produce a .txt file with the numbers sorted for each given input (75 sorted .txt file) as well as "cartis_simion_executionTime.txt", which contains the execution time of quicksort for each file, and "cartis_simion_averageExecutionTime.txt" which contains the average execution time for each input size.

You can also give the program a pre-made .txt file containing numbers seperated by a space and specify your desired .txt output file.

# environment: 

this project was tested on the Ubuntu WSL and on the USC Molinaroli College of Engineering Linux machines.

# make instructions
run all make instructions in a terminal

make all: 
creates the executable cartis_simion_QuickSort.

make clean:
deletes the executable cartis_simion_QuickSort, all object files, and all .txt files

# how to run
once you run "make all", you will have the executable cartis_simion_QuickSort.

To run the example file, simply write "./cartis_simion_QuickSort" inside of your terminal

To run the program with a pre-made input .txt file, in addition to the above execution command (./cartis_simion_QuickSort), include the name of your desired input file, followed by the name of your desired output file. each part should be seperated by a space.

example execution with pre-made file:
./cartis_simion_QuickSort input.txt output.txt

# Writen by: Simion Cartis