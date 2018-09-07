#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

//SNPRINTF function call
int snprintf(char *dst, size_t buffer_size, const char *format, ...);

//Other function calls

//Main for testing
int main() {
     char buffer[256];
     int i = 10;
     float j = 22.17234;
     double k = 774.291823;
     char l = 'A';
     const char *m = "Hello World";
     unsigned long n = 0xdeadbeeffeedbeefUL;
     int ret;

     ret = snprintf(buffer, 256, "%-25s %d %5.2f %.3lf %c %#10lx %%", m, i, j, k, l, n);

     printf("Wrote: '%s' (%d bytes)\n", buffer, ret);

     return 0;
}

int snprintf(char *dst, size_t buffer_size, const char *format, ...){
    int numchar;
    va_list arg;
    va_start(arg, format);
    while (*format) {
        if (*format == '%'){
            format++;
            //Check for flag
            //Check for specifier
            switch (*format){
                case 's': {
                    const char *s = va_arg(arg, const char *);
                    while (*s)
                        putchar(*s++);
                    break;
                }
                case 'd': {
                    int d = va_arg(arg, int);
                    //do something
                    break;
                }
            }
            format++;
        }
        else {
            //print character
            putchar(*format);
            format++;
        }
    }

    va_end(arg);
    return numchar;
}