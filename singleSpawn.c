/* 
File is singleSpawn.c

Purpose:
a program that checks if the first unsigned integer within a binary file is a prime number by spawning 
a child process

input:
a binary file containing integers entered via the command line parameters.  For example multiSpawn prime.bin

output:
print statement declaring whether the number is prime or not

Assumption:
the program does not check if the number is a positive integer

*/ 

/**************************************************************/
// INCLUDE FILES
//
#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*************************************************************/
// PROTOTYPES
//
int morph(char *number);


/*************************************************************/



int main(int argc, char* argv[]){
	
	int status;
	int exitStatus;
	FILE *file = fopen(argv[1], "rb");
	
	if (argc < 2) { // file name not provided in command line
		printf("Usage: singlePrime fileName.\n");
		return(1);
	}
	
	if (file == NULL) { // file does not exist
		printf("file %s does not exist", argv[1]);
		return(1);
	}
	
	printf("please wait...\n\n");
	if (file != NULL) {
		
		pid_t pid = fork();
		unsigned int firstInt;
		char buffer[40];
		fread(&firstInt, sizeof(unsigned int), 1, file);
		sprintf(buffer, "%u", firstInt);
		
		if (pid == 0) {
			// child process instructions
			morph(buffer);
		}
		else {
			// parent process instructions
			while (wait(&status) > 0) { /* wait for child processes */}
			
			exitStatus = WEXITSTATUS(status);
			if (exitStatus == 1) 
				printf("%s is a prime number\n", buffer);
			else if(exitStatus == 0)
				printf("%s is NOT a prime number\n", buffer);
			else 
				printf("Error. No number included in command line parameter\n");
		}
	}
}	


/*************************************************************/
/*
Purpose: morphs a string to the isPrime program
input: a number stored as a string

return: -1 if the morph failed
*/ 

int morph(char *number)
{
	unsigned int result;
	char *fileName = "./isPrime";
	char *isPrimeParam[3] = {
		"isPrime",
		number
	};
	result = execvp(fileName, isPrimeParam);
}













