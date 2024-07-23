#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isVowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return (true);
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return (true);
    return (false);
}

char* reverseVowels(char* s) {

    int i;
    int j;
    int vowelsSize;
    char *vowels;

    i = 0;
    vowelsSize = 0;
    while(s[i])
    {
        if(isVowel(s[i]))
            vowelsSize++;
        i++;
    }
    vowels = calloc(vowelsSize + 1, 1);
    
    i--;
    j = 0;
    while(i >= 0)
    {
        if(isVowel(s[i]))
        {
            vowels[j] = s[i];
            j++;
        }
        i--;
    }

    i = 0;
    j = 0;
    while(s[i])
    {
        if(isVowel(s[i]))
        {
            s[i] = vowels[j];
            j++;
        }
        i++;
    }
    return (s);
}