#include<stdio.h>

//Defininig the functions below
int linearsearch(int a[],int ele,int n);
int binarysearch(int a[],int ele, int n);
int main()
{
    int n,ele,i;
    int a[20];
   
    printf("Enter size of the list: ");
    scanf("%d",&n);
    
    printf("Enter %d elements in the list\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d",&ele);
    printf("LINEAR SEARCH\n");
    linearsearch(a, ele,n);
    printf("BINARY SEARCH\n");
    binarysearch(a,ele,n);
    return 0;

}

int linearsearch(int a[],int ele,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==ele)
        {
            printf("The element is found at position %d\n",i+1);
        }
    }
    return 0;
}


int binarysearch(int a[],int ele,int n)
{
    int mid,i,j;
    i=0;
    j=n-1;
    mid=(i+j)/2;
    while(a[mid]!=ele && i<j)
    {
        if(a[mid]>ele)
        {
            j=mid-1;
        }
        else
        {
            i=mid+1;
        }
        mid=(i+j)/2;
    }
    if(a[mid]==ele)
    {
        printf("Element is found\n");
        printf("At Position: %d",mid+1);
        return 1;
    }
    else
    {
        printf("Element Not Found\n");
        return 0;
    }
}
