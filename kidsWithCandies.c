#include <stdlib.h>
#include <stdbool.h>

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {

    int i;
    int gst_candies_qty;
    bool *returnArray;

    returnArray = malloc(candiesSize * sizeof(bool));
    *returnSize = candiesSize;

    i = 0;
    gst_candies_qty = 0;
    while(i < candiesSize)
    {
        if(candies[i] > gst_candies_qty)
            gst_candies_qty = candies[i];
        i++;   
    }
    
    i = 0;
    while(i < candiesSize)
    {
        if(candies[i] + extraCandies >= gst_candies_qty)
            returnArray[i] = true;
        else
            returnArray[i] = false;
        i++;
    }
    return (returnArray);
}
