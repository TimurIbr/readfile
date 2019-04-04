#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

char *readText(FILE *file)
{
        struct stat tmp;
        fstat(fileno(file), &tmp);
        long int size = tmp.st_size;

        char *bigString = (char *)calloc(size + 1, sizeof(char));
        if((errno != 0) || bigString == nullptr)
                exitErr("Memory cannot be allocated");

        if(fread(bigString, size, 1, file) != 1)
                exitErr("reading error");

        return bigString;
}

char* file_to_string(char* filename){
        FILE *file;
        file = fopen(filename, 'r');
        char* outputstring = readText(file);
}

int main(int ac, char * av[]){
        char * teststring = file_to_string(av[1]);
	//char buff[50];
	
        printf("%s\n", teststring);
        return 0;
}

