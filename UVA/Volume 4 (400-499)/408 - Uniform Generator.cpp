/*****************************************
 ***Problema: Uniform Generator
 ***ID: 408
 ***Juez: UVA
 ***Tipo: Cycle finding
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int s, m, now, i;
    while( scanf("%d %d", &s ,&m ) == 2 ) {
        int a[ 100005 ] = { 0 };
        now = s % m; a[ now ] = 1;
        while( now ) {
            now = ( now + s ) % m;
            a[ now ] = 1;
        }
        for( i = 0 ; i < m ; i++)
            if( !a[ i ] ) break;
        if( i >= m ) printf("%10d%10d    Good Choice\n\n", s, m);
        else printf("%10d%10d    Bad Choice\n\n", s, m);
    }
    return 0;
}

