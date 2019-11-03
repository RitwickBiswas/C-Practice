#include <stdio.h>
#include <string.h>
#include <jansson.h>

void disp(int * , int);
int compare(int* , int*);

int main()
{
    char *s =NULL;
    char *f =NULL;
    json_t *json_arr = json_array();
    json_t *root  =json_object();
    int n;

    printf("Enter N :\n");
    scanf("%d",&n);
    int num[n];
    json_object_set_new(root,"data",json_arr);
    for(int i = 0 ; i<n ; i++)
    {
        scanf("%d",&num[i]);
    }
    disp(num,n);
    for(int i = 0 ; i < n ; i++)
    {
        json_array_append(json_arr , json_integer(num[i]));
    }
    s=json_dumps(root,0);
    printf("Array before sorting");
    puts(s);
    printf("Array after sorting");
    puts(s);
    json_decref(root); 



    return 0;
}

void disp(int *numarr , int size)
{
    for(int i = 0 ; i < size; i++)
    {
        printf("%d ",numarr[i]);
    }
    printf("\n");
}

int compare(int* x , int* y)
{
    return *x - *y;
}