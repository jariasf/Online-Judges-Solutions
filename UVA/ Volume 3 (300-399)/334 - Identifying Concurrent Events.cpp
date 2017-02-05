/*****************************************
 ***Problema: Identifying Concurrent Events
 ***ID: 334
 ***Juez: UVA
 ***Tipo: Graph Theory, Floyd Transitive Closure
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

#define MAX 305
int ady[ MAX ][ MAX ] , V;

void TransitiveClosure(){

    for( int k = 0 ; k < V ; ++k ){
        for( int i = 0 ; i < V ; ++i ){
            for( int j = 0 ; j < V ; ++j ){
                ady[ i ][ j ] |= ady[ i ][ k ] & ady[ k ][ j ];
            }
        }
    }
}

char cities[ MAX ][ 40 ];
int numcities;
int get_Id( char *s ){

    for( int i = 0 ; i < numcities ; ++i ){
        if( strcmp( s , cities[ i ] ) == 0 ) return i;
    }
    strcpy( cities[ numcities ] ,s );
    return numcities++;
}

char *get_String( int id ){

    for( int i = 0 ; i < numcities ; ++i ){
        if( id == i ) return cities[ i ];
    }
}

int main(){
    int q = 1, n , E ,ant , id;
    char s[ 40 ] , s1[ 40 ];
    while( scanf("%d" , &n ) && n ){
        numcities = 0;

        while( n-- ){

            scanf("%d" , &E );

            for( int i = 0 ; i < E ; ++i ){
                 scanf("%s" , &s );
                 id = get_Id( s );

                 if( i != 0 ){
                     ady[ ant ][ id ] = 1;
                 }
                 ant = id;
            }

        }
        V = numcities;
        scanf("%d" , &E );
        while( E-- ){
            scanf("%s %s" , &s , &s1 );
            ady[ get_Id( s ) ][ get_Id( s1 ) ] = 1;
        }

        TransitiveClosure();
        int total_events = V * ( V - 1 ) / 2;
        int x[ 2 ] , y[ 2 ] , idx = 0;
        for( int i = 0 ; i < V ; ++i ){
            for( int j = i + 1 ; j < V ; ++j ){
                if( ady[ i ][ j ] == 1 ||ady[ j ][ i ] == 1  ) total_events--;
                else{
                    if( idx < 2 ){
                        x[ idx ] = i;
                        y[ idx++ ] = j;
                    }

                }
            }
        }

        printf("Case %d, ", q++ );
        if( total_events == 0 )printf("no concurrent events.\n");
        else if( total_events == 1 ){
             printf("1 concurrent events:\n");
             printf("(%s,%s) \n" , get_String( x[ 0 ] ) , get_String( y[ 0 ] ) );
        }
        else{
             printf("%d concurrent events:\n" , total_events );
             printf("(%s,%s) (%s,%s) \n" , get_String( x[ 0 ] ) , get_String( y[ 0 ] ) , get_String( x[ 1 ] ) , get_String( y[ 1 ] ) );

        }
        memset( ady , 0 ,sizeof( ady ) );
    }

    return 0;
}
