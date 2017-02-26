/*****************************************
 ***Problema: Chessboard in FEN
 ***ID: 10284
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#define MAX 105
char s[ MAX ];
int ady[ 8 ][ 8 ];
int n = 8;

int cabx[ 8 ]={ -2 , -2 , -1 , -1 ,  1 , 1 ,  2 , 2 };
int caby[ 8 ]={ -1 ,  1 , -2 ,  2 , -2 , 2 , -1 , 1 };
int rx[ 4 ] = { 1 , -1 , 0 ,  0 };
int ry[ 4 ] = { 0 ,  0 , 1 , -1 };
int qx[ 8 ] = { 1 , -1 , 0 ,  0 , 1 , 1 , -1 , -1 };
int qy[ 8 ] = { 0 ,  0 , 1 , -1 , 1 , -1 , 1 , -1 };
int bx[ 4 ] = { 1 , 1 , -1 , -1 };
int by[ 4 ] = { 1 , -1 , 1 , -1 };

void queen( int x , int y ){
    for( int i = 0 ; i < 8 ; ++i ){
        int k = 0;
        while( 1 ){
            k++;
            int nx = k * qx[ i ] + x, ny = k * qy[ i ]+ y;
            if( nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && ( ady[ nx ][ ny ] == '.' || ady[ nx ][ ny ] == 1 ) ){
                ady[ nx ][ ny ] = 1;
            }
            else break;
        }
    }
}

void knight( int x , int y ){
    for( int i = 0 ; i < 8 ; ++i ){
        int nx = cabx[ i ] + x, ny = caby[ i ]+ y;
        if( nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && ady[ nx ][ ny ] == '.' ){
            ady[ nx ][ ny ] = 1;
        }
    }
}

void bishop( int x , int y ){
    for( int i = 0 ; i < 4 ; ++i ){
        int k = 0;
        while( 1 ){
            k++;
            int nx = k * bx[ i ] + x, ny = k * by[ i ]+ y;
            if( nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && ( ady[ nx ][ ny ] == '.' || ady[ nx ][ ny ] == 1 )){
                ady[ nx ][ ny ] = 1;
            }
            else break;
        }
    }
}

void rook( int x , int y ){
    for( int i = 0 ; i < 4 ; ++i ){
        int k = 0;
        while( 1 ){
            k++;
            int nx = k * rx[ i ] + x, ny = k * ry[ i ]+ y;
            if( nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && ( ady[ nx ][ ny ] == '.' || ady[ nx ][ ny ] == 1 )){
                ady[ nx ][ ny ] = 1;
            }
            else break;
        }
    }
}

void peon( int x , int y , bool color ){

    if( color ){ // si negro
        for( int i = 0 ; i < 2 ; ++i ){
            int nx = bx[ i ] + x, ny = by[ i ]+ y;
            if( nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && ady[ nx ][ ny ] == '.' ){
                ady[ nx ][ ny ] = 1;
            }
        }
    }
    else{
        for( int i = 2 ; i < 4 ; ++i ){
            int nx = bx[ i ] + x, ny = by[ i ]+ y;
            if( nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && ady[ nx ][ ny ] == '.' ){
                ady[ nx ][ ny ] = 1;
            }
        }
    }
}

void king( int x , int y ){
    for( int i = 0 ; i < 8 ; ++i ){
        int nx = qx[ i ] + x, ny = qy[ i ] + y;
        if( nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && ady[ nx ][ ny ] == '.' ){
            ady[ nx ][ ny ] = 1;
        }
    }
}

int main(){
    int l, fila , col;
    while( scanf("%s" , &s ) != EOF ){
        l = strlen( s );
        fila = col = 0;
        for( int i = 0 ; i < l ; ++i ){
            if( s[ i ] == '/' ){
                col = 0;
                fila++;
                continue;
            }
            if( '0' <= s[ i ] && s[ i ] <= '8' ){
                for( int j = 0 ; j < ( s[ i ] - '0' ) ; ++j ) ady[ fila ][ col++ ] = '.';
            }
            else ady[ fila ][ col++ ] = s[ i ];
        }

        for( int i = 0 ; i < 8 ; ++i ){
            for( int j = 0 ; j < 8 ; ++ j ){
                if( ady[ i ][ j ] == 'k' || ady[ i ][ j ] == 'K' )king( i , j );
                else if( ady[ i ][ j ] == 'n' || ady[ i ][ j ] == 'N' )knight( i , j );
                else if( ady[ i ][ j ] == 'p' )peon( i , j , 1 );
                else if( ady[ i ][ j ] == 'P' )peon( i , j , 0 );
                else if( ady[ i ][ j ] == 'r' || ady[ i ][ j ] == 'R' )rook( i , j );
                else if( ady[ i ][ j ] == 'q' || ady[ i ][ j ] == 'Q' )queen( i , j );
                else if( ady[ i ][ j ] == 'b' || ady[ i ][ j ] == 'B' )bishop( i , j );
            }
        }

        int ans = 0;
        for( int i = 0 ; i < 8 ; ++i ){
            for( int j = 0 ; j < 8 ; ++ j ){
                if( ady[ i ][ j ] == '.')ans++;
            }
        }
        printf("%d\n" , ans );
    }

    return 0;
}
