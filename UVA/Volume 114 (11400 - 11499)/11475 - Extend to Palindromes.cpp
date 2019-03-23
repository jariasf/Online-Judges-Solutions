/*****************************************
 ***Problema: Extend to Palindromes
 ***ID: 11475
 ***Juez: UVA
 ***Tipo: KMP | Palindromes
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
#define MAX 100005
char s1[ MAX ] , s2[ MAX ];
int len , b[ MAX ];

void preprocess(){
    int i = 0, j = -1; b[ 0 ] = -1;
    while( i < len ){
        while( j >= 0 && s2[ i ] != s2[ j ] ) j = b[ j ];
        i++;j++;
        b[ i ] = j;
    }
}

void solve(){
    int i = 0, j = 0;
    while( i < len ){
        while( j >= 0 && s2[ j ] != s1[ i ] ) j = b[ j ];
        i++; j++;
    }
    for( ; j < len ; ++j ) printf("%c" , s2[ j ] );
    printf("\n");
}

int main(){
    int i , j;
    while( scanf("%s" , &s1 ) != EOF ){
        len= strlen( s1 );
        for( i = len - 1 , j = 0 ; i >= 0 ; --i , ++j ) s2[ j ] = s1[ i ];
        preprocess();
        printf("%s" , s1 );
        solve();
    }
    return 0;
}
