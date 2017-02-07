/*****************************************
 ***Problema: Humble Numbers
 ***ID: 443
 ***Juez: UVA
 ***Tipo: Number Theory, dp
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

/*
The 4011th humble number is 231525000.
The 412th humble number is 18000.
The 313th humble number is 7938.
*/
#include <stdio.h>

#define MAX 5845
long long dp[ MAX ] = { 1 };
inline long long Min( long long a , long long b ){ return a < b ? a : b;}

void solve(){
    int p1 = 0 , p2 = 0 , p3 = 0 , p4 = 0, mini, a = 2 , b = 3 , c = 5 , d = 7;
    for( int i = 1 ; i < MAX ; ++i ){
        dp[ i ] = Min( Min( dp[ p1 ] * a , dp[ p2 ] * b ) , Min( dp[ p3 ] * c , dp[ p4 ] * d ) );
        if( dp[ i ] == dp[ p1 ] * a ) p1++;
        if( dp[ i ] == dp[ p2 ] * b ) p2++;
        if( dp[ i ] == dp[ p3 ] * c ) p3++;
        if( dp[ i ] == dp[ p4 ] * d ) p4++;
    }
}

const char * getSuffix( int n ){
    if( n % 10 == 1 && n % 100 != 11 ) return "st";
    if( n % 10 == 2 && n % 100 != 12 ) return "nd";
    if( n % 10 == 3 && n % 100 != 13 ) return "rd";
    return "th";
}

int main(){
    solve();
    int n;
    while( scanf("%d" , &n ) && n ){
        printf("The %d%s humble number is %lld.\n" , n , getSuffix( n ) ,  dp[ n - 1 ] );
    }

    return 0;
}
