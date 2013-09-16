#include <stdlib.h>
#include <math.h>

int main(void)
{
    int k = 1;
    double a = sqrt(2);
    double b = 0.0;
    double x = 2 + sqrt(2);
    double t = 0.0;
    printf("%lf\n", M_PI);
    for(; k < 16; k++)
    {
        t = sqrt(a);
        b = (t * (1 + b))/(a + b);
        a = 0.5 * ((t + 1) / t);
        x = (x * b * (1 + a))/(1 + b);
        printf("k: %d || x: %lf || |x-PI|: %lf\n", k, x, fabs(x - M_PI));
    }
    
}