#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool check_if_divides_both_str(char *str1, char *str2, char *divider, size_t size)
{
    int i;
    int j;

    i = 0;
    while(str1[i])
    {
        j = 0;
        while(str1[i] && j < size)
        {
            if(str1[i] != divider[j])
                return (false);
            i++;
            j++;
        }
    }

    i = 0;
    while(str2[i])
    {
        j = 0;
        while(str2 && j < size)
        {
            if(str2[i] != divider[j])
                return (false);
            i++;
            j++;
        }
    }
    return (true);
}

char* gcdOfStrings(char* str1, char* str2) {
    
    int i;
    size_t size;

    unsigned int len_str1;
    unsigned int len_str2;
    char *smallest_str;

    char *largest_divider;
    char *divider;
    char *tmp;

    len_str1 = strlen(str1);
    len_str2 = strlen(str2);

    smallest_str = str1;
    if(len_str1 > len_str2)
        smallest_str = str2;

    divider = NULL;
    largest_divider = calloc(1, sizeof(char));

    i = 0;
    size = 1;
    while(smallest_str[i])
    {
        if(len_str1 % size == 0 && len_str2 % size == 0)
        {
            divider = calloc(size + 1, sizeof(char));
            strncpy(divider, smallest_str, size);
            if(check_if_divides_both_str(str1, str2, divider, size))
            {
                tmp = largest_divider;
                largest_divider = divider;
                free(tmp);
            }
            else
                free(divider);
        }
        size++;
        i++;
    }
    return (largest_divider);
}   
