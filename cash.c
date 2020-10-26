#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float a;
    do
    {
        a = get_float("Please enter change owed in $: ");
    }
    while (a <= 0.0);
    int cents = round(a * 100);
    int i, j, k, l;
    printf("Change owed is %i cents.\n", cents);
    for (i = 0; cents >= 25; i++) // To count Quarters
    {
        cents -= 25;
    }
    for (j = 0; cents >= 10; j++) // To count Dimes
    {
        cents -= 10;
    }
    for (k = 0; cents >= 5; k++) // To count Nickels
    {
        cents -= 5;
    }
    for (l = 0; cents >= 1; l++) // To count Pennys
    {
        cents -= 1;
    }
    printf("Coins needed: %i\n", i + j + k + l);
    printf("%i Quarters, %i Dimes, %i Nickels and %i Pennys.\n", i, j, k, l);
}

