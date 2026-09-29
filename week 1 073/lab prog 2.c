#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 10
void push(int);
void pop();
void display();
int stack[SIZE],top=-1;
void main()
{
       int value,choice;
       while(1){
        printf("1.push\n2.pop\n3.display\n4.exit\n");
        printf("enter the choice");
        scanf("%d",&choice);
        switch(choice){
           case 1:printf("enter value to insert:");
              scanf("%d",&value);
              push(value);
              break;
            case 2:pop();
              break;
            case 3:display();
              break;
            case 4:exit(0);
            default:printf("\wrong selection");

       }
       }
}
void push(int value)
{
    if(top == SIZE-1)
        printf("stack full");
    else
        top++;
    stack[top]=value;
    printf("insertion success\n");
}
void pop()
{
    if (top==-1)
        printf ("stack empty");
    else
    {
        printf("deleted:%d",stack[top]);
        top--;
    }}
void display()
{
    if (top==-1)
        printf("stack empty");
    else{
        int i;
        printf("stack ele are");
        for (i=top;i>=0;i--)
            printf("%d",stack[i]);
    }
    }






