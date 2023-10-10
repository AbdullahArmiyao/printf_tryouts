#include "lib/main.h"

/**
 * _reverse - function to reverse string
*/

void _reverse(char *s, int len){
    int i = 0, j = len - 1;
    while (i < j)
    {
        //swap positions
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        //incrememt i and decrement j
        i++;
        j--;
    }

}
