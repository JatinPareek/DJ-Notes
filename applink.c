#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node
{
    int pow;
    float coeff;
    struct node *next;
} node;

node *head = NULL, *head1 = NULL, *head2 = NULL;
node *P1, *P2, *P3;

node *create(head);
node *display();
void addpoly();

void main()
{
    printf("Enter 1st polynomial:\n");
    P1 = create(head1);
    printf("Enter 2nd Polynomial:\n");
    P2 = create(head2);
    printf("--------------------------\n");
    printf("The Entered Polynomials are:\n");
    display(P1);
    printf("\n");
    display(P2);
    printf("---------------------------\n");
    printf("The Addition of poly nomial is:\n");
    display(P3);
    getch();
}

node *create(head)
{
    node *newnode, *temp;
    int p = 0, c = 0;
    while (p != -1)
    {
        printf("Enter the Power: ");
        scanf("%d", &p);
        if (p != -1)
        {
            printf("Enter the Coeff of %d pow: ", p);
            scanf("%d", &c);
            newnode = (node *)malloc(sizeof(node));
            newnode->pow = p;
            newnode->coeff = c;
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
                temp->next = newnode;
                newnode->next = NULL;
            }
        }
    }
    return head;
}


void addpoly()
{
    
}