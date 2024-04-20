#include <string.h>

int lengthOfLongestSubstring(char* s) {
    
    int i;
    int j;
    int len;
    int longestLen;
    char arr[256];

    i = 0;
    longestLen = 0;
    while(s[i])
    {
        j = i;
        len = 0;
        memset(arr, '\0', 256);
        while(s[j] && arr[(int)s[j]] == '\0')
        {
            arr[(int)s[j]] = s[j];
            len++;
            j++;
        }
        if(len > longestLen)
            longestLen = len;
        i++;   
    }
    return (longestLen);
}
