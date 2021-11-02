#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int i=0;
char ch[100];
/*
 Production:
  E->TE'
  E'->+TE'/@
  T->FT'
  T'->*FT'/@
  F->a/@
*/
void E()
{
    printf("E->TE'\n");
    T();
    Eprime();
}

void Eprime()
{
    if(ch[i] == '+')
    {
        i++;
        printf("E'->+TE'\n");   
        T();
        Eprime();
    }
    else
    {
        printf("E'->@\n");
    }
}

void T()
{
    printf("T->FT'\n");
    F();
    Tprime();
}

void Tprime()
{

    if(ch[i] == '*')
    {
        i++;
        printf("T'->*FT'\n");
        F();
        Tprime();
    }
    else
    {
        printf("T'->@\n");
    }
}

void F()
{
    if(ch[i]=='a')
    {
        i++;
        printf("F->a\n");
    }
    else
    {
        printf("F->@\n");
    }
}
void main()
{
    printf("enter the string\n");
    gets(ch);
    printf("\nProduction set are:\n");
    E();
    if(strlen(ch)==i)
    {
        printf("\nstring is accepted");
    }
    else
    {
        printf("\nstring is not accepted");
    }
}