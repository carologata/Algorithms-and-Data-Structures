void swap(int *nums, int i, int j)
{
    int tmp;

    tmp = nums[j];
    nums[j] = nums[i];
    nums[i] = tmp;
}

void moveZeroes(int* nums, int numsSize) {

    int i;
    int j;

    i = 0;
    j = i + 1;
    while(j < numsSize)
    {
        if(nums[i] == 0 && nums[j] != 0)
        {
            swap(nums, i, j);
            i++;
            j = i + 1;
        }
        else if(nums[i] == 0)
        {
            j++;
        }
        else
        {
            i++;
            j = i + 1;
        }
    }
}