#include <stdio.h>
#include <jansson.h>
#include <string.h>

int comp(const void* , const void*);

int main()
{
    int n;
    int* ptr , *newptr;
    char* s = NULL;
    json_t* json_arr = json_array();
    json_t* sorted_json_arr = json_array();
    json_t* original = json_object();
    json_t* sorted = json_object();
    json_t* value;
    json_object_set_new(original,"Original",json_arr);
    
    printf("Enter number of Elements: \n");
    scanf("%d",&n);

    ptr = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n ; ++i)
    {
        scanf("%d",ptr + i);
    }

    for(int i = 0 ; i < n ; i++)
    {
        json_array_append(json_arr,json_integer(*(ptr + i)));
    }
    s=json_dumps(original,0);
    puts(s);

    void* iter = json_object_iter(original);
    while(iter)
    {
        value = json_object_iter_value(iter);
        iter = json_object_iter_next(original,iter);
    }

    char* f = NULL;
    f=json_dumps(value,0);
    puts(f);
    int type = json_typeof(value);
    printf("Type of json Data %d \n",type);
    int newarr[n];
    for(int i = 0 ; i<n ; ++i)
    {
        newarr[i] =  json_integer_value(json_array_get(value,i));
    }

    qsort(newarr,n,sizeof(int),comp);

    for(int i = 0 ; i < n ; i++)
    {
        json_array_append(sorted_json_arr,json_integer(newarr[i]));
    }
    
    json_object_set_new(original,"Sorted",sorted_json_arr);

    f=json_dumps(original,0);
    puts(f);
    FILE* output;
    output = fopen("jsonMain.json","w+");
    json_dumpf(original,output,0);

//-------------------------------------------------------------------
    return 0;
}

int comp(const void* a, const void* b)
{
    return ( *(int*)a - *(int*)b );
}