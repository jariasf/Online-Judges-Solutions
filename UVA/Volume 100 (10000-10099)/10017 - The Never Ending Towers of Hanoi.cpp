/**********************************************
 ***Problema: The Never Ending Towers of Hanoi
 ***ID: 10017
 ***Juez: UVA
 ***Tipo: Recursion
 ***Autor: Jhosimar George Arias Figueroa
 **********************************************/

#include <stdio.h>

int len;
#define MAX 256
int A[ MAX ] , lenA , B[ MAX ], lenB , C[ MAX ],lenC;

void move(int n, int s , int i , int d  ){
    if( n > 0 ){
        move( n - 1 , s , d , i );
        if( len < 0 ) return;
        len--;
        if( s == 1 ){
            lenA--;
            if( d == 2 ){ B[ lenB++ ] = A[ lenA ]; }
            else if( d == 3 ){ C[ lenC++ ] = A[ lenA ]; }
        }
        else if( s == 2 ){
            lenB--;
            if( d == 1 ){ A[ lenA++ ] = B[ lenB ]; }
            else if( d == 3 ){ C[ lenC++ ] = B[ lenB ]; }
        }
        else if( s == 3 ){
            lenC--;
            if( d == 1 ){ A[ lenA++ ] = C[ lenC ]; }
            else if( d == 2 ){ B[ lenB++ ] = C[ lenC ]; }
        }
        printf("A=>");
        if( lenA > 0 )printf("  ");
        for( int j = 0 ; j < lenA ; ++j ) printf(" %d" , A[ j ] );
        printf("\nB=>");
        if( lenB > 0 )printf("  ");
        for( int j = 0 ; j < lenB ; ++j ) printf(" %d" , B[ j ] );
        printf("\nC=>");
        if( lenC > 0 )printf("  ");
        for( int j = 0 ; j < lenC ; ++j ) printf(" %d" , C[ j ] );
        printf("\n\n");

        if( len < 0 ) return;
        move( n - 1 , i , s , d );
        if( len < 0 ) return;
    }
}

int main(){
    int n , t = 1;
    while( scanf("%d %d" , &n , &len ) , n | len ){
        for( int i = n ; i > 0 ; --i ) A[ n - i ] = i;
        len--;
        lenA = n; lenB = lenC = 0;
        printf("Problem #%d\n\n" , t++ );
        printf("A=>");
        if( lenA > 0 )printf("  ");
        for( int j = 0 ; j < lenA ; ++j ) printf(" %d" , A[ j ] );
        printf("\nB=>");
        if( lenB > 0 )printf("  ");
        for( int j = 0 ; j < lenB ; ++j ) printf(" %d" , B[ j ] );
        printf("\nC=>");
        if( lenC > 0 )printf("  ");
        for( int j = 0 ; j < lenC ; ++j ) printf(" %d" , C[ j ] );
        printf("\n\n");
        move( n , 1 , 2 , 3 );
    }
    return 0;
}
