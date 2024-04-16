#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 7
int main()
{
    int i, j;
    int mt[N][M];
    int * puntero;
    srand(time(NULL));

    puntero= &mt[0][0];
    for ( i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            *(puntero + (i*M+ j)) =1+rand()%100;//*(puntero+(i*numcolumnas+j))
            printf("%d  ",*(puntero + (i*M+ j)));
        }
      printf("\n");  
    }
    
    return 0;
}
