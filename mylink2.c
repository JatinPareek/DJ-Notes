#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next, *rear;
} node;

node *head = NULL;

void create();
void InsertatBegin();
void InsertatEnd();
void InsertatSpecified();
void Display();
void Displayrev();
void DeleteEnd();
void deleteBegin();
void DeleteSpecified();

void main()
{
    int choice;
    choice = 0;
    while (choice != 10)
    {
        printf("\n_________________MENU_________________\n");
        printf("1.Create\n2.InsertatBegin\n3.InsertatEnd\n4.InsertatSpecidied\n5.Display\n6.DisplayReverse\n7.DeleteEnd\n8.deleteBegin\n9.DeleteSpecified\n10.Exit.\n");
        printf("Enter Your Choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            create();
            break;
        case 2:
            InsertatBegin();
            break;
        case 3:
            InsertatEnd();
            break;
        case 4:
            InsertatSpecified();
            break;
        case 5:
            Display();
            break;
        case 6:
            Displayrev();
            break;
        case 7:
            DeleteEnd();
            break;
        case 8:
            deleteBegin();
            break;
        case 9:
            DeleteSpecified();
            break;
        case 10:
            printf("!!Exited Successfully!!\nThanks\n");
            break;
        }
    }
    getch();
}

void create()
{
    int n, value;
    node *newnode, *temp;
    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data: ");
        scanf("%d", &value);
        newnode = (node *)malloc(sizeof(node));
        newnode->data = value;
        if (head == NULL)
        {
            newnode->next = NULL;
            newnode->rear = NULL;
            head = newnode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = NULL;
            newnode->rear = temp;
        }
        printf("NODE INSERTED\n");
    }
}

void InsertatEnd()
{
    int value;
    node *newnode, *temp;
    printf("Enter the data: ");
    scanf("%d", &value);
    newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    if (head == NULL)
    {
        newnode->rear = NULL;
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->rear = temp;
    }
    printf("NODE IS INSERTED AT END\n");
}

void InsertatBegin()
{
    int value;
    printf("Enter the data: ");
    scanf("%d", &value);
    node *newnode, *temp;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    newnode->rear = NULL;
    if (head == NULL)
    {
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head->rear = newnode;
        head = newnode;
    }
    printf("NODE IS INSERTED AT BEGIN\n");
}

void InsertatSpecified()
{
    int value, loc;
    printf("Enter the data: ");
    scanf("%d", &value);
    printf("Enter the location after which you want to insert: ");
    scanf("%d", &loc);
    node *newnode, *temp;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    if (head == NULL)
    {
        newnode->next = NULL;
        newnode->rear = NULL;
        head = newnode;
    }
    else
    {
        temp = head;
        for (int i = 0; i < loc - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next->rear = newnode;
        newnode->rear = temp;
        temp->next = newnode;
    }
    printf("NODE INSERTED AT SPECIFIED LOCATION\n");
}

void Display()
{
    node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("!!List is Empty!!\n");
    }
    else
    {
        while (temp->next != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d -> NULL", temp->data);
    }
}

void Displayrev()
{
    node *temp, *rev;
    temp = head;
    if (head == NULL)
    {
        printf("!!List is Empty!!\n");
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        rev = temp;
        while (rev->rear != NULL)
        {
            printf("%d->", rev->data);
            rev = rev->rear;
        }
        printf("%d->NULL", rev->data);
    }
}

void deleteBegin()
{
    node *temp1;
    temp1 = head;
    if (head == NULL)
    {
        printf("List Is Empty\nDeletion Not Possible.\n");
    }
    else
    {
        if (temp1->next == temp1->rear)
        {
            head = NULL;
            free(temp1);
            printf("NODE DELETED AT BEGIN\n");
        }
        else
        {
            head = temp1->next;
            head->rear = NULL;
            temp1->next = NULL;
            free(temp1);
            printf("NODE DELETED AT BEGIN\n");
        }
    }
}

void DeleteEnd()
{
    node *temp1, *temp2;
    temp1 = head;
    if (head == NULL)
    {
        printf("List Is Empty\nDeletion Not Possible.\n");
    }
    else
    {
        if (temp1->next == NULL && temp1->rear == NULL)
        {
            head = NULL;
            free(temp1);
            printf("NODE DELETED AT END\n");
        }
        while (temp1->next != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = NULL;
        temp1->rear = NULL;
        free(temp1);
        printf("NODE DELETED AT END\n");
    }
}

void DeleteSpecified()
{
    int value;
    node *temp1, *temp2;
    temp1 = head;
    if (head == NULL)
    {
        printf("List Is Empty\nDeletion Not Possible.\n");
    }
    else
    {
        printf("Enter the data of node which you want to delete: ");
        scanf("%d", &value);
        if (temp1->data == value && temp1->rear == NULL)
            {
                head = temp1->next;
                head->rear = NULL;
                temp1->next = NULL;
                free(temp1);
                printf("NODE DELETED AS SPECIFIED\n");
            }
            else (temp1->data == value && temp1->next == NULL)
            {
               
            }
        while (temp1->data != value)
        {
            temp2 = temp1;
            

            temp1 = temp1->next;
        }
        temp2->next = temp1->next;
        temp1->next->rear = temp2;
        temp1->rear = NULL;
        temp1->next = NULL;
        free(temp1);
        printf("NODE DELETED AS SPECIFIED\n");
    }
}