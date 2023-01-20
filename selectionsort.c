#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void printarray(int a[], int n);
void selectionsort(int a[], int n);

void main()
{
    int n;
    printf("Enter the size of your Array: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the Element %d from array: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("Array Before Callinf SelectionSort Function\n");
    printarray(a, n);
    printf("Array After calling SelectionSort Function\n");
    selectionsort(a, n);
    printarray(a, n);
    getch();
}

void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void selectionsort(int a[], int n)
{
    int indexconsidermin, i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        indexconsidermin = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[indexconsidermin])
            
            {
                indexconsidermin = j;
            }
        }
        temp = a[i];
        a[i] = a[indexconsidermin];
        a[indexconsidermin] = temp;
    }
}
