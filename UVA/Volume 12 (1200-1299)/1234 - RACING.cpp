/*****************************************
 ***Problema: RACING
 ***ID: 1234
 ***Juez: UVA
 ***Tipo: MST
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 100005
int uf[ MAX ] , V;
int Find( int x ){ return ( x == uf[ x ] )? x : uf[ x ] = Find( uf[ x ] ); }
void Union( int x , int y ){ uf[ Find( x ) ] = Find( y ); }
void MakeSet(){ for( int i = 1 ; i <= V ; ++i ) uf[ i ] = i; }
struct Edge{
    int u , v , w;
    bool operator < ( const Edge e1 ) const{
        return w > e1.w;
    }
    Edge(){}
}graph[ MAX  ];

int main(){
    int t , E , i , u , v, w , ans;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d %d" , &V , &E ) ){
        MakeSet();
        for( i = 0 ; i < E && scanf("%d %d %d" , &graph[ i ].u , &graph[ i ].v , &graph[ i ].w ); ++i );
        sort( graph , graph + E );
        ans = 0;
        for( i = 0 ; i < E ; ++i ){
            u = graph[ i ].u;
            v = graph[ i ].v;
            w = graph[ i ].w;
            if( Find( u ) != Find( v ) ) Union( u , v );
            else ans += w;
        }
        printf("%d\n" , ans );
    }
    scanf("%d" , &t );
    return 0;
}
