#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long card_no = get_long("Please enter a credit card number: ");
//  printf("You entered number: %li \n",card_no);

// to extract individual digits

    long d16 = card_no % 10000000000000000;
    long d15 = card_no % 1000000000000000;
    long d14 = card_no % 100000000000000;
    long d13 = card_no % 10000000000000;
    long d12 = card_no % 1000000000000;
    long d11 = card_no % 100000000000;
    long d10 = card_no % 10000000000;
    long d9 = card_no % 1000000000;
    long d8 = card_no % 100000000;
    long d7 = card_no % 10000000;
    long d6 = card_no % 1000000;
    long d5 = card_no % 100000;
    long d4 = card_no % 10000;
    long d3 = card_no % 1000;
    long d2 = card_no % 100;
    long d1 = card_no % 10;

    d16 = (d16 - d15) / 1000000000000000;
    d15 = (d15 - d14) / 100000000000000;  // b = (b-a) /10;
    d14 = (d14 - d13) / 10000000000000;
    d13 = (d13 - d12) / 1000000000000;
    d12 = (d12 - d11) / 100000000000;
    d11 = (d11 - d10) / 10000000000;
    d10 = (d10 - d9) /  1000000000;
    d9 = (d9 - d8) /   100000000;
    d8 = (d8 - d7) /   10000000;
    d7 = (d7 - d6) /   1000000;
    d6 = (d6 - d5) /   100000;
    d5 = (d5 - d4) /   10000;
    d4 = (d4 - d3) /   1000;
    d3 = (d3 - d2) /   100;
    d2 = (d2 - d1) /   10;



// To check if card no is valid
// to multiply each digit by 2

    d16 *= 2;
    d14 *= 2;
    d12 *= 2;
    d10 *= 2;
    d8 *= 2;
    d6 *= 2;
    d4 *= 2;
    d2 *= 2;


    int d21 = 0, d22 = 0, d41 = 0, d42 = 0, d61 = 0, d62 = 0, d81 = 0, d82 = 0, d101 = 0, d102 = 0;
    int d121 = 0, d122 = 0, d141 = 0, d142 = 0, d161 = 0, d162 = 0;

// To split 2 digit if occured after multiplication

    d21 = d2 % 10;
    d22 = (d2 - d21) / 10;
    d41 = d4 % 10;
    d42 = (d4 - d41) / 10;
    d61 = d6 % 10;
    d62 = (d6 - d61) / 10;
    d81 = d8 % 10;
    d82 = (d8 - d81) / 10;
    d101 = d10 % 10;
    d102 = (d10 - d101) / 10;
    d121 = d12 % 10;
    d122 = (d12 - d121) / 10;
    d141 = d14 % 10;
    d142 = (d14 - d141) / 10;
    d161 = d16 % 10;
    d162 = (d16 - d161) / 10;

// Adding individual digits

    int sum = d21 + d22 + d41 + d42 + d61 + d62 + d81 + d82 + d101 + d102 + d121 + d122 + d141 + d142 + d161 + d162;
    int final_sum = sum + d1 + d3 + d5 + d7 + d9 + d11 + d13 + d15;

    if (final_sum % 10 == 0)
    {
        if (d15 == 3 && (d14 / 2 == 4 || d14 / 2 == 7))
        {
            printf("AMEX\n");   //34,37 And 15 digit
        }
        else if ((d16 / 2 != 0 && d16 / 2 == 5) && (d15 == 1 || d15 == 2 || d15 == 3 || d15 == 4 || d15 == 5))
        {
            printf("MASTERCARD\n");   //51,52,53,54,55 And 16 digit
        }
        else if ((d16 / 2 != 0 && d16 / 2 == 4) || (d16 / 2 == 0 && d15 == 0 && d14 / 2 == 0 && d13 == 4))
        {
            printf("VISA\n");   //4 and 13 0r 16 digit
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
