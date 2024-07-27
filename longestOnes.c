int longestOnes(int* nums, int numsSize, int k) {
    
    int start;
    int end;
    int flip;
    int consecutives;
    int maxConsecutives;

    start = 0;
    end = 0;
    flip = 0;
    consecutives = 0;
    maxConsecutives = 0;

    while(end < numsSize)
    {
        if(nums[end] == 1)
        {
            end++;
            consecutives++;
        }
        else if(nums[end] == 0 && flip < k)
        {
            end++;
            consecutives++;
            flip++;
        }
        else if(nums[end] == 0)
        {
            if(consecutives > maxConsecutives)
                maxConsecutives = consecutives;
            if(nums[start] == 1)
            {
                start++;
                consecutives--;
            }
            else if(nums[start] == 0)
            {
                start++;
                flip--;
                consecutives--;
            }
        }
    }
    if(consecutives > maxConsecutives)
        maxConsecutives = consecutives;
    return (maxConsecutives);
}

/* int main(void)
{
    int k = 3;
    int nums[] = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    longestOnes(nums, 19, k);
} */