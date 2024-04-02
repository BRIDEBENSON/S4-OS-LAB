#include <stdio.h>

int mblock[20];
int msize;

void bestsort()
{
    int temp;
    for (int i = 0; i < msize; i++)
    {
        for (int j = 0; j < msize - i - 1; j++)
        {
            if (mblock[j] > mblock[j + 1])
            {
                temp = mblock[j];
                mblock[j] = mblock[j + 1];
                mblock[j + 1] = temp;
            }
        }
    }
}

int findBestFit(int processSize)
{
    int bestFitIdx = -1;
    int minSizeDiff = 99999;

    for (int i = 0; i < msize; i++)
    {
        if (mblock[i] >= processSize && mblock[i] - processSize < minSizeDiff)
        {
            bestFitIdx = i;
            minSizeDiff = mblock[i] - processSize;
        }
    }

    return bestFitIdx;
}

int main()
{
    int process[20];
    int allocated[20];
    int flag[20];
    int psize;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &msize);
    for (int i = 0; i < msize; i++)
    {
        printf("Enter the size of memory block %d: ", (i + 1));
        scanf("%d", &mblock[i]);
        flag[i] = 0;
    }
    bestsort();
    printf("Enter the number of processes: ");
    scanf("%d", &psize);
    for (int i = 0; i < psize; i++)
    {
        printf("Enter the size of process %d: ", (i + 1));
        scanf("%d", &process[i]);
    }
    for (int i = 0; i < psize; i++)
    {
        int bestFitIdx = findBestFit(process[i]);
        if (bestFitIdx != -1 && flag[bestFitIdx] == 0)
        {
            allocated[bestFitIdx] = i;
            flag[bestFitIdx] = 1;
        }
    }
    printf("BEST FIT\n");
    printf("Block no\t\tBlock size\t\tProcess no\t\tProcess\n");
    for (int i = 0; i < msize; i++)
    {
        if (flag[i] == 1)
            printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n", (i + 1), mblock[i], allocated[i] + 1, process[allocated[i]]);
        else
            printf("%d\t\t\t%d\t\t\tAllocation failed\tAllocation failed\n", (i + 1), mblock[i]);
    }

    return 0;
}
