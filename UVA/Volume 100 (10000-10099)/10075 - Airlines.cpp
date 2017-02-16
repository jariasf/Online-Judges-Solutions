/***********************************************
 ***Problema: Airlines
 ***ID: 10075
 ***Juez: UVA
 ***Tipo: Floyd Warshall ,Great Circle Distance
 ***Autor: Jhosimar George Arias Figueroa
 ***********************************************/

#include <stdio.h>
#include <cstring>
#include <math.h>

#define MAX 105
int ady[ MAX ][ MAX ];
char cities[ MAX ][ 30 ];
int V , ncities;

int get_Id( char *s){
    for( int i = 0 ; i < ncities ; ++i ){
         if( strcmp( s , cities[ i ] ) == 0 )return i;
    }
    strcpy( cities[ ncities ] , s );
    return ncities++;
}

struct City{
    double lat , lon;
    City( double l , double ll ): lat( l ) , lon( ll ){}
};

#define R 6378
double rad = 3.141592653589793 / 180.;
int greatCircle( double a_lat , double a_long , double b_lat , double b_long ){
    double t = cos( a_lat ) * cos( b_lat ) * cos( a_long - b_long ) + sin( a_lat ) * sin( b_lat );
    if( t < -1 )t = -1;
    if( t > 1 ) t = 1;
    return (int)floor( acos( t ) * R + 0.5 );
}


#define INF 999999999
void Init(){
    for( int i = 0 ; i < V ; ++i ){
        for( int j = 0 ; j < V ; ++j ){
             ady[ i ][ j ] = INF;
        }
        ady[ i ][ i ] = 0;
    }
}

void Floyd(){
    for( int k = 0 ; k < V ; ++k ){
        for( int i = 0 ; i < V ; ++i ){
            for( int j = 0 ; j < V ; ++j ){

                int t = ady[ i ][ k ] + ady[ k ][ j ];
                if( ady[ i ][ j ] > t ){
                    ady[ i ][ j ] = t;
                }
            }
        }
    }
}

int main(){
    int E, Q , u , v , q = 1;
    char s[ 30 ] , s2[ 30 ];
    double lat, lon;
    while( scanf("%d %d %d" ,&V ,&E, &Q ) && ( V + E + Q ) ){
        if( q > 1 )printf("\n");
        ncities = 0;
        double vv[ V ][ 2 ];
        for( int i = 0 ; i < V ; ++i ){
            scanf("%s %lf %lf" , &s , &lat , &lon );
            u = get_Id( s );
            vv[ u ][ 0 ] = lat*rad;
            vv[ u ][ 1 ] = lon*rad;
        }

        Init();

        while( E-- ){
            scanf("%s %s", &s, &s2 );
            u = get_Id( s ); v = get_Id( s2 );
            ady[ u ][ v ] = greatCircle( vv[ u ][ 0 ] , vv[ u ][ 1 ] , vv[ v ][ 0 ] , vv[ v ][ 1 ] );

        }
        Floyd();
        printf("Case #%d\n" , q++ );
        while( Q-- ){
            scanf("%s %s" ,&s , &s2 );
            u = get_Id( s ); v = get_Id( s2 );
            if( ady[ u ][ v ] == INF ) printf("no route exists\n");
            else printf("%d km\n" , ady[ u ][ v ] );
        }
    }
    return 0;
}
