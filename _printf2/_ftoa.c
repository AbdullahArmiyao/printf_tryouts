#include "lib/type_conversion.h"
#include "lib/main.h"
#include <math.h>
#include <stdio.h>

/*
 * int_to_str - function that converts integer to string
 * @x: is the given integer
 * @str: is the string
 * @d: An integer representing the precision, which specifies
 * the number of digits after the decimal point
*/

int int_to_str(long long x, char *str, int d){

    /**
     * These lines initialize an integer variable i to 0, which
     * will be used as an index for building the string. It also
     * stores the sign of the input integer x in the sign variable.
    */
    int i = 0;
    long long int sign = x;

    /**
     * This conditional block checks if x is negative and, if so,
     * converts it to its positive equivalent. This is done to handle
     * negative numbers correctly in the string conversion
    */
    if (x < 0){
        x = -x;
    }

    /**
     * This while loop iteratively processes the digits of the positive
     * integer x. It takes the last digit of x using (x % 10) and converts
     * it to a character by adding '0'. It stores this character in the str
     * array at index i and then updates x by dividing it by 10 to remove the
     * last digit. This process continues until all digits of x have been processed
     * and converted to characters in the str array
    */
    while(x){
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }

    /**
     * If the input x was negative, this block adds a minus sign '-' at the end of
     * the string to indicate that the number is negative
    */
    if(sign < 0){
        str[i++] = '-';
    }

    /**
     * This while loop adds trailing zeros to the string to achieve the specified
     * precision (d). If d is greater than the number of digits in the integer part
     * of the number, it pads the string with zeros
    */
    while (i < d){
        str[i++] = '0';
    }

    /**
     * These lines terminate the string by adding a null character '\0' at the end.
     * It then calls a _reverse function to reverse the characters in the string,
     * presumably to obtain the correct order for the integer digits
    */
    str[i] = '\0';
    _reverse(str, i);

    return (1);
}

/**
 * _ftoa - converts double to string
 * @f: floating point number
 * @s: string
 * Return: void
*/

void _ftoa(long double f, char *s){

    /**
     * These lines declare a long double variable sign to store the sign of the
     * input floating-point number f and an integer j to use as an index for
     * building the string s
    */
    long double sign = f;
    int j = 0;

    /**
     * This conditional block checks if f is negative. If it is, it takes the
     * absolute value of f by negating it. This is done to handle negative floating-point
     * numbers correctly in the conversion process
    */
    if (f < 0)
        f = -f;

    /**
     * Extract the integer part
    */
    long long ipart = (long long)f;

    /**
     * Extract the floating part
    */
    long double fpart = (f - (long double)ipart) * pow(10, 6);

    // check if the value was negative then add a -
    if(sign < 0){
        s[j++] = '-';
    }
    /*convert integer part to string*/
    int i = int_to_str(ipart, s + j, 0);
    s[i++] = '.';
    int_to_str((long long)fpart, s + i, 6);
}
