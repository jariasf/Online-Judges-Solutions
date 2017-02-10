/*****************************************
 ***Problema: Copying Books
 ***ID: 714
 ***Juez: UVA
 ***Tipo: Binary Search + Greedy
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
#define MAX 505
int N , k , slash[ MAX ];
long long a[ MAX ];
long long maximo( long long a , long long b ){ return ( a > b )? a : b ; }

long long Partition( long long mid ){

    int j;
    long long max = 0 , sum = 0;
    for( int i = N - 1, j = 0 ; i >= 0 ; --i ){
        if( j + 1 < k  && (  i + 1 < k - j || sum + a[ i ] > mid) ){
            max = maximo( max, sum );
            sum = a[ i ];
            slash[ i ] = 1;
            j++;
        }
        else sum += a[ i ];
    }
    return maximo( max , sum );

}

int main(){

    int t ;
    long long left , right , mid;
    scanf("%d" , &t );

    while( t-- ){
        scanf("%d %d" , &N , &k );
        left = right = 0;
        for( int i = 0 ; i < N ; ++i ) {
            scanf("%lld" , &a[ i ] );
            right += a[ i ];
            slash[ i ] = 0;
        }

        while( left < right ){
            mid = ( left + right )>>1;
            if( Partition( mid ) > mid ) left = mid + 1;
            else right = mid;
        }

        memset( slash , 0 , sizeof( slash ) );

        Partition( left );
        printf("%lld" , a[ 0 ] );
        if( slash[ 0 ] )printf(" /");

        for( int i = 1 ; i < N ; ++i ){
            printf(" %lld" , a[ i ] );
            if( slash[ i ] )printf(" /");
        }
        printf("\n");
    }
    return 0;
}
