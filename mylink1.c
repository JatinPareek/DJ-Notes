#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

void create();
void InsertatBegin();
void InsertatEnd();
void InsertatSpecified();
void Display();
void DeleteEnd();
void deleteBegin();
void DeleteSpecified();
void sortedlist();

void main()
{
    int choice;
    choice = 0;
    while (choice != 10)
    {
        printf("\n_________________MENU_________________\n");
        printf("1.Create\n2.InsertatBegin\n3.InsertatEnd\n4.InsertatSpecidied\n5.Display\n6.DeleteEnd\n7.deleteBegin\n8.DeleteSpecified\n9.Sortedlist\n10.Exit\n");
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
            DeleteEnd();
            break;
        case 7:
            deleteBegin();
            break;
        case 8:
            DeleteSpecified();
            break;
        case 9:
            sortedlist();
            break;
        case 10:
            printf("Exited Successfully\n");
            printf("THANKS\n");
            break;
        default:
            printf("Please Select Valid Option\n");
            break;
        }
    }
    getch();
}

void create()
{
    int value;
    node *newnode, *temp;
    printf("Enter Number of Nodes to create: ");
    scanf("%d", &value);
    for (int i = 0; i < value; i++)
    {
        newnode = (node *)malloc(sizeof(node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        if (head == NULL)
        {
            newnode->next = NULL;
            head = newnode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            newnode->next = NULL;
            temp->next = newnode;
        }
        printf("NODE INSERTED\n");
    }
}
void sortedlist()
{
    node *newnode, *temp, *p;
    int val;
    printf("Enter the data:");
    scanf("%d", &val);
    newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    if (head == NULL)
    {
        head = newnode;
    }
    temp = head;
    if (temp->data > newnode->data)
    {
        newnode->next = head;
        head = newnode;
    }
    while (temp->data < newnode->data && temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
}

void InsertatEnd()
{
    int value;
    node *newnode, *temp;
    printf("Enter the Data: ");
    scanf("%d", &value);
    newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    if (head == NULL)
    {
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newnode->next = NULL;
        temp->next = newnode;
    }
    printf("NODE INSERTED AT END\n");
}

void InsertatBegin()
{
    int value;
    printf("Enter the data: ");
    scanf("%d", &value);
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    if (head == NULL)
    {
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
    printf("NODE INSERTED AT BEGIN\n");
}

void InsertatSpecified()
{
    int value;
    printf("Enter the data: ");
    scanf("%d", &value);
    node *newnode, *temp;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    int loc;
    printf("Enter the location after which you want to insert: ");
    scanf("%d", &loc);
    if (head == NULL)
    {
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        temp = head;
        for (int i = 0; i < loc; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    printf("NODE INSERTED AT SPECIFIED LOCATION\n");
}

void Display()
{
    node *temp;
    if (head == NULL)
    {
        printf("!!LIST IS EMPTYY!!\n");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("%d\tNULL", temp->data);
    }
}

void deleteBegin()
{
    node *temp;
    if (head == NULL)
    {
        printf("LIST IS EMPTY\n");
        printf("Deletion Not Possible\n");
    }
    else
    {
        temp = head;
        if (temp->next == NULL)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            head = temp->next;
            free(temp);
            printf("DELETED THE NODE AT BEGIN\n");
        }
    }
}

void DeleteEnd()
{
    node *temp1, *temp2;
    temp1 = head;
    if (head == NULL)
    {
        printf("LIST IS EMPTY\n");
        printf("Deletion Not Possible\n");
    }
    else
    {
        while (temp1->next != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = NULL;
        free(temp1);
        printf("NODE DELETED AT END\n");
    }
}

void DeleteSpecified()
{
    int value;
    printf("Enter the data of the node which u want to delete: ");
    scanf("%d", &value);
    node *temp1, *temp2;
    if (head == NULL)
    {
        printf("LIST IS EMPTY\n");
        printf("Deletion Not Possible\n");
    }
    else
    {
        temp1 = head;
        while (temp1->data != value)
        {
            if (temp1->next == NULL)
            {
                printf("Node is not found in the list.\nDeletion Not Possible.\n");
            }
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = temp1->next;
        printf("NODE DELETED AS SPECIFIED\n");
    }
}