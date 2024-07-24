#include <limits.h>

double findMaxAverage(int* nums, int numsSize, int k) {
    
    int start;
    int end;
    int sum;
    double average;
    double maxAverage;

    start = 0;
    end = 0;
    sum = nums[start];
    average = 0;
    maxAverage = INT_MIN;
    while(end < numsSize)
    {
        if(end - start + 1 == k)
        {
            average = (double) sum/k;
            if(average > maxAverage)
                maxAverage = average;
            end++;
            if(end < numsSize)
                sum += nums[end];
        }
        else if(end - start + 1 < k)
        {
            end++;
            if(end < numsSize)
                sum += nums[end];

        }
        else if(end - start + 1 > k)
        {
            sum -= nums[start];
            start++;
        }
    }
    return (maxAverage);
}

/* int main(void)
{
    int nums[] = {-1};
    int k = 1;

    findMaxAverage(nums, 1, k);
} */