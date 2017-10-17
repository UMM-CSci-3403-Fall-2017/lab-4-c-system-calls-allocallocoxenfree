#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 4

bool is_vowel(char c) { 
    /* 
     * Returns true if c is a vowel (upper or lower case), and 
     * false otherwise. 
     */
	if ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') == 1) {
		return true;
	}

	return false;     
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    /*
     * Copy all the non-vowels from in_buf to out_buf. 
     * num_chars indicates how many characters are in in_buf, 
     * and this function should return the number of non-vowels that
     * that were copied over.
     */
	int counter = 0;
	for (int i = 0; i < num_chars; i++)
	{
		if(in_buf[i + 1] == '\0' || in_buf[i + 1] == EOF){
		//	printf("it has a null terminator at: \n");
		//	printf("%d\n", i);
			break;
		}
		if (!is_vowel(in_buf[i]))
		{
		//	printf("%c\n",in_buf[i]);
			out_buf[counter] = in_buf[i];
			counter++;
		}	
	}
//	out_buf[counter] = '\0';
	return counter;
}

void disemvowel(FILE* inputFile, FILE* outputFile) { 
    /*
     * Copy all the non-vowels from inputFile to outputFile.
     * Create input and output buffers, and use fread() to repeatedly read
     * in a buffer of data, copy the non-vowels to the output buffer, and
     * use fwrite to write that out. 
     */

	//buffer arrays
	char buffer[BUF_SIZE];
	char buffer2[BUF_SIZE];

	//2 cases, with an output file and without an output file
	if(inputFile && outputFile) {
		//takes chunks of data and disemvowels them all seperately before writing them to the output file
		while(fread(buffer,1,BUF_SIZE,inputFile) == BUF_SIZE) {
			int final_size = copy_non_vowels(sizeof(buffer),buffer,buffer2);
			fwrite(buffer2, 1, final_size, outputFile);
		}
	} else {
		//takes chunks of data and disemvowels them all seperately before outputing them in standard out
		while(fread(buffer,1,BUF_SIZE,inputFile) == BUF_SIZE) {
			int final_size = copy_non_vowels(sizeof(buffer),buffer,buffer2);
			fwrite(buffer2,1,final_size,stdout);
		}
	}
}

int main(int argc, char *argv[]) { 	    

    // Code that processes the command line arguments 
    // and sets up inputFile and outputFile.

    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile;
    //if there is a specified output file
    if(argc == 3){
	    outputFile = fopen(argv[2], "w+");
    }

    //2 cases, with an input file and without an input file (takes from standard in if without input)
    if(inputFile){
    	disemvowel(inputFile, outputFile);
    } else {
	disemvowel(stdin, outputFile);
    }
    if(inputFile) fclose(inputFile);
    if(outputFile) fclose(outputFile);

    return 0; 
}
