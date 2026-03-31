#include <stdio.h>

extern void reverse_string(char **str1, char **str2);

int main(void)
{
    /* Print the words in reverse */

    char *str1 = "Hello";
    char *str2 = "World";

    printf("%s %s\n", str1, str2);
    reverse_string(&str1, &str2);
    printf("%s %s\n", str1, str2);
   
   return 0;
}
