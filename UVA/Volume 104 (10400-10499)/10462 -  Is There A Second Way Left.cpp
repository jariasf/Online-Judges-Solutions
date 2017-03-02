/*****************************************
 ***Problema: Is There A Second Way Left
 ***ID: 10462
 ***Juez: UVA
 ***Tipo: Graph Theory , MST
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
#define MAX 105
int uf[ MAX ];

int Find( int x ){
    return ( uf[ x ] == x ) ? x : uf[ x ] = Find( uf[ x ] );
}

void Union( int x , int y ){
    uf[ Find( x ) ] = Find( y );
}

struct Arista{
    int u , v , w;
    bool mst;
    Arista( int uu , int vv , int ww , bool mstt ): u( uu ) , v( vv ) , w( ww ) , mst( mstt ){}
    Arista(){}
    bool operator <( const Arista &a ) const{
        return w < a.w;
    }
}graph[ MAX ];

int main(){
    int t, V , E , u , v , w , first , second , aux , size;
    scanf("%d" , &t );
    for( int q = 1 ; q <= t ; ++q ){
        first = size = 0;
        scanf("%d %d" , &V , &E );
        for( int i = 0 ; i < E ; ++i ){
            scanf("%d %d %d" , &u , &v , &w );
            graph[ i ] = Arista( u , v , w , false );
        }
        sort( graph , graph + E );
        for( int i = 1 ; i <= V ; ++i ) uf[ i ] = i;

        for( int i = 0 ; i < E ; ++i ){
            u = graph[ i ].u; v = graph[ i ].v; w = graph[ i ].w;
            if( Find( u ) != Find( v ) ){
                first += w;
                size++;
                graph[ i ].mst = true;
                Union( u , v );
            }
        }
        printf("Case #%d : " , q );
        if( size != V - 1 ){
            printf("No way\n");
            continue;
        }
   
        ///vemos aristas del MST y probamos nuevo MST eliminando una de dichas aristas
        second = 1000000;
        for( int i = 0 ; i < E ; ++i ){
            if( !graph[ i ].mst ) continue;
            aux = 0; size = 0;
            for( int j = 1 ; j <= V ; ++j ) uf[ j ] = j;

            for( int j = 0 ; j < E ; ++j ){
                if( i == j )continue;
                u = graph[ j ].u; v = graph[ j ].v; w = graph[ j ].w;
                if( Find( u ) != Find( v ) ){
                    aux += w;
                    size++;
                    Union( u , v );
                }
            }
            ///si tengo todos los nodos, puede ser q la arista q halla eliminado sea la unica
            ///coneccion a ese nodo
            if( size == V - 1 && second > aux ) second = aux;
        }
        if( second == 1000000 )printf("No second way\n");
        else printf("%d\n" , second );

    }
    return 0;
}
