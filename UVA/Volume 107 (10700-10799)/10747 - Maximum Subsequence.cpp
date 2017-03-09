/*****************************************
 ***Problema: Maximum Subsequence
 ***ID: 10747
 ***Juez: UVA
 ***Tipo: Greedy
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
#define MAX 10005
int a[ MAX ];
int n ,negative , positive;

int main(){
    int k , ini, ans;
    long long sum , prod;
    int zeros;
    while( scanf("%d %d" , &n , &k ) , n | k ){
        positive = negative = 0;
        zeros = 0;

        for( int i = 0 ; i < n ; ++i ) {
            scanf("%d" , &a[ i ] );
            if( a[ i ] < 0 ){
                negative++;
            }else if( a[ i ] > 0 ) {
                positive++;
            }
        }
        zeros = n - positive - negative;
        sort( a , a + n );
        vector<int> neg , pos;

        for( int i = negative - 1 ; i >=0 ; --i ){
            neg.push_back( a[ i  ] );
        }
        sum = 0;
        for( int i = n - positive ; i < n ; ++i ){
            pos.push_back( a[ i ] );
            sum += a[ i ];
        }
        int N = ( negative & 1 )? negative - 1: negative;
        if( k > positive + negative || ( zeros > 0 && k > positive + N ) 
			|| ( zeros > 0 && !positive && k & 1   ) ){
            k -= positive;
            k -= zeros;
            for( int i = negative - 1 ; k > 0 && i >= 0 ; --i ){
                sum += a[ i ];
                k--;
            }
            printf("%d\n" , sum );
        }
        else{
            sum = 0;
            int prodPos, prodNeg ,a , b , c ,d;
            int ini = 0;
            bool iniPos = true;
            if( k & 1 ){
                if( positive > 0 ){
                    sum += pos[ positive - 1 ];
                    positive--;
                }
                else if( negative > 0 ){
                    sum += neg[ 0 ];
                    ini = 1;
                    iniPos = false;
                }
                k--;
            }
            bool enterPos , enterNeg;
            while( k > 0 && k % 2 == 0 ){
                enterPos = enterNeg = false;
                if( positive > 1 ){
                    enterPos = true;
                    prodPos = pos[ positive - 1 ] * pos[ positive - 2 ];
                }
                if( negative > 1 + ini  ){
                    enterNeg = true;
                    prodNeg = neg[ negative - 1 ] * neg[ negative - 2 ];
                }
                if( enterPos ){
                    if( enterNeg ){
                        if( prodPos >= prodNeg ){
                            sum += pos[ positive - 1 ] + pos[ positive - 2 ];
                            positive -= 2;
                            k -= 2;
                        }
                        else{
                            sum += neg[ negative - 1 ] + neg[ negative - 2 ];
                            negative -= 2;
                            k -= 2;
                        }
                    }
                    else{
                        sum += pos[ positive - 1 ] + pos[ positive - 2 ];
                        positive -= 2;
                        k-=2;
                    }
                }
                else if( enterNeg ){

                    if( !iniPos ){
                        sum += neg[ ini  ] + neg[ ini + 1 ];
                        ini += 2;
                        k -= 2;
                    }
                    else{
                        sum += neg[ negative - 1 ] + neg[ negative - 2 ];
                        negative -= 2;
                        k -= 2;
                    }
                }
                else break;
            }

            if( k > 0 ){
                for( int i = positive - 1 ; k > 0 && i >= 0 ; --i ){
                    sum += pos[ i ];
                    k--;
                }
                if( k > 0 ){
                    for( int i = 0 ; k > 0 && i < negative ; ++i ){
                        sum += neg[ i ];
                        k--;
                    }
                }
            }

            printf("%d\n" , sum );
        }
    }
    return 0;
}

