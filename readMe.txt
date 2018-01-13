Purpose of Software:
	
	These programs determine if unsigned numbers in a binary file are prime numbers 
	in different ways utilizing different methods in each program.

Developer Name and Development Date:
	
	Cameron Hawtin
	December 3/17



Organization:
	The software is organized into 9 seperate files:
	
	-createBinary.c – a program that creates a binary file from a given set of numbers. 
		Assuming that the executable is a.out the usage is: 
		a.out filename num1 num2 etc. where filename is the binary file name, 
		num1 is the first unsigned number num2 is the second unsigned number etc.
	-prime.bin: the binary file containing unsigned numbers.
	-prime.txt: the text file showing what the unsigned numbers are.
	-singlePrime.c: the first main program.	
	-singleSpawn.c: the second main program utilizing a spawned child.	
	-multiSpawn.c: the third main program utilizing multiple spawned children.	
	-MakeFile1.txt: the makefile for singlePrime.
	-MakeFile2.txt: the makefile for singleSpawn.
	-MakeFile3.txt: the makefile for multiSpawn.


Compilation:

	These programs utilize MakeFiles. 	
	Type the following into console:
		
		make -f Makefile1.txt	
		make -f Makefile2.txt
		make -f Makefile3.txt		
	Run programs by typing "singlePrime prime.bin", "singleSpawn prime.bin", or 
	"multiSpawn prime.bin" respectively into console

	PLEASE NOTE: singlePrime will not display results in the console unless compiled with the print statements
	in the "isPrime" function in "isPrime.c" uncommented.

Issues: 
	
	None as far as I am aware other than the note under the compilation section.
	(must recompile singleSpawn with isPrime print statements uncommented)


Software Use:
	
	Compile and run the program. Information should be displayed. 	

