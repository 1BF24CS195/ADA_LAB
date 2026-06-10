#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int a[],int low, int high){
    int pivot=a[low];
    int i=low+1;
    int j=high;
    int temp;

    while(1){
        while(i<=high && a[i]<=pivot)
            i++;
        while(j >= low && a[j]>pivot)
            j--;
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else
            break;
    }
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;

    return j;
}

int quicksort(int a[],int low, int high){
    if(low<high){
        int j=partition(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}

int main()
{
    int i, j;
    clock_t start, end;
    double time_taken;
    int *a = (int *)malloc(5000000 * sizeof(int));

    srand(time(0));

    printf("n\tExecution Time (s)\n");
    printf("------------------------\n");

    for(i = 100000; i <= 500000; i += 100000)
    {
        for(j = 0; j < i; j++)
            a[j] = rand();

        start = clock();
        quicksort(a, 0, i - 1);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("%d\t%.7f\n", i, time_taken);
    }
    free(a);
    return 0;
}
