#include <stdio.h>
#include <jansson.h>
#include <string.h>


void displayArray(int * , int);

int main()
{
    printf("Hello World\n");
    printf("Jansson Installed\n");

    char *name = "Ritwick";
    int age = 23;
    int n;
    
    printf("%s %d\n",name,age);
    printf("Lenght of name %lu\n",strlen(name));

    printf("Enter n: \n");
    scanf("%d",&n);
    int nums[n];
    for(int i = 0  ; i<n ; i++)
    {
        scanf("%d",&nums[i]);
    }
    displayArray(nums,n);

    return 0;
}

void displayArray(int *numarr, int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        printf("%d ",numarr[i]);
    }
    printf("\n");
}