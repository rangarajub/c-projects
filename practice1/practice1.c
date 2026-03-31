/* Conversion of Temperature from Fahrenheit to Celsius 

C = 5/9 (F - 32)

*/

#include <stdio.h>

#if 0
// Implementation using while loop
void f2c (void) 
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("********************\n");
    printf("Fahr\tCelsius\n");
    printf("********************\n");

    fahr = lower; 
    while(fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr += step;
    }
    printf("*******************\n");
}
#endif

// Implementation using #define constants and for loop

#define LOWER 0
#define UPPER 300
#define STEP 20

void f2c (void)
{
    int fahr, celsius;
    
    printf("********************\n");
    printf("Fahr\tCelsius\n");
    printf("********************\n");

    for(fahr = LOWER; fahr <= UPPER; fahr += STEP)
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
    }
    printf("*******************\n");
}

void print_input(void)
{
    int c;

    while((c = getchar()) != EOF)
        putchar(c);
}

void compress_multiple_blanks_to_single(void)
{
    int c, lastc = 'a';

    while((c = getchar()) != EOF)
    {
        if(c != ' ')
            putchar(c);
        else
        {
            if(lastc != ' ')
                putchar(c);
        }
        lastc = c;
    }
}

void replace_escape_chars(void)
{
    int c;

    while((c = getchar()) != EOF)
    {
        if(c == '\t')
        {
            putchar('\\');
            putchar('t');
        } else if(c == '\b')
        {
            putchar('\\');
            putchar('b');
        } else if(c == '\\')
        {
            putchar('\\');
            putchar('\\');
        } else
            putchar(c);
    }
}

#define IN 1    /* Inside a word */
#define OUT 0   /* Outside a word */

void word_count(void)
{
    int c;
    int nc = 0, nl = 0, nw = 0;
    int state = OUT;

    while((c = getchar()) != EOF)
    {
        ++nc;

        if(c == '\n')
            ++nl;
        if(c == ' ' || c == '\t' || c == '\n')
            state = OUT;
        else if(state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    printf("No of characters: %d\n", nc);
    printf("No of words: %d\n", nw);
    printf("No of lines: %d\n", nl);
}
