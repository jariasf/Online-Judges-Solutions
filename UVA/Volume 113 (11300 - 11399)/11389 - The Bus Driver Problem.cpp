/*****************************************
 ***Problema: The Bus Driver Problem
 ***ID: 11389
 ***Juez: UVA
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 105
int am[ MAX ], pm[ MAX ];
int main(){
    int n , d , r , ans;
    while( scanf("%d %d %d" , &n , &d , &r ) , n | d | r ){
        for( int i = 0 ; i < n ; ++i ) scanf("%d" , &am[ i ] );
        for( int i = 0 ; i < n ; ++i ) scanf("%d" , &pm[ i ] );
        sort( am , am + n );
        sort( pm , pm + n );
        ans = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( am[ i ] + pm[ n - i - 1 ] > d) ans += ( am[ i ] + pm[ n - i - 1 ] - d );
        }
        printf("%d\n" , ans * r );
    }
    return 0;
}
