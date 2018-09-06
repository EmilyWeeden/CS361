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

    //Check for flag


    //Check for specifier


    return numchar;
}