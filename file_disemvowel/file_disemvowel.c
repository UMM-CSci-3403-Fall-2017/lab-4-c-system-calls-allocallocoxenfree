#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 1024

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
		if(in_buf[i] == '\0'){
			break;
		}
		if (!is_vowel(in_buf[i]))
		{
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


	char buffer[1024];
	char buffer2[1024];

	//possible issue with fread (returns a -1 possibly when done, and that might be printed as well.)
//	if (inputFile && !outputFile) {
//	        fread(buffer, 1, sizeof(buffer), inputFile);
//        	int final_size = copy_non_vowels(sizeof(buffer), buffer, buffer2);
//		fwrite(buffer2, 1, final_size, stdout);
//	}

        if (inputFile && outputFile) {
                printf("aaaaaaaaaaassaw");
		fread(buffer, 1, sizeof(buffer), inputFile);
                int final_size = copy_non_vowels(sizeof(buffer), buffer, buffer2);
                fwrite(buffer2, 1, final_size, outputFile);
        } else {
		fread(buffer, 1, sizeof(buffer), inputFile);
                int final_size = copy_non_vowels(sizeof(buffer), buffer, buffer2);
                fwrite(buffer2, 1, final_size, stdout);
        }


//	fread(buffer,  sizeof(buffer), sizeof(char), inputFile);
//	buffer[sizeof(buffer) -1] = '\0';
//       	printf("%s\n", buffer);	
//	fwrite(buffer, sizeof(buffer), sizeof(char), outputFile);

}

int main(int argc, char *argv[]) { 	    
    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile;
    if(argc == 2){
	    outputFile = fopen(argv[2], "w+");
    }  

    if (!outputFile){
	printf("I'm the conductor of the poop train\n");
    }
    // Code that processes the command line arguments 
    // and sets up inputFile and outputFile.

    if(inputFile){
    	disemvowel(inputFile, outputFile);
    } else {
	disemvowel(stdin, outputFile);
    }
    if(inputFile) fclose(inputFile);
    if(outputFile) fclose(outputFile);

    return 0; 
}
