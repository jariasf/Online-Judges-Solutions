/****************************************************
 ***Problema: Following Orders
 ***ID: 124
 ***Juez: UVA
 ***Tipo: Graph Theory, Topological Sort, Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 *****************************************************/

#include <stdio.h>
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;
#define MAX 35
int used[ MAX ];
///reglas representadas con entero a < b -> [ 0 ][ 1 ] = true
int contraint[ MAX ][ MAX ];
char let[ MAX ];
int idx;
char output[ MAX + 5 ];
bool check( int len , int in ){
    //si x ejemplo tengo a b f g
    //contrait a <b b < f
    //primero entra "a" y se compara con "b" "f" y "g"
    //contradiccion al  contrait es q a > b x ello output va en indice j
    for( int i = 0 ; i < len ; ++i ){
        if( contraint[ in ][ output[ i ] - 'a'  ] ) return false;
    }
    return true;
}

void dfs( int len ){
    if( len == idx ){
        output[ len ] ='\0';
        printf("%s\n", output );
        return;
    }

    for( int i = 0 ; i < idx ; ++i ){
        if( !used[ i ] && check( len , let[ i ] - 'a' ) ){
            output[ len ] = let[ i ];
            used[ i ] = 1;
            dfs( len + 1 );
            used[ i ] = 0;
        }
    }
}

int main(){
    char line[ MAX + 5 ];
    char a ,b;
    int l;
    bool bb = false;
    while( gets( line ) ){
        if( bb ) putchar( '\n' );
        bb = true;
        idx = 0;
        for( int i = 0 ; line[ i ] ; ++i ){
            if( isalpha( line[ i ] ) ) {
                let[ idx ] = line[ i ];
                used[ idx++ ] = 0;
            }
        }
        //se ordena para sacar lexicograficamente
        sort( let, let + idx );
        memset( contraint , 0 , sizeof( contraint ) );

        gets( line );
        strcat( line, " ");
        stringstream ss( line );
        while( ss>>a>>b ) contraint[ a - 'a' ][ b - 'a' ] = 1;
        dfs( 0 );
    }

    return 0;
}
