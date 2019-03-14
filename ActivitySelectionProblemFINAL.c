#include<stdio.h>
#include<stdlib.h>

typedef struct      // STRUCTURE OF EACH ACTIVITY
{
    int activity_no;
    int start_time;
    int finish_time;
}node;

void heapify(node *arr , int n , int p);
void heap_sort(node *arr , int n);
void greedy_actitvity_selector(node *, int, int*, int *r);

void heapify(node arr[] , int n , int p)
{
    int gt=p;
    int lc = 2*p+1;
    int rc = 2*p+2;
    if(lc<n && arr[lc].finish_time>arr[gt].finish_time)
        gt=lc;
    if(rc<n && arr[rc].finish_time>arr[gt].finish_time)
        gt=rc;
    if(gt!=p)
    {
        node temp = arr[p];
        arr[p]= arr[gt];
        arr[gt] = temp;
        heapify(arr,n,gt);
    }
}
void heap_sort(node arr[] , int n) // USING HEAP SORT TO SORT SET OF ACTIVITIES ACCORDING TO THEIR FINISH TIME
{
    int i;
    for(i=(n+1)/2;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    int cs=n;
    while(cs>1)
    {
        node temp = arr[0];
        arr[0]= arr[cs-1];
        arr[cs-1] = temp;
        cs--;
        heapify(arr,cs,0);
    }
}
void greedy_actitvity_selector(node arr[], int n , int result[], int *result_size)  // GREEDY ACTIVITY SELECTOR ALGORITHM
{
    int i;
    int k =0;
    result[0] = 0;
    (*result_size)++;
    for(i=1;i<n;i++)
    {
        if(arr[i].start_time>=arr[k].finish_time)
        {
            ++(*result_size);
            result[(*result_size)]=i;
            k=i;
        }

    }
}

int main()
{
    int i,n;
    printf("ENTER NUMBER OF ACTIVITIES\n");
    scanf("%d",&n);
    node  * arr = (node *)malloc(n * sizeof(node));
    int  * result = (int *)malloc(n * sizeof(int)); // SET OF COMPATIBLE ACTIVITIES
    int result_size = -1;
    printf("ENTER START TIME AND FINISH TIME OF EACH ACTIVITY\n");
    for(i=0;i<n;i++)
    {
        arr[i].activity_no=i+1;
        printf("ACTIVITY NUMBER : %d",arr[i].activity_no);
        printf("\nSTART TIME: ");
        scanf("%d",&arr[i].start_time);
        printf("END TIME: ");
        scanf("%d",&arr[i].finish_time);
    }
    heap_sort(arr,n);

    greedy_actitvity_selector(arr,n,result,&result_size);

    printf("RESULTANT SET OF COMPATIBLE ACTIVITIES\n");
    for(i=0;i<=result_size;i++)
    {
        printf("[%d] ",result[i]+1);
    }

    return 0;
}
