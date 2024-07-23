int min(int x, int y)
{
    int minimum;

    minimum = x;
    if(x > y)
        minimum = y;
    return (minimum);
}

int maxArea(int* height, int heightSize) {

    int i;
    int j;
    int area;
    int max;

    i = 0;
    j = heightSize - 1;

    area = (j - i) * min(height[i], height[j]);
    max = area;
    while(i < j)
    {
        if(height[i] < height[j])
            i++;
        else
            j--;
        area = (j - i) * min(height[i], height[j]);
        if(area > max)
            max = area;
    }
    return (max);
}