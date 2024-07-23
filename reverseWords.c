#include <stdlib.h>

char* reverseWords(char* s) {
    
    int i;
    int len;
    int start;
    char *reverseStr;

    len = strlen(s);
    reverseStr = calloc(len + 1, sizeof(char));

    len--;
    i = 0;
    while(len >= 0 && s[len] == ' ')
        len--;
    while(len >= 0)
    {
        if(s[len] != ' ')
        {
            while(len >= 0 && s[len] != ' ')
                len--;
            start = len + 1;
            while(s[start] && s[start] != ' ')
            {
                reverseStr[i] = s[start];
                start++;
                i++; 
            } 
        }
        if((len - 1 >= 0) && s[len] == ' ' && s[len - 1] != ' ')
        {
            reverseStr[i] = ' ';
            i++;
        }
        len--;
    }
    return(reverseStr);
}