int maxVowels(char* s, int k) {
    
    int start;
    int end;
    int qtyVowels;
    int maxVowels;

    start = 0;
    end = 0;
    qtyVowels = 0;
    maxVowels = 0;

    if(s[start] == 'a' || s[start] == 'e' || s[start] == 'i' || s[start] == 'o' || s[start] == 'u')
        qtyVowels++;
        
    while(s[end])
    {
        if(end - start + 1 == k)
        {
            if(qtyVowels > maxVowels)
                maxVowels = qtyVowels;
            end++;
            if(s[end])
            {
                if(s[end] == 'a' || s[end] == 'e' || s[end] == 'i' || s[end] == 'o' || s[end] == 'u')
                    qtyVowels++;
            }
        }
        else if(end - start + 1 > k)
        {
           if(s[start] == 'a' || s[start] == 'e' || s[start] == 'i' || s[start] == 'o' || s[start] == 'u')
                qtyVowels--;
            start++;
        }
        else if(end - start + 1 < k)
        {
            end++;
            if(s[end])
            {
                if(s[end] == 'a' || s[end] == 'e' || s[end] == 'i' || s[end] == 'o' || s[end] == 'u')
                    qtyVowels++;
            }
        }
    }
    return (maxVowels);
}

/* int main(void)
{
    char *s = "abciiidef";

    int k = 3;

    int result = maxVowels(s, k);
} */