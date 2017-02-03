/*****************************************
 ***Problema: Stacks of Flapjacks
 ***ID: 120
 ***Juez: UVA
 ***Tipo: Stacks, Greedy
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
#include <climits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 205
#define MAXN 105
char line[ MAX ];
int a[ MAXN ], b[ MAXN ] , l;

bool cmp( int a , int b ){ return a > b;}
int getIdx( int x ){ return l - x; }

void print(){
    for( int i = 0 ; i < l ; ++i ) printf("%d " , a[ i ] ) ;
    printf("\n");
}

void flip( int idx ){
    int left = 0 , right = idx + 1;
    while( left < right ){
        int tmp = a[ left ];
        a[ left ] = a[ right - 1 ];
        a[ right - 1 ] = tmp;
        left++; right--;
    }
    //print();
}

void solve(){
    int i , len = l , j;
    sort( b , b + l , cmp );
    for( i = 0 ; i < l ; ++i ){
        for( j = 0 ; j < len ; ++j ){
            if( b[ i ] == a[ j ] ) break;
        }

        if( j != len - 1 ){
            if( j == 0 ){
                flip( len - 1 );
                printf("%d " , l - len + 1 );
            }
            else {
                flip( j );
                printf("%d " , l - j );
                flip( len - 1 );
                printf("%d " , l - len + 1 );
            }
        }
        len--;
    }
    printf("0\n");
}

int main(){
    int x;
    while( gets( line ) ){
        l = 0;
        stringstream ss( line );
        while( ss>>x ){ a[ l ] = b[ l++ ] = x; }
        for( int i = 0 ; i < l ; ++i ){
            if( i ) printf(" ");
            printf("%d" , a[ i ] );
        }
        printf("\n");
        solve();
    }
    return 0;
}
