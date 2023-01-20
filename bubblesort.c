#include <stdio.h>
#include <conio.h>

void printarray(int a[], int n);
void bubblesort(int a[], int n);

void main()
{
    int n;
    printf("Enter the size of your array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of your array\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element: ");
        scanf("%d", &a[i]);
    }
    printf("Your Array is:\n");
    printarray(a, n); // printing array before sorting
    bubblesort(a, n);
    printf("\n");
    printf("The Sorted Array is:\n");
    printarray(a, n); // printing array after sorting
    getch();
}

void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubblesort(int a[], int n)
{
    int temp, issorted;
    for (int i = 0; i < n - 1; i++) // No. of passes
    {
        printf("Working on pass %d\n", i + 1);

        for (int j = 0; j < n - 1 - i; j++) // comparison in each pass
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        printf("After pass %d\n", i + 1);
        printarray(a, n);
    }
}