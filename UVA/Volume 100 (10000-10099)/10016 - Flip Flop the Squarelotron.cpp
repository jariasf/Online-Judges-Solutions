/*****************************************
 ***Problema: Flip-Flop the Squarelotron
 ***ID: 10016
 ***Juez: UVA
 ***Tipo: Array Manipulation
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

#define MAX 110
int a[MAX ][ MAX ] , ring , n, tmp;

void upsideDown( int ring , int len ){
    int l = len - ring;
    for( int i = ring ; i < len ; ++i ){
        tmp = a[ ring ][ i ];
        a[ ring ][ i ] = a[ len - 1 ][ i ];
        a[ len - 1 ][ i ] = tmp;
    }
    l -= 2;
    //extremos de fila

    for( int i = ring + 1, j = 1; l > 0 ; ++i , j++ , l-= 2 ){
        tmp = a[ i ][ ring ];
        a[ i ][ ring ] = a[ len - j - 1 ][ ring ];
        a[ len - j - 1 ][ ring ] = tmp;

        tmp = a[ i ][ len - 1 ];
        a[ i ][ len - 1 ] = a[ len - j - 1 ][ len - 1 ];
        a[ len - j - 1 ][ len - 1 ] = tmp;
    }

}

void leftRight( int ring , int len ){
    int l = len - ring;
    for( int i = ring ; i < len ; ++i ){
        tmp = a[ i ][ ring ];
        a[ i ][ ring ] = a[ i ][ len - 1 ];
        a[ i ][ len - 1 ] = tmp;
    }
    l -= 2;
    //extremos de fila
    for( int i = ring + 1, j = 1; l > 0 ; ++i , j++ , l-=2 ){
        tmp = a[ ring ][ i ];
        a[ ring ][ i ] = a[ ring ][ len - j - 1 ];
        a[ ring ][ len - j - 1 ] = tmp;

        tmp = a[ len - 1 ][ i];
        a[ len - 1 ][ i ] = a[ len - 1 ][ len - j - 1 ];
        a[ len - 1 ][ len - j - 1 ] = tmp;
    }
}


void mainDiagonal( int ring , int len ){
    for( int i = ring ; i < len - 1 ; ++i ){
        tmp = a[ ring ][ i ];
        a[ ring ][ i ] = a[ i ][ ring ];
        a[ i ][ ring ] = tmp;

        tmp = a[ len - 1 ][ i ];
        a[ len - 1 ][ i  ] = a[ i ][ len - 1 ];
        a[ i ][ len - 1  ] = tmp;
    }

}

void mainInverse( int ring , int len ){
    for( int i = len - 1 , j = ring ; i > ring ; --i , j++ ){
        tmp = a[ ring ][ i ];
        a[ ring ][ i ] = a[ j ][ len - 1 ];
        a[ j ][ len - 1 ] = tmp;

        tmp = a[ len - 1 ][ i ];
        a[ len - 1 ][ i ] = a[ j ][ ring ];
        a[ j ][ ring  ] = tmp;
    }
}

void print(){
    bool f;
    for( int i = 0 ; i < n ; ++i ){
        f = false;
        for( int j = 0 ; j < n ; ++j ){
            if( f ) putchar(' ');
            printf("%d", a[ i ][ j ]);
            f = true;
        }
        printf("\n");
    }
}

int main(){
    int t , k ,op;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d" , &n );
        for( int i = 0 ;i < n ; ++i ){
            for( int j = 0 ; j < n ; ++j ){
                scanf("%d" , &a[ i ][ j ] );
            }
        }
        ring= n/2;
        if( n & 1 ) ring++ ;

        for( int i = 0 ; i < ring ; ++i ){
            scanf("%d" , &k );
            while( k-- ){
                scanf( "%d" , &op );
                if( op == 1 )upsideDown( i , n - i );
                else if( op == 2 ) leftRight( i , n - i );
                else if( op == 3 ) mainDiagonal( i , n - i );
                else mainInverse( i , n - i );
            }
        }
        print();
    }
    return 0;
}
