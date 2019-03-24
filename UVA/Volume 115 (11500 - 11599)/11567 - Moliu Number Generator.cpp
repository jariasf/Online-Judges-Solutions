/*****************************************
 ***Problema: Moliu Number Generator
 ***ID: 11567
 ***Juez: UVA
 ***Tipo: DP, recursion, simulation
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int resp;

void solve( long long s , int len ){
    if( s == 3 ){
        resp = len + 3;
        return;
    }
    if( s == 0 ){
        resp = len;
        return;
    }

    if( s % 2 == 0 )solve( s/2 , len + 1 );
    else{
        if( ( ( s - 1 ) /2 ) % 2 == 0 )solve( s - 1 , len + 1 );
        else solve( s + 1 , len + 1 );
    }
}

int main(){

    int n;
    long long s;

    while( scanf("%lld" , &s ) != EOF ){
        resp = 0;
        solve( s , 0 );
        printf("%d\n" , resp );
    }

    return 0;
}

