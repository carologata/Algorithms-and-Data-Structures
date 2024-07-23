#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    
    int i;
    int planted;

    i = 0;
    planted = 0;
    while(i < flowerbedSize && planted < n)
    {
        if(flowerbedSize == 1)
        {
            if(flowerbed[i] == 0)
            {
                flowerbed[i] = 1;
                planted++;
            }
        }
        else if(i == 0)
        {
            if(flowerbed[i] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                planted++;
            }
        }
        else if (i == (flowerbedSize - 1))
        {
            if(flowerbed[i] == 0 && flowerbed[i - 1] == 0)
            {
                flowerbed[i] = 1;
                planted++;
            }
        }   
        else 
        {
            if(flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                planted++;
            }
        }
        i++;
    }
    if(planted == n)
        return (true);
    return (false);
}
