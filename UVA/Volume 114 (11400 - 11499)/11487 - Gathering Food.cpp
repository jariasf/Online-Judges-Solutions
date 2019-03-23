/*****************************************
 ***Problema: Gathering Food
 ***ID: 11487
 ***Juez: UVA
 ***Tipo: DP
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 13
#define MOD 20437
#define pii pair< int , int >
#define mp make_pair
#define INF 1<<30
int lenPath[ 26 ];
char ady[ MAX ][ MAX ], table[ MAX ][ MAX ];
int n;
int dx[ 4 ] = { 0 , 0 , 1 , -1 };
int dy[ 4 ] = { 1 , -1 , 0 , 0 };

//Con la s rutas mas cortas halladas, hago el conteo usando DP
int dp[ MAX ][ MAX ][ 27 ][ 105 ];
int solve( int x , int y , int letter , int len ){
    if( len > lenPath[ letter ] ) return 0;
    if( letter == ady[ x ][ y ] - 'A' && len == lenPath[ letter ] )return 1;
    if( dp[ x ][ y ][ letter ][ len ] != -1 ) return dp[ x ][ y ][ letter ][ len ];
    int i , nx , ny;
    int ans = 0;
    for( i = 0 ; i < 4 ; ++i ){
        nx = dx[ i ] + x;
        ny = dy[ i ] + y;
        if( nx >= 0 && ny >= 0 && nx < n && ny < n && ady[ nx ][ ny ] != '#'){
            if( ady[ nx ][ ny ] == '.' || ady[ nx ][ ny ] - 'A' == letter ){
                ans =( ans % MOD + solve( nx , ny , letter , len + 1 ) % MOD ) % MOD;
            }
        }
    }
    return dp[ x ][ y ][ letter ][ len ] = ans;
}

//Hallamos las rutas mas cortas entre A -> B , B -> C , etc
struct Data{
    int x , y , d;
    Data( int xx , int yy , int dd ): x( xx ) , y( yy ) , d( dd ){}
};

int visto[ MAX ][ MAX ] , pos[ 27 ][ 2 ];
int shortest( int x , int y , int letter )
{
    memset( visto , 0 , sizeof( visto ) );
    queue< Data > Q;
    Q.push( Data( x , y , 0 ) );
    visto[ x ][ y ] = 1;
    int i , nx , ny;
    while( !Q.empty() ){
        Data act = Q.front(); Q.pop();
        for( i = 0 ; i < 4 ; ++i ){
            nx = dx[ i ] + act.x;
            ny = dy[ i ] + act.y;
            if( nx >= 0 && ny >= 0 && nx < n && ny < n && table[ nx ][ ny ] != '#' && !visto[ nx ][ ny ] ){
                if( table[ nx ][ ny ] == '.' ){
                    Q.push( Data( nx , ny , act.d + 1 ) );
                    visto[ nx ][ ny ] = 1;
                }
                else if( table[ nx ][ ny ] - 'A' == letter )return act.d + 1;
            }
        }
    }
    return -1;
}

int main(){
    int q = 1 , xini , yini , i , j , maxi, ans1 , ans2 ;
    while( scanf("%d" , &n ) , n ){
        maxi = 0;
        for( i = 0 ; i < n ; ++i ){
            scanf("%s" , &ady[ i ] );
            for( j = 0 ; j < n ; ++j ){
                if( ady[ i ][ j ] >= 'A' && ady[ i ][ j ] <= 'Z'){
                    pos[ ady[ i ][ j ] - 'A' ][ 0 ] = i;
                    pos[ ady[ i ][ j ] - 'A' ][ 1 ] = j;
                    maxi = max( maxi , ady[ i ][ j ] - 'A' );
                }
                if( ady[ i ][ j ] == 'A' ){
                    xini = i;
                    yini = j;
                }
            }
        }
        //hallo rutas mas cortas de A -> B -> C -> D -> E -> F...
        memset( lenPath , 0 , sizeof( lenPath ) );
        memcpy( table , ady , sizeof( ady ) );

        ans1 = 0;
        for( i = 1 ; i <= maxi ; ++i ){
            lenPath[ i ] = shortest( pos[ i - 1 ][ 0 ] , pos[ i - 1 ][ 1 ] , i );
            table[ pos[ i - 1 ][ 0 ] ][ pos[ i - 1 ][ 1 ] ] = '.';
            if( lenPath[ i ] == -1 ) break;
            ans1 += lenPath[ i ];
        }

        printf("Case %d: " , q++ );
        if( i != maxi + 1 )puts("Impossible");
        else{
            memset( dp , -1 , sizeof( dp ) );
            ans2 = 1;
            for( i = 1 ; i <= maxi ; ++i ){
                ans2 =( ans2 % MOD * solve( pos[ i - 1 ][ 0 ] , pos[ i - 1 ][ 1 ] , i , 0 ) % MOD ) % MOD;
                ady[ pos[ i - 1 ][ 0 ] ][ pos[ i - 1 ][ 1 ] ] = '.';
            }
            printf("%d %d\n" , ans1 , ans2 % MOD );
        }
    }

    return 0;
}
