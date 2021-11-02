#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int keyword(char ch[100])
{
    if(strcmp(ch,"int")==0||strcmp(ch,"float")==0||strcmp(ch,"char")==0||strcmp(ch,"double")==0||strcmp(ch,"bool")==0)
    //add more words to keyword
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int identifer(char ch[100])
{
    int a = 0;
    if(ch[0]>='a'&&ch[0]<='z'||ch[0]>='A'&&ch[0]<='Z')
    {
        a = 1;
        for(int i=1;i<strlen(ch);i++)
        {
            if(ch[i]>='a'&&ch[i]<='z'||ch[i]>='A'&&ch[i]<='Z'||ch[i]>='0'&&ch[i]<='9')
            {
                a = 1;
            }
            else
            {
                a = 0 ;
            }
        }
    }
    if(a==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int operator(char ch[100])
{
    if(strcmp(ch,"+")==0||strcmp(ch,"-")==0||strcmp(ch,"*")==0||strcmp(ch,"/")==0||strcmp(ch,"%")==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int constant(char ch[100])
{
    int a = 0;
    if(ch[0]>='0'&&ch[0]<='9')
    {
        a = 1;
        for(int i=1;i<strlen(ch);i++)
        {
            if(ch[i]>='0'&&ch[i]<='9')
            {
                a = 1;
            }
            else
            {
                a = 0 ;
            }
        }
    }
    if(a==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void main()
{
    FILE *fptr1,*fptr2;
    char ch[100];
    fptr1 = fopen("input.txt","r");
    fptr2 = fopen("output.txt","w");
    int c;
    c = fscanf(fptr1,"%s",ch);
    printf("%d",c);
    while(c != EOF)
    {
        if(keyword(ch)==1)
        {
            fprintf(fptr2,"%s is a keyword\n",ch);
        }
        else if(identifer(ch)==1)
        {
            fprintf(fptr2,"%s is an identifer\n",ch);
        }
        else if(operator(ch)==1)
        {
            fprintf(fptr2,"%s is an operator\n",ch);
        }
        else if(strcmp(ch,";")==0)
        {
            fprintf(fptr2,"%s is a delimiter\n",ch);
        }
        else if(constant(ch)==1)
        {
            fprintf(fptr2,"%s is a constant\n",ch);
        }
        c = fscanf(fptr1,"%s",ch);
    }
    fclose(fptr1);
    fclose(fptr2);
}
