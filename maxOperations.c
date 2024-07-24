#include <stdlib.h>

int compare(void *value1, void *value2)
{
    int valueInt1;
    int valueInt2;

    valueInt1 = *((int *)value1);
    valueInt2 = *((int *)value2);

    return (valueInt1 - valueInt2);
}

int maxOperations(int* nums, int numsSize, int k){

    int start;
    int end;
    int sum;
    int operations;

    qsort(nums, numsSize, sizeof(int), compare);

    start = 0;
    end = numsSize - 1;

    sum = 0;
    operations = 0;
    while(start < end)
    {
        sum = nums[start] + nums[end];
        if(sum == k)
        {
            start++;
            end--;
            operations++;
        }
        else if(sum < k)
            start++;
        else
            end--;
    }
    return (operations);
}

/* int main(void)
{
    int nums[] = {4,4,1,3,1,3,2,2,5,5,1,5,2,1,2,3,5,4};

    int k = 2;

    maxOperations(nums, 18, k);
} */