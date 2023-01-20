#include <stdio.h>
#include <stdlib.h>

void insertionsort(int a[], int n);
void printArray(int a[], int n);

void main()
{

    // int n;
    int i, n;
    printf("Enter the length of array: ");
    scanf("%d", &n);
    // int a[]={12,11,65,43,98,7};
    // int n=6;
    int a[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Array Before calling the fucntion is:\n");
    printArray(a, n);
    printf("CALLING THE INSERTION SORT Function\n");
    printf("Array after calling the function is:\n");
    insertionsort(a, n);
    printArray(a, n);
}
/*void insertionSort(int a[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

// int a[]={12,11,65,43,98,7};

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}*/

void insertionsort(int a[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void printArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}