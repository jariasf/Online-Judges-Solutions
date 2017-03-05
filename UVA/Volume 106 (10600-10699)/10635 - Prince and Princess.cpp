/*****************************************
 ***Problema: Prince and Princess
 ***ID: 10635
 ***Juez: UVA
 ***Tipo: Hallar LCS x medio de LIS
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
#define MAX 62505
int a[ MAX ], lis[ MAX ];
int n , p , q , k, j , i, len, t;

int LIS(){

    lis[ len = 1 ] = a[ 0 ];
    for( p = 1 ; p < k ; ++p ){

        if( lis[ len ] < a[ p ] ){
            lis[ ++len ] = a[ p ];
            continue;
        }
        for( i = 1 , j = len ; i < j ; )
            if( lis[ t = ( i + j ) >> 1 ] < a[ p ] ) i = t + 1; else j = t;

        lis[ i ] = a[ p ];
    }

    for( i = 0 ; i < k ; ++i ){
        cout<<a[ i ]<<" b "<<lis[ i ]<<endl;
    }

    return len;

}

int main(){
    int t, seen[ MAX ] , index[ MAX ] , x , qq;
    scanf("%d" , &t );
    memset( seen , 0 , sizeof( seen ) );
    for( qq = 1 ; qq <= t ; ++qq ){

        scanf("%d %d %d", &n , &p , &q );

        for( i = 0 ; i <= p ; ++i ){
            scanf("%d" , &x );
            seen[ x ] = qq;
            index[ x ] = i;
        }

        for( j = 0, k = 0 ; j <= q ; ++j ){
            scanf("%d" , &x );
            if( seen[ x ] == qq ){
                a[ k++ ] = index[ x ];
            }
        }
        printf("Case %d: ", qq );
        if( k == 0 )printf("0\n");
        else printf("%d\n", LIS() );
    }

    return 0;
}
