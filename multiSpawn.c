/* 
File is multiSpawn.c

Purpose:
a program that checks if the first 10 unsigned integers within a binary file are prime numbers
by spawning multiple child processes

input:
a binary file containing integers entered via the command line parameters.  For example multiSpawn prime.bin

output:
print statements declaring which numbers are prime and which are not

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
		int primeArray[10];
		pid_t childProcessIds[10];
		unsigned int intList[10];
		fread(intList, sizeof(unsigned int), 10, file);
		
		for(int i=0; i<10; i++) {
			pid_t cpid = fork();
			char buffer[40];
			sprintf(buffer, "%u" ,intList[i]);
		
			if (cpid == 0) 
				// child process instructions
				morph(buffer);
			else {
				// parent process instructions
				childProcessIds[i] = cpid;
				//printf("%s corresponds with %d\n", buffer, childProcessIds[i]);
			}
		}
		int i=0;
		while (i!=10) {
			int status = 100;
			pid_t responded = waitpid(-1, &status, 0);
			
			for (int j=0; j<10; j++) {
				if (responded == childProcessIds[j] && WIFSIGNALED(responded) != 0) {
					primeArray[j] = status;
					i++;
				}
			}		
		}
		for(i=0; i<10; i++) {
			if(primeArray[i] == 256) 
				printf("%u is a prime number\n", intList[i]);
			else
				printf("%u is NOT a prime number\n", intList[i]);
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












