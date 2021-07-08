/*
Univerisidad autonoma del estado de mexico
centro universitario uaem zumpango

Sánchez Contreras Marco Antonio
programacion paralela y distribuida
OBJETIVO: Determinar el camino más corto usando omp y algoritmo de floyd

Compilacion:
./floyd.x 8 matA.x
*/

#include <iostream>
#include <fstream>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath> 
#include "funciones.h"

using namespace std;

#define min(a,b) ((a<b)?a:b)

float **M, **A;
char *nomarch;
int main(int argc, char *argv[])
{
    int i,j,k,dt;
    float t1, t2,tt, m;
    
    dt = atoi(argv[1]);
    nomarch = argv[2];
    
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            A = crea_mat(dt,dt);
            A = lee_mat(nomarch,dt,dt);
        }
        #pragma omp section
        {
         	M = crea_mat(dt,dt);   
            M = A;
            //muestra_mat(A,dt,dt);;     
        } 
    }
    muestra_mat(A,dt,dt);;
    omp_set_num_threads(4);
    t1 = omp_get_wtime();
    
    #pragma omp parallel for simd

        for ( k = 0; k < dt; k++){
            for ( i = 0; i < dt; i++){
                for ( j = 0; j < dt; j++){
                    
                    M[i][j] = min(A[i][j],(A[i][k]+A[k][j]));
                    A[i][j] = M[i][j];
                }
                
            }
            
        }
 
    t2 = omp_get_wtime();
    tt = t2-t1;
    cout<<"El tiempo de ejecucion en paralelo es: "<<tt<<endl<<endl;
    muestra_mat(A,dt,dt);
    /* code */
    return 0;
}

