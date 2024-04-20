#include <math.h>

int lengthOfLongestSubstring(char* s) 
{
    
    int i;
    int j;
    int len;
    int longestLen;
    int arr[256] = {0};

    i = 0;
    j = 0;
    longestLen = 0;
    while(s[i])
    {
        arr[s[i]]++;
        while(arr[s[i]] > 1)
        {
            arr[s[j]]--;
            j++;
        }
        len = i - j + 1;
        longestLen = fmax(longestLen, len);
        i++;
    }
    return (longestLen);
}
