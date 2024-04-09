#include <stdio.h>
#include <stdlib.h>

#define N 20
int main()
{
    int i;
    double vt[N];
    double *punteroVt;
    punteroVt = &vt[0];
    printf("[ ");
    for ( i = 0; i < N; i++)
    {
        *punteroVt = 1+rand()%100;
       // vt[i]=1+rand()%100;
        printf("%.2f  ", ++(*punteroVt));
    }
    printf("]");

    return 0;
}