/*****************************************
 ***Problema: Bits and Pieces
 ***ID: 12444
 ***Juez: UVA
 ***Tipo: Bitwise
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
int A , B;
void solve( int a , int b , int c , int d , int last ){
    bool bb = true;
    for( int i = 31 ; i >= 0 ; --i ){
        if( !( c & 1<<i ) && ( d & 1<<i ) ){
            if( bb ) a|= 1<<i;
            else b |= 1<<i;
            bb = false;
        }
    }
    A = a; B = b;
}
int main(){
    int t , c , d , i;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d %d" , &c , &d ) ){
        bool b = true;
        for( i = 31 ; i >= 0 ; --i ){
            if( ( c & 1<<i ) && !( d & 1<<i ) ){
                b = false;
                break;
            }
        }
        if( !b ) puts("-1");
        else{
            solve( c , c , c , d , 31 );
            if( A > B ) swap( A , B );
            printf("%d %d\n" , A , B );
        }
    }
    return 0;
}
