/*****************************************
 ***Problema: Perfect Cubes
 ***ID: 386
 ***Juez: UVA
 ***Tipo: Ad hoc, Simulation, no input
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<stdio.h>

int main(){
    for( int i = 6 ; i <= 200 ; ++i ){
       for(int j = 2 ; j <= 150 ; ++j ){
          for(int k = j+1 ; k <= 150 ; ++k ){
            for(int q = k+1 ; q <= 200 ; ++q ){
               long long sum = j * j * j + k * k * k + q * q * q;
               if( sum == i * i * i ){
                   printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, k, q);
               }
            }
          }
       }
    }
    return 0;
}
