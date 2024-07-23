#include <stdbool.h>

bool increasingTriplet(int* nums, int numsSize) {
    
    int i;
    int j;
    int k;

    i = 0;
    while(i < numsSize - 2)
    {
       j = i + 1;
       while(j < numsSize - 1)
       {
            if(nums[i] < nums[j])
            {
                k = j + 1;
                while(k < numsSize)
                {
                    if(nums[j] < nums[k])
                        return (true);
                    k++;
                }
            }
            j++;
       }
    }
    return (false);
}