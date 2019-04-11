/*****************************************
 ***Problema: Counting substhreengs
 ***ID: 12856
 ***Juez: UVA
 ***Tipo: Math
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
#define MAX 1000005
char s[ MAX ];
long long sum[ MAX ] , cnt[ 3 ];
int main(){
    int t , f , i , end , start ;
    long long x , n , d = 3;
    unsigned long long ans;
    while( scanf("%s" , s ) != EOF ){
        int len = strlen( s );
        ans = 0;
        memset( cnt , 0 , sizeof(cnt ) );
        for( int i = 0 ; i < len ; ++i ){
            if( s[i] >= '0' && s[i] <= '9' ){
                if( i - 1 >= 0 && s[ i - 1 ] >= '0' && s[i - 1] <= '9'){
                    sum[i] = sum[ i - 1 ] % d + (s[i] - '0') % d;
                }else{
                    sum[i] = (s[i] - '0')%d;
                }
                sum[i] %=d;
                cnt[ sum[ i ] ]++;
            }else{
                for( int i = 0 ; i < d ; ++i )
                    ans += ( ( cnt[ i ] * ( cnt[ i ] - 1 ) )/2 );
                ans += cnt[ 0 ];
                memset( cnt , 0 , sizeof( cnt ) );
            }
        }
        for( int i = 0 ; i < d ; ++i )
            ans += ( ( cnt[ i ] * ( cnt[ i ] - 1 ) )/2 );
        ans += cnt[ 0 ];
        printf("%llu\n" , ans );
    }

    return 0;
}
