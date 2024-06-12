#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool check_if_palindromic(char *str)
{
    int len;
    int half;
    int i;
    int j;

    len = strlen(str);
    half = len/2;
    i = 0;
    j = len - 1;
    while(i < half)
    {
        if(str[i] != str[j])
            return (false);
        i++;
        j--;
    }
    return (true);
}

char* longestPalindrome(char* s) 
{
    
    char *new;
    char *longest_palindromic;
    int i;
    int j;
    int new_len;
    int palindromic_len;

    i = 0;
    palindromic_len = 0;
    new_len = 0;
    longest_palindromic = NULL;
    while(s[i])
    {
        j = i;
        while(s[j])
        {
            new = strndup(&s[i], j - i + 1);
            new_len = strlen(new);
            if(check_if_palindromic(new) && new_len > palindromic_len)
            {
                longest_palindromic = new;
                palindromic_len = strlen(longest_palindromic);
            }
            else
                free(new);
            j++;
        }
        i++;
    }
    return (longest_palindromic);
}

/* int main(void)
{
    char *longest_palindrome;
    char *str = "babad";

    longest_palindrome = longestPalindrome(str);
} */