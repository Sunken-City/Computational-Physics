#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int nInt = 1;
    double nDouble = 1;
    double nLog = 0;
    int i = 1;
    printf("n = %d || Int: %d | Double: %lf | Log: %lf\n", 0, 0, 0, 0);
    for (; i < 31; i++)
    {
        nInt = nInt * i;
        nDouble = nDouble * (double)i;
        nLog = log(nDouble);
        printf("n = %d || Int: %d | Double: %lf | Log: %lf\n", i, nInt, nDouble, exp(nLog));
    }
}