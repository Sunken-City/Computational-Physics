#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //Simple init to 0 to avoid errors. Just habit, really.
    double e = 0;
    double n = 0;
    int i = 1;
    for (; i < 11; i++)
    {
        n = pow(8.0, i);
        e = pow(1 + (1/n), n);
        printf("Using 8^%d: e = %.14lf\n", i, e);
    }
    e = exp(1.0);
    printf("Using exp: e = %.14lf\n", e);
}