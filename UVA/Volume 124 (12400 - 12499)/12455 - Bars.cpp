/*****************************************
 ***Problema: Bars
 ***ID: 12455
 ***Juez: UVA
 ***Tipo: Sumsets
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#define MAX 25
int a[ MAX ], n;
bool dfs(int step , int sum)
{
    if( step == n ) return false;
    if( sum - a[ step ] == 0) return true;
    if( dfs( step + 1 , sum - a[ step ] ) ) return true;
    if( dfs( step + 1 , sum ) ) return true;
    return false;
}
int main(){
    int t , i , s;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d %d" , &s , &n );
        for( i = 0 ; i < n ; ++i ) scanf("%d" , &a[ i ] );
        if( !s || dfs( 0 , s ) ) puts("YES");
        else puts("NO");
    }
    return 0;
}


/*

7
2
11
1 0 0 0 0 0 1 0 0 0 1
4
8
1 1 1 0 0 8 0 2
4
2
4 0
1000
20
50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50
999
20
50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 48
1000
20
100000 100000 100000 100000 100000
100000 100000 100000 100000 100000
100000 100000 100000 100000 100000
100000 100000 100000 100000 100000
1000
20
100000 100000 100000 100000 100000
100000 100000 100000 100000 100000
100000 100000 100000 100000 100000
100000 100000 100000 1 999

*/
