#include <stdlib.h>

void number_to_char(int counter, int *tcount, char *arr, int *index)
{
    int number;
    int divider;

    divider = 1;
    number = counter;
    *tcount = *tcount + 1;

    while(number > 9)
    {
        divider *= 10;
        number /= 10;
        *tcount = *tcount + 1;
    }
    while(divider > 0)
    {
        arr[*index] = (counter / divider) + 48;
        counter = counter % divider;
        divider /= 10;
        *index = *index + 1;
    }
    *index = *index - 1;
}

int compress(char* chars, int charsSize) {

    int i;
    int j;
    int icount;
    int tcount;
    char c;

    i = 0;
    j = 0;
    icount = 0;
    tcount = 0;

    c = chars[i];

    while(i < charsSize)
    {
        if(chars[i] == c)
            icount++;
        else 
        {
            if(icount == 1)
            {
                tcount += icount;
                j++;
            }
            else
            {
                tcount++;
                j++;
                number_to_char(icount, &tcount, chars, &j);
                j++;
            }
            icount = 1;
            c = chars[i];
            chars[j] = c;
        }
        i++;
    }
    if(icount == 1)
        tcount += icount;
    else
    {
        tcount++;
        j++;
        number_to_char(icount, &tcount, chars, &j);
    }
    return (tcount);
}

/* int main(void)
{

    char *chars;
    chars = malloc(14);
    chars[0] = 'a';
    chars[1] = 'b';
    chars[2] = 'b';
    chars[3] = 'b';
    chars[4] = 'b';
    chars[5] = 'b';
    chars[6] = 'b';
    chars[7] = 'b';
    chars[8] = 'b';
    chars[9] = 'b';
    chars[10] = 'b';
    chars[11] = 'b';
    chars[12] = 'b';
    chars[13]='b';

    int result = compress(chars, 14);
} */