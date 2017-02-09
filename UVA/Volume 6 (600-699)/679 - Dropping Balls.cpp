/*****************************************
 ***Problema: Dropping Balls
 ***ID: 679
 ***Juez: UVA
 ***Tipo: Tree
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

#define MAX 524290
int n;
bool tree[ 4 * MAX ];
int ans[ 25 ][ 1<<20 ];
int solve( int ball , int left = 0 , int right = n - 1 , int node = 0 , int depth = 1 ){
    ans[ depth ][ ball ] = node + 1;
    if( left == right ){
        return node;
    }
    int mid = (left + right)>>1, ans;
    if( tree[ node ] ){
        tree[ node ] = 0;
        ans = solve( ball , mid + 1 , right , 2 * node + 2 , depth + 1 );
    }
    else{
        tree[ node ] = 1;
        ans = solve( ball , left , mid , 2 * node + 1 , depth + 1 );
    }
    return ans;
}

void init( ){
    for( int i = 0 ; i < 4 * MAX ; ++i ) tree[ i ] = 0;
}

int main(){
    int t , d , ball;
    init();
    n = 1<<19;
    for( int i = 1 ; i <= 1<<19 ; ++i ) solve( i );
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d %d" , &d , &ball );
        printf("%d\n" , ans[ d ][ ball ] );
    }
    return 0;
}
