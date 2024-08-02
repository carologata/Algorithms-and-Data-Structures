int pivotIndex(int* nums, int numsSize) {
    
    int pivot = -1;
    int rightSum = 0;
    int leftSum = 0;

    for(int i = 1; i < numsSize; i++)
        rightSum += nums[i];
    
    int i = 0;
    while(i < numsSize)
    {
        if(rightSum == leftSum)
        {
            pivot = i;
            break ;
        }
        i++;
        if(i < numsSize)
        {
            leftSum += nums[i-1];
            rightSum -= nums[i];
        }
    }
    return (pivot);
}
