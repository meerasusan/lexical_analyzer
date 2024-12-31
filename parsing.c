/*
NAME : MEERA SUSAN TOMMY
DATE :
DISCRIPTION :
SAMPLE INPUT :
SAMPLE OUTPUT :
*/
#include<stdio.h>
#include<ctype.h>
#include"main.h"
int parsing(FILE *fptr)
{
    printf("Parsing : started\n\n");
    fseek(fptr,0,SEEK_SET);//resetting the curser
    char line[80],word[20],num[10];//error with *line
    //printf("here1\n");
    while(fscanf(fptr,"%[^\n]",line) != EOF)//scanning each line in file
    {
	//printf("her2\n");
	int i=0,j=0,fl_flag=0;//i->traverse through line
	//printf("%s\n",line);
	while(line[i])//scanning each character in line
	{
	    if(line[i] =='#')//pre-prosessor directive #
	    {
		printf("Preprocessor directive  : %s\n",line);
		break;
	    }
	    else if(line[i]==';')// ;
	    {
		printf("End of statement         : ;\n");
	    }
	    else if(line[i] >= 48 && line[i] <= 57 || line[i] == '.')//numeric or floating const
	    {
		//printf("%c\n",line[i]);
		num[j] = line[i];
		j++;
		if(line[i]== '.')
		    fl_flag = 1;
		if(line[i+1] < 48 || line[i+1] >57)//logical error
		{
		    if(line[i+1]!='.')
		    {
		   // printf("here\n");
		    num[j] = '\0';
                    if(fl_flag)
		    	printf("Floating constant        : %s\n",num);
		    else
		    	printf("Integer constant         : %s\n",num);
		    j=0;//reinitialing j;
		    fl_flag =0;
		    //num[0] = '\0';//reinitilising num
		    }
		}
	    }
	    else if(line[i] == '"' || line[i] == 39)//string const || char constant
	    {
		char ch = line[i];
		//if(line[i]==''')
		    //fl_flag =1;
		while(1)//for(j=0;line[i+1] != '"' || line[i+1] != ''';i++,j++)
		{
		    word[j] = line[i];
		    j++; i++;
		    if(line[i] == ch)
		    {
			word[j] = ch ; word[j+1] = '\0';
			if(ch == '"')
			    printf("String constant          : %s\n",word);
			else
			    printf("Character constant       : %s\n",word);
			j=0;//reinitialising j
			break;
		    }
		    //else if(fl_flag && line[i] == ''')
		}
	    }
	    
    	    else if(isalpha(line[i]))//keyword || identifier
	    {
		word[j] = line[i];
		j++;
		if(!isalpha(line[i+1]))
		{
		    word[j] = '\0';
		    if(check_keyword(word))
			printf("Keyword                  : %s\n",word);
		    else
			printf("Identifier               : %s\n",word);
		    j=0;
		}
	    }
	    else if(line[i] != 32 || line[i] != '\t')//operator
	    {
		char arr[3] = {line[i],line[i+1]};
		if(check_operator(arr)==2)
		{
		    printf("Operator                 : %s\n",arr);
		    i++;
		}
		if(check_operator(arr)==1)
		    printf("Operator                 : %c\n",arr[0]);
	    }

	    //Error//

	    i++;
	}
    	fseek(fptr,1,SEEK_CUR);
    }
    return 1;
}
