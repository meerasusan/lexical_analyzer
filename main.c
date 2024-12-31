/*
NAME : MEERA SUSAN TOMMY
DATE :
DISCRIPTION :
SAMPLE INPUT :
SAMPLE OUTPUT :
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "main.h"
//#include<>
//long int last_pos;
FILE *fptr;
int main(int argc,char *argv[])
{
    //vadidation
    if(validate(argv,argc));
    {
    	printf("Open      :  %s  : SUCCSESS \n",argv[1]);
	if(parsing(fptr))
	    printf("Parsing : %s : Done\n",argv[1]);
	else
	    printf("Parsing : Error Failed\n");
    }
    return 0;

}

int validate(char *argv[],int argc)
{
    if(argc == 2)//only one argument
    {
	if(strstr(argv[1],".c"))//extention
	{
		fptr = fopen(argv[1],"r");
		if(fptr)//if fptr not null
		{
		    fseek(fptr,0,SEEK_END);//If file empty,, curser at last
		    //last_pos = ftell(fptr);//last curser pos before EOF
		    if(ftell(fptr))//file not empty
			return 1;
		    else
			printf("ERROR: File is empty\n");
		}
		else
	    	     printf("ERROR: File does not exists\n");//fptr null
	}
	else
	    printf("ERROR: File extention not .c\n");
    }
    else
	printf("ERROR: One argument\n");
    return 0;
}

/*int parsing(FILE *fptr)
{
    printf("Parsing started\n\n");
    fseek(fptr,0,SEEK_SET);//resetting the curser
    char line[80];//error with *line
    //printf("here1\n");
    while(fscanf(fptr,"%[^\n]",line) != EOF)//scanning each line in file
    {
	//printf("her2\n");
	int i=0,j=0,count=0;//i->traverse through line
	//printf("%s\n",line);
	while(line[i])//scanning each character in line
	{
	    //printf("here3\n");
	    //if(line[i] == ' ' || line[i] == '\t')//if space or tab move next
	
	    if(line[i] =='#')//pre-prosessor directive
	    {
		printf("preprocessor directive  : %s\n",line);
		break;
	    }
	    if(line[i] == '{'|| line[i]=='}')
	    {

		count++;
	    }
	    if(line[i] >= 48 && line[i] <= 57)//numeric constant
		printf("numeric constant        : %c\n",line[i]);
	    i++;
	}
    	fseek(fptr,1,SEEK_CUR);
    }
    return 1;
}*/
