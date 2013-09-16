#include <stdlib.h>
#include <math.h>

int main(void)
{
    int k = 1;
    double a = sqrt(2);
    double b = 0.0;
    double x = 2.0 + sqrt(2);
    double t = 0.0;
    printf("%.8lf\n", M_PI);
    for(; k < 6; k++)
    {
        t = sqrt(a);
        b = (t * (1 + b))/(a + b);
        a = 0.5 * (t + (1/t));
        x = (x * b * (1 + a))/(1 + b);
        printf("k: %d || x: %.16lf || |x-PI|: %.16lf\n", k, x, fabs(x - M_PI));
    }
    
}