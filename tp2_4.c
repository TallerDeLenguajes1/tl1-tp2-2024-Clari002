#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMA 5

struct compu
{
    int velocidad;//entre 1 y 3 GHz
    int anio;//entre 2015 y 2023
    int cantidad;//entre 1 y 8
    char *tipo_cpu;//valor del arreglo tipos
}typedef compu;

void mostrarPcs(compu PC[], int cantidad);
void mostrarPcMasVieja( compu PC[], int cantidad);
void mostrarPcMasVeloz( compu PC[], int cantidad);

int main()
{

    compu PC[TAMA];
    int i, j;
    char tipos[6][10]={"Intel", "AMD", "Celeron","Athlon", "Core", "Pentium"};
    srand(time(NULL));

    for (i = 0; i < TAMA; i++)
    {
        PC[i].velocidad= 1+rand()%3;
        PC[i].anio= 2015 + rand()%10;
        PC[i].cantidad = 1 + rand()%8;
        int valor = rand() % 6;
        PC[i].tipo_cpu = malloc(strlen(tipos[valor]+1));//reservo memoria
        strcpy(PC[i].tipo_cpu,tipos[valor]);   
    }
    
    mostrarPcs(PC, TAMA);
    mostrarPcMasVieja(PC, TAMA);
    mostrarPcMasVeloz(PC, TAMA);

    for (j = 0; j < TAMA; j++)
    {
        free(PC[j].tipo_cpu);
    }


    return 0;
}

void mostrarPcs(compu PC[], int cantidad)
{

    int i;
    for (i = 0; i < cantidad; i++)
    {
        printf("\n-----------PC %d------------", i+1);
        printf("\nVelocidad: %d", PC[i].velocidad);
        printf("\nA%co: %d",164, PC[i].anio);
        printf("\nCantidad: %d", PC[i].cantidad);
        printf("\nTipo cpu: %s", PC[i].tipo_cpu);
        printf("\n");
        
    }   
}


void mostrarPcMasVieja(compu PC[], int cantidad)
{

    int i;
    int pcJoven = 2025;
    
    for ( i = 0; i < cantidad; i++)
    {
        if(PC[i].anio<pcJoven)
        {
            pcJoven= PC[i].anio; 
           
        }   
    }
    printf("\n\nLA/s PC/s MAS VIEJA/s: ");
    for ( i = 0; i < cantidad; i++)
    {
        if (PC[i].anio == pcJoven)
        {
            printf("\n-----------PC %d------------", i+1);
        printf("\nVelocidad: %d", PC[i].velocidad);
        printf("\nA%co: %d",164, PC[i].anio);
        printf("\nCantidad: %d", PC[i].cantidad);
        printf("\nTipo cpu: %s", PC[i].tipo_cpu);
        printf("\n");
        }
        
    }
    
     
    
}

void mostrarPcMasVeloz( compu PC[], int cantidad)
{
    int i;
    int velocidadMayor = 0;
    
    for ( i = 0; i < cantidad; i++)
    {
        if(PC[i].velocidad>velocidadMayor)
        {
            velocidadMayor = PC[i].velocidad; 
            
        }   
    }
    printf("\n\nLA/s PC/s CON MAS VELOCIDAD: ");
    for ( i = 0; i < cantidad; i++)
    {
        if (PC[i].velocidad== velocidadMayor)
        {
            printf("\n-----------PC %d------------", i+1);
            printf("\nVelocidad: %d", PC[i].velocidad);
            printf("\nA%co: %d",164, PC[i].anio);
            printf("\nCantidad: %d", PC[i].cantidad);
            printf("\nTipo cpu: %s", PC[i].tipo_cpu);
            printf("\n");
        }
        
    }
    
     

}