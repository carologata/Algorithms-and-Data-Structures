#include <stdlib.h>
#include <string.h>

char *checkIfIsLongestPalindromic(char *s, int i, int j, char *current)
{
    char *new;
    int size;
    int string_size;

    string_size = j;
    while(i < string_size + 1)
    {
        if(s[i] != s[j])
            return (current);
        i++;
        j--;  
    }
    size = j - i + 2;
    new = calloc(size, sizeof(char));
    strncpy(new, &s[i], size - 1);
    return (new);
}

char* longestPalindrome(char* s) {
    
    int i;
    int j;
    char *longestPalindromicString;

    i = 0;
    longestPalindromicString = calloc(2, sizeof(char));
    longestPalindromicString[0] = s[i];
    longestPalindromicString[1] = '\0';
    while(s[i])
    {
        j = i + 1;
        while(s[j])
        {
            longestPalindromicString = checkIfIsLongestPalindromic(s, i, j, longestPalindromicString);
            j++;
        }
        i++;
    }
    return (longestPalindromicString);
}

int main(void)
{
    char *s;

    s = longestPalindrome("babad");
}