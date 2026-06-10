#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Merge function
void merge(int a[], int l, int m, int r)
{
    int i=l, j=m+1, k=l, temp[100000];

    while(i<=m && j<=r)
    {
        if(a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i<=m)
        temp[k++] = a[i++];

    while(j<=r)
        temp[k++] = a[j++];

    for(i=l;i<=r;i++)
        a[i] = temp[i];
}

// MergeSort function
void mergesort(int a[], int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;
        mergesort(a, l, m);
        mergesort(a, m+1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    int n, i, j;
    clock_t start, end;
    double time_taken;
    int a[100000];

    printf("n\tExecution Time (s)\n");
    printf("------------------------\n");

    for(i = 10000; i <= 80000; i+=10000)
    {
        for(j = 0; j < i; j++)
            a[j] = rand() % 1000;

        start = clock();
        mergesort(a, 0, i-1);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("%d\t%.6f\n", i, time_taken);
    }

    return 0;
}
