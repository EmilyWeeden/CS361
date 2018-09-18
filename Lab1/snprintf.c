#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

//SNPRINTF function call
int snprintf(char *dst, size_t buffer_size, const char *format, ...);

//Other function calls
static void convertint(char *str, int val){
    //do something
}

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
            switch (*format){
                case '-': { //left justified
                    break;
                }
                case '+': { //changes sign
                    break;
                }
                case '#': { //print "0x"
                    break;
                }
                case '0': { //fill with 0s instead of spaces
                    break;
                }
            }
            //Check for specifier
            switch (*format){
                case 's': { //string
                    const char *s = va_arg(arg, const char *);
                    while (*s)
                        putchar(*s++);
                    break;
                }
                case 'c': { //character
                    const char *c = va_arg(arg, const char **);
                    putchar(*s++);
                    break;
                }
                case 'x': { //32bit hex number
                    int x = va_arg(arg, int);
                    break;
                }
                case 'lx': { //64bit hex number
                    int lx = va_arg(arg, int);
                    break;
                }
                case 'd': { //32bit signed decimal
                    int d = va_arg(arg, int);
                    //do something
                    break;
                }
                case 'ld': { //64bit signed decimal
                    int ld = va_arg(arg, int);
                    break;
                }
                case 'u': { //32bit unsigned decimal
                    unsigned int u = va_arg(arg, unsigned int);
                    break;
                }
                case 'lu': { //64bit unsigned decimal
                    unsigned int lu = va_arg(arg, unsigned int);
                    break;
                }
                case 'p': { //64bit pointer in hex
                    //pointer
                    break;
                }
                case 'f': { //32bit float number
                    float f = va_arg(arg, float);
                    break;
                }
                case 'lf': { //64bit float number
                    float lf = va_arg(arg, float);
                    break;
                }
                case '%': { //just %
                    //%
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