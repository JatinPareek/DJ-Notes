#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *top;

void push(); // it can also be void push(int n); if the user knows the size of stack
void pop();
void display();

void main()
{
    int choice;
    choice = 0;
    while (choice != 4)
    {
        printf("\n--------------MENU----------------\n");
        printf("Select Your Option\n");
        printf("1.Push.\n2.Pop.\n3.Display.\n4.Exit.\n");
        printf("Enter Your Option: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // int n;
            // printf("Enter the no. of elements you want to push: ");
            // scanf("%d", &n);
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exited Successfully\nThanks.\n");
            break;
        default:
            printf("Not a Valid Option\n");
            break;
        }
    }
    getch();
}

void push() // it can also be void push(int n);
{

    int val;
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("Enter the element to be pushed: ");
    scanf("%d", &val);
    newnode->data = val;
    if (newnode == NULL)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        if (top == NULL)
        {
            newnode->next = NULL;
            top = newnode;
        }
        else
        {
            newnode->next = top;
            top = newnode;
        }
    }

    printf("Element Pushed\n");
}

void pop()
{
    int val;
    val=0;
    node *delnode;
    if (top == NULL)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        val = top->data;
        delnode = top;
        top = delnode->next;
        free(delnode);
        printf("Element Popped is %d\n", val);
    }
    
}

void display()
{
    node *temp;

    if (top == NULL)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        temp = top;
        
        while (temp->next != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}