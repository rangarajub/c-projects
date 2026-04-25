#include <stdio.h>

void print_last_digit(int n)
{
    printf("The last digit of %d is %d\n", n, n % 10);
}

void print_last_two_digits(int n)
{
    printf("The last two digits of %d are %d\n", n, n % 100);
}

void print_even_or_odd(int n)
{
    if (n % 2 == 0)
        printf("%d is even\n", n);
    else
        printf("%d is odd\n", n);
}

void delete_last_digit(int *n)
{
    *n /= 10;
}

void swap_with_temp(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_without_temp(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void swap_with_xor(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main()
{
    int n = 123;
    int a = 5, b = 10;

    print_last_digit(n);
    print_last_two_digits(n);
    print_even_or_odd(n);
    delete_last_digit(&n);
    printf("After deleting the last digit, n is now %d\n", n);

    printf("Before swapping: a = %d, b = %d\n", a, b);
    swap_with_temp(&a, &b);
    printf("After swapping with temp: a = %d, b = %d\n", a, b);
    swap_without_temp(&a, &b);
    printf("After swapping without temp: a = %d, b = %d\n", a, b);
    swap_with_xor(&a, &b);
    printf("After swapping with XOR: a = %d, b = %d\n", a, b);

    return 0;
}