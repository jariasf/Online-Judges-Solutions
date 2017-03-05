/*****************************************
 ***Problema: Friends
 ***ID: 10608
 ***Juez: UVA
 ***Tipo: Union Find
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#define MAX 30005

int parent[ MAX ] , V;

void MakeSet(){
    for( int i = 0 ; i < V ; ++i ) parent[ i ] = i;
}

int Find( int x ){
    return ( parent[ x ] == x )? x : parent[ x ] = Find( parent[ x ] );
}
void Union( int x , int y ){
    parent[ Find( x ) ] = Find( y );
}

int numElem[ MAX ];
int main(){
    int t , E , x , y, ans;
    scanf("%d" , &t );

    while( t-- ){
        scanf("%d %d" , &V , &E );
        MakeSet();
        while( E-- ){
            scanf("%d %d" , &x , &y );
            Union( x - 1 , y - 1 );
        }

        //Cuento numero de elementos por conjunto
        memset( numElem , 0 , sizeof( numElem ) );
        for( int i = 0 ; i < V ; ++i ){
            numElem[ Find( i ) ]++;
        }

        //Hallo el maximo
        ans = 0;
        for( int i = 0 ; i < V ; ++i ) ans = ( ans < numElem[ i ] )?numElem[ i ]: ans;
        printf("%d\n" , ans );
    }

    return 0;
}
