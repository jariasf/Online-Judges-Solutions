/*****************************************
 ***Problema: Cola
 ***ID: 11150
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int main(){
    int n , sum ;
    while ( scanf( "%d", &n ) !=EOF ){
        sum = n;
        while( n >= 3){
            n -= 3;
            n++;
            sum++;
        }
        if( n == 2 )sum++;
        printf( "%d\n" ,sum);
    }
    return 0;
}
