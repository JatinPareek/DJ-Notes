#include <stdio.h>

void mergesort(int a[], int low, int high);
void merge(int a[], int low, int high, int mid);

void printarray(int a[], int n);

void main()
{
    int n;
    printf("Enter the size of your array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of your array\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element No.%d: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("\n");
    int low = 0;
    int high = n - 1;
    printarray(a, n);
    printf("\n");
    mergesort(a, low, high);
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

void mergesort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high)/ 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, high, mid);
    }
}

void merge(int a[], int low, int high, int mid)
{
    int i, j, k, b[100];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for(i=low;i<=high;i++)
    {
        a[i]=b[i];
    }
}