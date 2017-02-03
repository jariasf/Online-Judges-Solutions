/*****************************************
 ***Problema: Laser Lines
 ***ID: 184
 ***Juez: UVA
 ***Tipo: Geometria
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
#include<math.h>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX 303

struct Point{
    int x , y;
    Point( int xx , int yy ): x( xx ) , y( yy ){}
    Point(){}

}v[ MAX ];

vector<Point> line[ MAX ];

bool cmp( Point p1 , Point p2 ){
    return ( p1.x < p2.x || ( p1.x == p2.x && p1.y < p2.y ) );
}
bool f( Point p1 , Point p2 ){
    return ( p1.x == p2.x && p1.y == p2.y );

}
int main(){
    int len , cnt , tam ;
    bool seen[ MAX ][ MAX ];

    while( scanf("%d %d" , &v[ 0 ].x , &v[ 0 ].y ) , v[ 0 ].x | v[ 0 ].y ){
        len = 1;
        memset( seen , 0 , sizeof( seen ) );

        while( scanf("%d %d" , &v[ len ].x , &v[ len ].y ), v[ len ].x | v[ len++ ].y );
        len--;
        sort( v , v + len , cmp );
        len = unique( v , v+len , f ) - v;

        tam = 0;
        for( int i = 0 ; i < len ; ++i ){
            for( int j =  i + 1 ; j < len ; ++j ){
                cnt = 2;
                if( seen[ i ][ j ] )continue;
                int k = 0;
                for(  ; k < j ; ++k ){
                    if( k != i && 
                        (( v[k].y - v[i].y ) * ( v[j].x - v[i].x ) - ( v[k].x - v[i].x )*( v[j].y - v[i].y ) == 0)){
                        k = -1;
                        break;
                    }
                }
                if( k == -1 )continue;
                for( k = j + 1 ; k < len ; ++k ){
                    if( ( v[ k ].y - v[ i ].y ) * ( v[ j ].x - v[ i ].x ) - ( v[ k ].x - v[ i ].x )*( v[ j ].y - v[ i ].y ) == 0){
                        cnt++;
                        seen[ i ][ k ] = seen[ j ][ k ] = 1;
                        line[ tam ].push_back( Point( v[ k ].x , v[ k ].y ) );
                    }
                }
                if( cnt >= 3 ){
                    line[ tam ].push_back( Point( v[ i ].x , v[ i ].y ) );
                    line[ tam ].push_back( Point( v[ j ].x , v[ j ].y ) );
                    tam++;
                }
                seen[ i ][ j ] = 1;
            }
        }
        if( tam == 0 ) puts("No lines were found");
        else{
            puts("The following lines were found:");

            for( int i = 0 ; i < tam ; ++i ){
                printf("(%4d,%4d)(%4d,%4d)", 
						line[ i ][ line[ i ].size() - 2 ].x, 
						line[ i ][ line[ i ].size() - 2 ].y, 
						line[ i ][ line[ i ].size() - 1 ].x,
						line[ i ][ line[ i ].size() - 1 ].y);
                for( int j = 0 ; j < line[ i ].size() - 2 ; ++j ){
                    printf("(%4d,%4d)" , line[ i ][ j ].x,line[ i ][ j ].y);
                }
                putchar('\n');
            }
        }
        for( int i = 0 ; i < tam ; ++i )line[ i ].clear();

    }
}
