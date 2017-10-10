#include <stdio.h>

int main(){
	FILE *fp;

	 fp=fopen("myfile.txt","w+");
	 fwrite("Test\n",6,1,fp);
	 fclose(fp);
	 return(0);
}
