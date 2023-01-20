#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 10
int st[MAX];
int top = -1;

void push();
int pop();
void display();

void main()
{
    int c;
    c = 0;
    while (c != 4)
    {
        printf("\n*****MENU*****\n");
        printf("Enter your Choice:\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d", &c);
        if(c==1)
        {
            if(top==9)
            {
                printf("stack is full");
            }
            else
            {
                push();
            }
        }    
        else if(c==2)
        {
            if (top == -1)
            {
                printf("Stack is empty");
            }
            else
            {
                pop();
            }
        }
        else if(c==3)
        {
            if (top == -1)
            {
                printf("Stack is Empty");
            }
            else
            {
                display();
            }
        }
        else if(c==4)
        {
            printf("Exited Successfully");
        }
        else
        {
            printf("!!!INVALID Choice!!!");
        }
  
    }  

}
void push()
{
    int x;
    printf("Enter the element to be pushed: ");
    scanf("%d", &x);

    top++;
    st[top] = x;
}

int pop()
{
    int n;

    n = st[top];
    top--;
    printf("The element popped is %d", n);
    return n;
}

void display()
{
    int i;
    i = top;
    for (i = top; i != -1; i--)
    {
        printf("%d\n", st[i]);
    }
}