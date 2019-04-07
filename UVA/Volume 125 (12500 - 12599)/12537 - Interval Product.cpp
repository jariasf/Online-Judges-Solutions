/*****************************************
 ***Problema: Interval Product
 ***ID: 12537
 ***Juez: UVA
 ***Tipo: Segment Tree
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#define MAX 100005
int tree[ MAX * 4] , n;

void update( int pos , int by , int left = 0 , int right = n - 1, int node = 0 ){
    if( left == right ){
        tree[ node ] = by;
        return;
    }
    int mid = ( left + right )/2;
    if( pos > mid ){
        update( pos , by , mid + 1 , right , 2 * node + 2 );
    }
    else{
        update( pos , by , left , mid , 2 * node + 1 );
    }
    tree[ node ] = tree[ 2 * node + 1 ] * tree[ 2 * node + 2 ];
}

int query( int from , int to , int left = 0 , int right = n - 1, int node = 0 ){
    if( left >= from && right <= to ){
        return tree[ node ];
    }
    int mid = ( left + right )/2, res = 1;
    if( from <= mid ){
        res *= query( from , to , left , mid , node * 2 + 1 );
    }
    if( to > mid ){
        res *= query( from , to , mid + 1 , right , 2 * node + 2 );
    }
    return res;
}

int main(){
    char c;
    int Q , x , i , a , b;
    while( scanf("%d %d" , &n , &Q ) != EOF ){
        for( i = 0 ; i < n && scanf("%d" , &x ) ; ++i ){
            if( x < 0 ) x = -1;
            else if( x > 0 ) x = 1;
            else x = 0;
            update( i , x );
        }

        while( Q-- > 0 && scanf(" %c" , &c ) ){
            scanf("%d %d" , &a , &b );
            if( c == 'C' ){
                if( b > 0 ) b = 1;
                else if( b < 0 ) b = -1;
                else b = 0;
                update( a - 1 , b );
            }
            else{
                x = query( a - 1 , b - 1 );
                if( x > 0 ) putchar('+');
                else if( x < 0 ) putchar('-');
                else putchar('0');
            }
        }
        printf("\n");
    }

    return 0;
}
