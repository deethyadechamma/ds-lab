#include<stdio.h>
#include<ctype.h>
#define SIZE 50
char stack[SIZE];
int top=-1;
void push(char elem)
{
    stack[++top]=elem;
}
}

