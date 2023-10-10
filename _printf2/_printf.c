#include <stdarg.h>
#include "lib/main.h"
#include "lib/type_conversion.h"


#define BIN 2
#define OCT 8
#define DEC 10
#define HEX 16


int _printf(const char *format, ...)
{

    // holds information needed by the three macros
    va_list args;

    // initialize the va_list to be used with the va_arg and va_end macros
    // format is the last fixed argument being passed to the function
    va_start(args, format);

    /*
     * va_arg(va_list ap, type)
     * so basically what va_argdoes is it retrieves the next argument in the
     * parameter list of the function with the type type
    */


    // basically, while the string is not at the null terminator
    while(*format != '\0')
    {
        // if the current charcter is %
        if(*format == '%')
        {
            // check the next character
            format++;
            // test the cases, if the following letters are after the %, then...
            switch (*format)
            {
                case 'c':
                    // if d, it is an integer
                    _putchar(va_arg(args, int));
                    break;

                case 's':
                    {
                        // if  s, it is a string
                        /*
                        * but we cannot call a string unless you call an array of
                        * characters like done below, and print out the array as long as
                        * the null terminator has not been reached
                        */
                        const char *str = va_arg(args, const char *);

                        while(*str != '\0')
                        {
                            _putchar(*str);
                            str++;
                        }
                    }
                    break;

                case 'd': case 'i':
                    {
                        int len = 0;
                        char s[32];
                        long long n = va_arg(args, long long);
                        _itob(n, s, DEC);

                        len += _putstr(s);

                        break;
                    }

                case 'x': case 'X':
                    {
                        int len = 0;
                        char s[32];
                        long long n = va_arg(args, long long);
                        _itob(n, s, HEX);
                        len += _putstr(s);
                        break;
                    }

                default:
                    // else just print the % and what follows next
                    _putchar('%');
                    _putchar(*format);
            }
        }
        else
        {
            _putchar(*format);
        }
        format++;
    }

    // this macro allows a function with variable arguments which used va_start to return.
    // if not called before returning from the function, the result is undefined
    va_end(args);
}
