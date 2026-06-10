#include <stdio.h>

#define MAX 10

void printPerm(int p[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", p[i]);
    printf("\n");
}

int getMobile(int p[], int dir[], int n)
{
    int mobile = 0, pos = -1;

    for(int i = 0; i < n; i++)
    {

        if(dir[i] == 0 && i != 0 && p[i] > p[i-1] && p[i] > mobile)
        {
            mobile = p[i];
            pos = i;
        }

        if(dir[i] == 1 && i != n-1 && p[i] > p[i+1] && p[i] > mobile)
        {
            mobile = p[i];
            pos = i;
        }
    }

    return pos;
}

void johnsonTrotter(int n)
{
    int p[MAX], dir[MAX];

    for(int i = 0; i < n; i++)
    {
        p[i] = i + 1;
        dir[i] = 0;
    }

    printPerm(p, n);

    while(1)
    {
        int pos = getMobile(p, dir, n);

        if(pos == -1)
            break;

        int swapPos;

        if(dir[pos] == 0)
            swapPos = pos - 1;
        else
            swapPos = pos + 1;

        int temp = p[pos];
        p[pos] = p[swapPos];
        p[swapPos] = temp;

        temp = dir[pos];
        dir[pos] = dir[swapPos];
        dir[swapPos] = temp;

        pos = swapPos;

        for(int i = 0; i < n; i++)
        {
            if(p[i] > p[pos])
                dir[i] = 1 - dir[i];
        }

        printPerm(p, n);
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
