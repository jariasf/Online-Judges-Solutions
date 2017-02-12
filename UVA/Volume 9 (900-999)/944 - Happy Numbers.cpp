/*****************************************
 ***Problema: Happy Numbers
 ***ID: 944
 ***Juez: UVA
 ***Tipo: Cycle Finding
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int f( int n ){
    int sum = 0;
    while( n > 0){
        sum += ( n % 10 )* ( n %10 );
        n /= 10;
    }
    return sum;
}

#define MAX 100000
int dp[ MAX ];
bool happy[ MAX ];

void TortoiseHare(int x){
    int s = 0, p = 1;

    int i = f(x), j = f(f(x));

    while (i != j) i = f(i), j = f(f(j));

    j = i; i = x;

    while (i != j) i = f(i), j = f(j), s++;

    j = f(i);

    while (i != j) j = f(j), p++;
    if( p == 1 ){ happy[ x ] = true; dp[ x ] = s + 1;  }
}

void Solve(){
    for( int i = 1 ; i< MAX ;++i ){
        happy[ i ] = false; dp[ i ] = -1;
        TortoiseHare( i );
    }
}

int main(){
    Solve();
    int n, L ,H;
    bool b = false;
    while( scanf("%d %d", &L, &H ) != EOF ){
        if( b ) printf("\n");
        b = true;
        for( int i = L; i <= H; ++i ){

            if( happy[ i ] ){
                printf("%d %d\n", i , dp[ i ] );
            }
        }
    }
    return 0;
}
