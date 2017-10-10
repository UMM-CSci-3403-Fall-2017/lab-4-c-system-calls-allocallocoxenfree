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
		if (!is_vowel(in_buf[i]))
		{
			out_buf[counter] = in_buf[i];
			counter++;
		}	
	}
	return counter;
}

void disemvowel(FILE* inputFile, FILE* outputFile) { 
    /*
     * Copy all the non-vowels from inputFile to outputFile.
     * Create input and output buffers, and use fread() to repeatedly read
     * in a buffer of data, copy the non-vowels to the output buffer, and
     * use fwrite to write that out. 
     */
//	FILE *fp;

	char buffer[10000];

	//fp = fopen(inputFile, "r");
	fread(buffer, (int) sizeof(char), 10000, inputFile);
	buffer[9999] = '\0';
       	printf("%s\n", buffer);	


}

int main(int argc, char *argv[]) { 	    
    FILE *inputFile = fopen(argv[0], "r"); 
    FILE *outputFile = fopen("test_output.txt", "w");

    // Code that processes the command line arguments 
    // and sets up inputFile and outputFile.

    disemvowel(inputFile, outputFile);

    return 0; 
}
