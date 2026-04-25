#include <stdio.h>
#include <unistd.h>

int main()
{
    unsigned int x = 0xffffffff;
    int i = 5;

    printf("x = 0x%08x\n", x);

    // clearing bit number 3
    x &= ~(1 << 3);

    printf("x = 0x%08x\n", x);

    // setting bit number 3 back to original state

    x |= (1 << 3);

    printf("x = 0x%08x\n", x);

    x = 0;

    // bit toggling bit number 3 five times

    do{
        // Testing the toggle bit operation
        x ^= (1 << 3);
        printf("x = 0x%08x\n", x);
    }while(--i != 0);

    x = (1 << 1) + (1 << 4);

    // BIT0 should be zero, BIT1 should be one, BIT2 should be zero, BIT3 should be zero, BIT4 should be one
    i = 0;
    while(i < 5)
    {
        if((x & (1 << i)) == (1 << i))
            printf("BIT%d is SET\n", i);
        else
            printf("BIT%d is CLEAR\n", i);
        i++;
    }

    return 0;
}