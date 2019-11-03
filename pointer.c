#include <stdio.h>
#include <string.h>

int* arrayInput(int * , int);
void display(int * , int);
int comparefunction(const void * , const void *);

int main()
{
    int size;
    printf("Enter the size of array: \n");
    scanf("%d", &size);
    int arr[size];
    arrayInput(arr,size);
    display(arr,size);
    qsort(arr,size,sizeof(int),comparefunction);
    display(arr,size);

}

void display(int *numarr , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        printf("%d ",numarr[i]);
    }
    printf("\n");
}

int* arrayInput(int *arr, int size)
{
    for(int i = 0 ; i<size ; i++)
    {
        scanf("%d",&arr[i]);
    }
    return arr;
}

int comparefunction(const void *a , const void *b)
{
    return(*(int*)a - *(int*)b);
}