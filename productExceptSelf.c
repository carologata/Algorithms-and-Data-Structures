/* algorithm source: https://www.youtube.com/watch?v=bNvIQI2wAjk */

#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    
    int i;
    int p;
    int s;
    int len;
    int *answer;

    answer = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    /* --------> */
    i = 0;
    answer[i] = 1;
    i++;
    while(i < numsSize)
    {
        answer[i] = answer[i - 1] * nums[i - 1];
        i++;
    }

    /* <-------- */
    i = numsSize - 1;
    s = 1;
    answer[i] = answer[i] * s;
    i--;
    while(i >= 0)
    {
        s = s * nums[i + 1];
        answer[i] = answer[i] * s;
        i--;
    }

    return (answer);
}
