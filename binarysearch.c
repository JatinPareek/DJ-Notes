#include<stdio.h>

int binarysearch(int a[],int ele,int n);

void main()
{
    int n,ele;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
     }
    printf("Enter the element to be searched:");
    scanf("%d",&ele);
    binarysearch(a,ele,n);
}

int binarysearch(int a[],int ele,int n)
{
    int i,j,mid;
    i=0;
    j=n-1;
    mid=(i+j)/2;
    while(a[mid]!=ele && i<j)
    {
        if(a[mid]<ele)
        {
           i=mid+1;
        }
        else{
            j=mid-1;
        }
        mid=(i+j)/2;
    }
    if(a[mid]==ele)
    {
        printf("The element is found at index %d and position %d",mid,mid+1);
        return 1;
    }
    else
    {
        printf("Element is not found");
        return 0;
    }
}