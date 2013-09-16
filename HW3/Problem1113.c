#include <stdlib.h>
#include <math.h>

int main(void)
{
    int nInt = 0;
    double nDouble = 0;
    double nLog = 0;
    int i = 1;
    for (; i < 31; i++)
    {
        nInt = nInt*i;
        printf("Int: %d", nInt);
    }
}