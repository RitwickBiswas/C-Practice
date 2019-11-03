#include <stdio.h>
#include <jansson.h>
#include <string.h>

int* arrayInput(int* , int);
void display(int* , int);
int comp(const void* , const void*);
json_t* jsonAppend(int* , json_t* , int);


int main()
{
    char* s = NULL;
    char* f = NULL;
    FILE* output;
    json_t* jsonArray = json_array();
    json_t* sortedJsonArray = json_array();
    json_t* root = json_object();
    json_object_set_new(root,"Original",jsonArray);
    int* arr_ptr;
    int* new_arr_ptr;
    int size;
    printf("Enter Number of elements:\n");
    scanf("%d",&size);
    arr_ptr = (int*)malloc(size*sizeof(int));
    new_arr_ptr = (int*)malloc(size*sizeof(int));
    arrayInput(arr_ptr,size);
    display(arr_ptr,size);
    jsonAppend(arr_ptr , jsonArray , size);
    s=json_dumps(root,0);
    puts(s);

    qsort(arr_ptr,size,sizeof(int),comp);
    jsonAppend(arr_ptr, sortedJsonArray , size);
    json_object_set_new(root,"Sorted",sortedJsonArray);
    f = json_dumps(root, 0);
    puts(f);
    output = fopen("jsonMain.json","w+");
    json_dumpf(root,output,0);
    printf("\n");
    free(arr_ptr);
    free(s);
    free(f);
    free(new_arr_ptr);
    json_decref(root);
    json_decref(jsonArray);
    json_decref(sortedJsonArray);
    
    return 0;
}



json_t* jsonAppend(int* arr , json_t* jsonArray , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        json_array_append(jsonArray,json_integer(*(arr + i)));
    }
    return jsonArray;
}

int comp(const void* a, const void* b)
{
    return ( *(int*)a - *(int*)b );
}

void display(int *numarr , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        printf("%d ",*numarr);
        numarr++;
    }
    printf("\n");
}

int* arrayInput(int *arr, int size)
{
    int* temp;
    for(int i = 0 ; i<size ; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    return arr;
}