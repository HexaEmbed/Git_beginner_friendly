#include <stdio.h>
#include <stdlib.h>

#define SET_BIT(x, y) ((x) |= (1<<y))
#define CLR_BIT(x, y) ((x) &= ~(1<<y))
#define TGL_BIT(x, y) ((x) ^= (1<<y))

int main(void)
{
    printf("START: main\n");
    int x = 0 , y = 0;
    printf("Application Code Here_00\n");
    printf("Application Code Here_01\n");
    printf("SET_BIT: %d\n",SET_BIT(x, y));
    printf("CLR_BIT: %d\n",CLR_BIT(x, y));
    printf("TGL_BIT: %d\n",TGL_BIT(x, y));
    printf("END: main\n");
    return EXIT_SUCCESS;
}