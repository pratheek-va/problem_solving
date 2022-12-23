#include <stdio.h>

int need[10][10], allocation[10][10], available[10], max[10][10], n, r;

struct process
{
    int finish;
    int index;
} process[20];

void input()
{
    printf("Enter the number of resources: \n");
    scanf("%d", &r);
    printf("Enter the number or process:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        process[i].finish = 0;
        process[i].index = i;
    }
    printf("Enter the max demand of matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
            scanf("%d", &max[i][j]);
    }

    printf("Enter the allocation matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
            scanf("%d", &allocation[i][j]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
            need[i][j] = max[i][j] - allocation[i][j];
    }

    printf("Enter the available resources: \n");
    for (int i = 0; i < r; i++)
        scanf("%d", &available[i]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
}

int checkSafety()
{
    int i = 0, j = 0, count = 0;
    int work[10];

    for (int i = 0; i < r; i++)
        work[i] = available[i];

    printf("The safety sequence is:>");
    while (1)
    {
        count++;
        int index = process[i].index;

        if (process[index].finish == 0)
        {
            for (j = 0; j < r; j++)
            {
                if (need[index][j] > work[j])
                    break;
            }
            if (j == r)
            {
                process[index].finish = 1;
                printf("P%d ", i);
                for (int k = 0; k < r; k++)
                {
                    work[k] = work[k] + need[index][k];
                }
            }
            i = ++i % n;
            for (j = 0; j < n; j++)
            {
                if (process[j].finish == 0)
                    break;
            }
            if (j == n)
            {
                printf("System is safer");
                return 1;
            }
            if (count > 100)
            {
                printf("Deadlock can occur");
                return 0;
            }
        }
        else
            i++;
    }
}

void newRequest()
{
    int index = 0, request[10], i = 0;

    printf("Enter the process index: \n");
    scanf("%d", &index);

    for (int i = 0; i < r; i++)
        scanf("%d", &request[i]);

    for (i = 0; i < r; i++)
        if (request[i] > available[i])
        {
            break;
        }
    if (i == r)
    {
        for (int j = 0; j < n; j++)
        {
            allocation[index][j] = allocation[index][j] + request[j];
            need[index][j] -= request[j];
            available[j] -= request[j];
        }
        if (checkSafety)
            printf("Resources can be allocated");
        else
            printf("Resources cannot be allocated");
    }
    else
        printf("Resource request is not granted.");
}

int main()
{
    input();
    checkSafety();
    newRequest();
}