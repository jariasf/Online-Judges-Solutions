/*************************************************
 ***Problema: Automatic correction of misspellings
 ***ID: 11048
 ***Juez: UVA
 ***Tipo: Strings
 ***Autor: Jhosimar George Arias Figueroa
 *************************************************/

#include <stdio.h>
#include <cstring>

int main(){

    int n , q;
    scanf("%d" , &n );

    char dict[10000][26], word[256];
    for( int i = 0 ; i < n ; ++i ) scanf("%s" , &dict[ i ] );
    scanf("%d" , &q );
    while( q-- ){
        scanf("%s" , &word );
        for( int i = 0 ; i < n ; ++i ){
            if( strcmp( dict[ i ] , word ) == 0 ){
                printf("%s is correct\n" , word );
                goto done;
            }
        }

        for( int i = 0 ; i < n ; ++i ){
            char *p = dict[ i ], *q = word;

            while( *p == *q )p++, q++;

            if( *p && strcmp( p + 1 , q ) == 0 )goto found;
            if( *q && strcmp( p , q + 1 ) == 0 )goto found;
            if( *p && *q && strcmp( p + 1 , q + 1 ) == 0 )goto found;
            if( p[ 0 ] && p[ 1 ] && p[ 0 ] == q[ 1 ] && p[ 1 ] == q[ 0 ] && strcmp( p + 2 , q + 2 ) == 0 ) goto found;
            continue;
            found: printf("%s is a misspelling of %s\n", word, dict[i] );
            goto done;
        }
        printf("%s is unknown\n", word);
        done:;
    }

    return 0;
}
