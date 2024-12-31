#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//char *res_keyword[] = {"const","volatile","extern","auto","register","static","signed","unsigned","short","long","double","char","int","float","struct","union","enum","void","typedef"};
//char *res_keyword_non_data[] = {"goto","return","continue","break","if","else","for","while","do","switch","case","default","sizeof","sizeof"};
//char operators[] = {'/','+','*','-','%','=','>','<','~','&',',','!','^','|',':','(',')','[',']'};
//FILE *fptr;
int validate(char **,int);
int parsing(FILE *);
int check_keyword(char *);
int check_operator(char *);
