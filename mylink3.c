#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

void create();
void InsertatBegin();
void InsertatEnd();
// void InsertatSpecified();
void Display();
void deleteBegin();
void DeleteEnd();
void DeleteSpecified();

void main()
{
    int choice;
    choice = 0;
    while (choice != 8)
    {
        printf("\n_________________MENU_________________\n");
        printf("1.Create\n2.InsertatBegin\n3.InsertatEnd\n4.Display\n5.deleteBegin\n6.DeleteEnd\n7.DeleteSpecified\n8.Exit.\n");
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
            Display();
            break;
        case 5:
            deleteBegin();
            break;
        case 6:
            DeleteEnd();
            break;
        case 7:
            DeleteSpecified();
            break;
        case 8:
            printf("!!Exited Successfully!!\nThanks\n");
            break;
        default:
            printf("Invali Option\n");
        }
    }
    getch();
}

void create()
{
    int n, value;
    node *newnode, *temp;
    printf("Enter Number of Nodes to Create: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data: ");
        scanf("%d", &value);
        newnode = (node *)malloc(sizeof(node));
        newnode->data = value;
        if (head == NULL)
        {
            newnode->next = newnode;
            head = newnode;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
        }
        printf("NODE INSERTED\n");
    }
}

void InsertatEnd()
{
    int value;
    printf("Enter the data: ");
    scanf("%d", &value);
    node *newnode, *temp;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    if (head == NULL)
    {
        newnode->next = newnode;
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
    printf("NODE INSERTED AT END\n");
}

void InsertatBegin()
{
    int value;
    printf("Enter the data: ");
    scanf("%d", &value);
    node *newnode, *temp;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    if (head == NULL)
    {
        newnode->next = newnode;
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newnode->next = head;
        head = newnode;
        temp->next = head;
    }
    printf("NODE INSERTED AT BEGIN\n");
}

/*void InsertatSpecified()
{
    int value,loc;
    printf("Enter the data: ");
    scanf("%d",&value);
    node *newnode,*temp;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    printf("Enter the location after which you want to insert: ");
    scanf("%d",&loc);
    if(head==NULL)
    {
        newnode->next=newnode;
        head=newnode;
    }
    else
    {
        temp=head;
        for(int i=0;i<loc;i++)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}*/

void Display()
{
    node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        while (temp->next != head)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}

void deleteBegin()
{
    node *temp1, *temp2;
    temp1 = head;
    if (head == NULL)
    {
        printf("List is Empty\nDeletion Not Possible\n");
    }
    else
    {
        if (temp1->next == head)
        {

            head->next = NULL;
            head = NULL;
            free(temp1);
            printf("Node Deleted\n");
        }
        else
        {

            while (temp1->next != head)
            {
                temp1 = temp1->next;
            }
            temp2 = head;
            head = temp2->next;
            temp1->next = head;
            temp2->next = NULL;
            free(temp2);
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
        printf("List is Empty\nDeletion Not Possible.\n");
    }
    else
    {
        if (temp1->next == head)
        {

            head->next = NULL;
            head = NULL;
            free(temp1);
            printf("Node Deleted\n");
        }
        else
        {
            while (temp1->next != head)
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            temp2->next = temp1->next; // temp2->next=head;
            temp1->next = NULL;
            free(temp1);
            printf("NODE DELETED AT END\n");
        }
    }
}

void DeleteSpecified()
{
    node *temp1, *temp2;
    temp1 = head;
    if (head == NULL)
    {
        printf("List is Empty\nDeletion Not Possible\n");
    }
    else
    {
        int value;
        printf("Enter the data of the node you want to delete: ");
        scanf("%d", &value);
        while (temp1->data != value)
        {
            if (temp1->next == head)
            {
                printf("NOde is not found in the List\nDeletion Not Possible\n");
            }
            else
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }
        }
        temp2->next = temp1->next;
        temp1->next = NULL;
        free(temp1);
        printf("NODE DELETED AS SPECIFIED\n");
    }
}