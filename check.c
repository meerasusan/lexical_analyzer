/*
NAME : MEERA SUSAN TOMMY
DATE :
DISCRIPTION :
SAMPLE INPUT :
SAMPLE OUTPUT :
*/
#include<stdio.h>
#include<string.h>
#include"main.h"
char *res_keyword[] = {"const","volatile","extern","auto","register","static","signed","unsigned","short","long","double","char","int","float","struct","union","enum","void","typedef"};
char *res_keyword_non_data[] = {"goto","return","continue","break","if","else","for","while","do","switch","case","default","sizeof","sizeof"};
char operators[] = {'/','+','*','-','%','=','>','<','~','&',',','!','^','|','?',':','(',')','[',']','}','{'};
char *relational[] = {"++","--","==",">=","<=","!=","!<","!>","+=","-=","=","/="};
int check_keyword(char *word)
{
    for(int j=0;j<19;j++)
	if(strcmp(word,res_keyword[j])==0)
	    return 1;
    
    for(int j=0;j<14;j++)
	if(strcmp(word,res_keyword_non_data[j])==0)
	    return 1;
    
    return 0;

}

int check_operator(char *arr)
{
    for(int j=0;j<12;j++)
	if(strcmp(arr,relational[j])==0)
	    return 2;

    for(int j=0;j<22;j++)
	if(arr[0] == operators[j])
	    return 1;
}
