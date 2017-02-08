/*****************************************
 ***Problema: Bowling
 ***ID: 584
 ***Juez: UVA
 ***Tipo: Ad hoc simulation
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

char rolls[ 105 ];
int n;

void solve(){
    int scores[ 105 ] = { 0 };
    int prev = 0;
    for( int i = 0 , j = 0 ; i < n ; ++i ){

        if(  '0' <= rolls[ i ] && rolls[ i ] <= '9' ){
            scores[ i ] = rolls[ i ] - '0';
            j++;
            if( j == 2 ){
                j = 0;

            }
        }
        else{
            if( j != 0 ){
                scores[ i ] = 10 - prev;
                j =0;
            }else scores[ i ] = 10;
        }
        prev = scores[ i ];
    }
    int ans = 0, frames = 0;
    for( int i = 0 , j = 0 ; i < n && frames < 10 ; ++i ){
        ans += scores[ i ];
        if( rolls[ i ] == 'X'){
            ans += scores[ i + 1 ] + scores[ i + 2 ];
            frames++;
            j = 0;
        }else if( rolls[ i ] == '/'){
            ans += scores[ i + 1 ];
            j = 0;
            frames++;
        }
        else{
            j++;
            if( j == 2 ){
                j = 0;
                frames++;
            }
        }
    }
    printf("%d\n", ans );
}

int main(){
    char s[ 105 ];
    int l;
    while( gets( s ) , s[ 0 ] != 'G'){
        l  = strlen( s );
        n = 0;
        for( int i = 0 ; i < l ; ++i ){
            if( s[ i ] == ' ')continue;
            rolls[ n++ ] = s[ i ];
        }
        solve();
    }

    return 0;
}
