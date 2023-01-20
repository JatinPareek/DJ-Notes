#include <stdio.h>
#include <stdlib.h>

void printArray(int a[], int n);
int partition(int a[],int low,int high);
void quicksort(int a[],int low,int high);

int partition(int a[],int low,int high)
{
    int pivot = a[low];
    int i = low +1;
    int j=high;
    do
    {
        while(a[i]<=pivot)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    } while (i<j);
    int temp=a[low];
     a[low]=a[j];
     a[j]=temp;
     return j;
    
}

void quicksort(int a[],int low,int high)
{
    int p;
    if(low<high)
    {
        p=partition(a,low,high);
        quicksort(a,low,p-1);
        quicksort(a,p+1,high);
    }
}

void printArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    // printf("\n");
}

void main()
{
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printArray(a,n);
    printf("\n");
    quicksort(a,0,n-1);
    printArray(a,n);
}