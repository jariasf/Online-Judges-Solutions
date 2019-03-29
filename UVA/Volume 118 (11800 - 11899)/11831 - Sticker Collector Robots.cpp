/*****************************************
 ***Problema: Sticker Collector Robots
 ***ID: 11831
 ***Juez: UVA
 ***Tipo: Simulation, Implicit graph
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX 105
char ady[ MAX ][ MAX ];
int f , c , s;

//N W S E
int dx[ 4 ] = { -1 ,  0 , 1 , 0 };
int dy[ 4 ] = {  0 , -1 , 0 , 1 };

int simulate( int x , int y , int dir ){
    int nx , ny , i , ans = 0;
    char command;
    for( i = 0 ; i < s && scanf(" %c" , &command ) ; ++i ){
        if( command == 'D' ){
            dir = ( dir - 1 + 4 ) % 4;
        }
        else if( command == 'E'){
            dir = ( dir + 1 ) % 4;
        }
        else{
            nx = x + dx[ dir ]; ny = y + dy[ dir ];
            if( nx >= 0 && nx < f && ny >= 0 && ny < c && ady[ nx ][ ny ] != '#' ){
                if( ady[ nx ][ ny ] == '*' ) ans++;
                ady[ nx ][ ny ] = '.';
                x = nx;
                y = ny;
            }
        }
    }
    return ans;
}

int main(){
    int x , y , i, j;
    while( scanf("%d %d %d" , &f , &c , &s ) , f | c | s ){
        for( i = 0 ; i < f ; ++i ){
            for( j = 0 ; j < c && scanf( " %c" , &ady[ i ][ j ] ) ; ++j ){
                if( ady[ i ][ j ] - 'A' >= 0 && ady[ i ][ j ] - 'A' <= 'Z' - 'A' ){
                    x = i; y = j;
                }
            }
        }
        printf( "%d\n" , simulate( x , y , ( ady[ x ][ y ] == 'N' )?0: ( ady[ x ][ y ] == 'O')?1:( ady[ x ][ y ] == 'S') ?2:3 ) );
    }
    return 0;
}
