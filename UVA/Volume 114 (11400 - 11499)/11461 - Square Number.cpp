/*****************************************
 ***Problema: Square Number
 ***ID: 11461
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cmath>

using namespace std;

#define MAX 100005
int dp[ MAX ];

void Solve(){

    dp[ 0 ] = 0;
    double aux;
    for( int i = 1 ; i < MAX ;++i ){
        aux = sqrt( i );
        if(  aux == (int)aux ){
            dp[ i ] = dp[ i - 1 ] + 1;
        }
        else dp[ i ] = dp[ i - 1 ];
    }
}

int main(){
    int low, high;
    Solve();

    while( scanf("%d %d", &low, &high) && low|high ){
        printf("%d\n" , dp[ high ] - dp[ low - 1 ]);
    }

    return 0;
}
