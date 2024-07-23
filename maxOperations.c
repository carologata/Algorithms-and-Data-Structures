
void remove_number(int *nums, int valueI, int valueJ, int *numsSize)
{
    int curr_index;
    int new_index;
    int countI;
    int countJ;

    curr_index = 0;
    new_index = 0;
    countI = 1;
    countJ = 1;
    while(curr_index < *numsSize)
    {
        if(nums[curr_index] == valueI && countI)
            countI--;
        else if(nums[curr_index] == valueJ && countJ)
            countJ--;
        else
        {
            nums[new_index] = nums[curr_index]; 
            new_index++;
        }   
        curr_index++;
    }
    *numsSize = *numsSize - 2;
}

int maxOperations(int* nums, int numsSize, int k)
{

    int i;
    int j;
    int element;
    int operations;

    i = 0;
    element = 0;
    operations = 0;
    while(i < numsSize)
    {
        element = k - nums[i];
        j = i + 1;
        while(j < numsSize)
        {
            if(nums[j] == element)
            {
                remove_number(nums, nums[i], nums[j], &numsSize);
                operations++;
                i = -1;
                break ;
            }
            j++;
        }
        i++;
    }
    return (operations);
}

#include <stdlib.h>

int main(void)
{
    int *nums = malloc(5 * sizeof(int));
    nums[0] = 3;
    nums[1] = 1;
    nums[2] = 3,
    nums[3] = 4;
    nums[4] = 3; 
    int k = 6;

    maxOperations(nums, 5, k);
}