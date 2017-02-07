/*****************************************
 ***Problema: Eeny Meeny Moo
 ***ID: 440
 ***Juez: UVA
 ***Tipo: Simulation, Josephus
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
//1 omitimos, empezamos desde 2 como si fuera 0
int survivor(int n, int m){
   int i, s;
   for (s = 0, i = 1; i <= n; i++) s = (s + m) % i;
   return (s + 2);
}


int main(){
    int n;
    while( scanf("%d" , &n ) && n ){
        for( int i = 1 ; ; ++i ){
            if( survivor( n - 1 , i ) == 2 ){
                printf("%d\n" , i );
                break;
            }
        }
    }

    return 0;
}
