#include <string.h>
#include <stdlib.h>

char *mergeAlternately(char *word1, char *word2){

    int len;
    char *mergeWord;
    int i;
    int j;
    int k;

    if(word1 == NULL || word2 == NULL)
        return (NULL);
    
    len = strlen(word1) + strlen(word2);
    mergeWord = malloc(len + 1);

    i = 0;
    j = 0;
    k = 0;
    while(word1[i] || word2[j])
    {
        if((word1[i] && k%2 == 0) || !word2[j])
        {
            mergeWord[k] = word1[i];
            i++;
        }
        else if(word2[j] || !word1[i])
        {
            mergeWord[k] = word2[j];
            j++;
        }
        k++;
    }
    mergeWord[k] = '\0';
    return (mergeWord);
}