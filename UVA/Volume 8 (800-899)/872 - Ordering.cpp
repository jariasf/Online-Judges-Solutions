/*******************************************************
 ***Problema: Ordering
 ***ID: 872
 ***Juez: UVA
 ***Tipo: Graph Theory, Topological Sort, Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************************/

#include <stdio.h>
#include <algorithm>
#include <sstream>

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
        if( contraint[ in ][ output[ i ] - 'A'  ] ) return false;
    }
    return true;
}
bool possible;
void dfs( int len ){
    if( len == idx ){
        possible = true;
        putchar( output[ 0 ] );
        for( int i = 1 ; i < len ;++i ){
            printf(" %c", output[ i ] );
        }
        putchar( '\n' );
        //output[ len ] ='\0';
        //printf("%s\n", output );
        return;
    }

    for( int i = 0 ; i < idx ; ++i ){
        if( !used[ i ] && check( len , let[ i ] - 'A' ) ){
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
    int t, l;
    bool bb = false;
    scanf("%d", &t);
    gets( line );
    while( t-- ){
        gets( line );
        gets( line );

        if( bb ) putchar( '\n' );
        bb = true;
        idx = 0;
        for( int i = 0 ; line[ i ] ; ++i )
            if( isalpha( line[ i ] ) ) { let[ idx ] = line[ i ];  used[ idx++ ] = 0;}

        ///se ordena para sacar lexicograficamente
        sort( let, let + idx );
        memset( contraint , 0 , sizeof( contraint ) );

        gets( line );
        l = strlen( line );
        for( int i = 0 ; i < l ; ++i ){
             if( line[ i ] == '<' )line[ i ] = ' ';
        }

        line[ l ] = ' ';
        line[ l + 1 ] = '\0';
        stringstream ss( line );
        while( ss>>a>>b ) contraint[ a - 'A' ][ b - 'A' ] = 1;
        possible = false;
        dfs( 0 );
        if( !possible ) printf("NO\n");

    }

    return 0;
}
