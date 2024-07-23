#include <string.h>
#include <stdbool.h>

bool isSubsequence(char* s, char* t) {
    
    int i;
    int j;

    i = 0;
    j = 0;
    while(t[i] && s[j])
    {
        if(s[j] == t[i])
            j++;
        i++;
    }
    if(strlen(s) == j)
        return (true);
    return (false);
}