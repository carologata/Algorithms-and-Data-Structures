#include <stdbool.h>

int longestSubarray(int* nums, int numsSize) {
    
    int start;
    int end;
    int k;
    int longestSize;
    int size;
    bool isThereZero;

    start = 0;
    end = 0;
    k = 1;
    longestSize = 0;
    size = 0;
    isThereZero = false;

    while(end < numsSize)
    {
        if(nums[end] == 1)
        {
            end++;
            size++;
        }
        else if(nums[end] == 0 && k == 1)
        {
            end++;
            k--;
            isThereZero = true;
        }
        else if(nums[end] == 0)
        {
            if(size > longestSize)
                longestSize = size;

            if(nums[start] == 0)
                k++;
            else 
                size--;
            start++;
        }

    }
    if(size > longestSize)
        longestSize = size;
    if(!isThereZero)
        longestSize--;
    return (longestSize);    
}

/* int main(void)
{
    int nums[] = {0,1,1,1,0,1,1,0,1};

    longestSubarray(nums, 9);
} */