#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int queue[10];
int front = -1,rear = -1;
void enqueue();
void dequeue();
void display();
void main()
{
    int i;
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    scanf("%d",&i);
    while(i!=4)
    {
        switch(i)
        {
            case 1: enqueue();
            break;
            case  2: dequeue();
            break;
            case 3: display();
            break;
        }
        printf("Enter menu no.\n");
        scanf("%d",&i);
    }
    printf("Program terminated\n");
    getch();
}
void enqueue()
{
    int n;
    printf("Enter the number:\n");
    scanf("%d",&n);
    if(front==-1)
    {
        front++;
        rear++;
        queue[rear] = n;
    }
    else if((rear+1)%10==front)
{
        printf("Queue is full!\n");
    }
    else
    {
        rear = (rear+10+1)%10;
        queue[rear] = n;
    }
}
void dequeue()
{
    int n;
    if(front==-1)
    {
        printf("Queue is empty!\n");
    }
    else if(front==rear)
    {
        n = queue[front];
        printf("%d is deleted from queue\n",n);
        front = -1;
        rear = -1;
    }
    else
    {
        n = queue[front];
        printf("%d is deleted from queue\n",n);
        front = (front+10+1)%10;
    }
}
void display()
{
    int i;
    i = front;
    printf("Elements present in Queue are\n");
    do
    {
      printf("%d\n",queue[i]);
      i = (i+11)%10;
    }
    while(i!=rear+1);
}
