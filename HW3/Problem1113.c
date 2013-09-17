#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int nInt = 1;
    double nDouble = 1;
    double nLog = log(1);
    int i = 1;
    printf("n = %d || Int: %d | Double: %lf | Log: %lf\n", 0, 1, 1, 1);
    for (; i < 31; i++)
    {
        nInt = nInt * i;
        nDouble = nDouble * (double)i;
        nLog = nLog + log(i);
        printf("n = %d || Int: %d | Double: %lf | Log: %lf\n", i, nInt, nDouble, exp(nLog));
    }
}