/*****************************************
 ***Problema: Killer Problem
 ***ID: 11898
 ***Juez: UVA
 ***Tipo: Sorting
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
#define MAX 200005
struct Data{
    int val , id;
    Data( int v , int i ): val( v ) , id( i ){}
    Data(){}
    bool operator < ( const Data d1 ) const{
        return val < d1.val || ( val == d1.val && id < d1.id );
    }
}a[MAX];

int main(){
    int t, q , x , y , n;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d" , &n );
        for( int i = 0 ; i < n ; ++i ){
            scanf("%d" , &a[ i ].val );
            a[ i ].id = i;
        }
        scanf("%d" , &q );
        sort( a , a + n );
        while( q-- ){
            scanf("%d %d" , &x , &y );
            x--;
            y--;
            int last = -1, mini = 1<<30;
            for( int i = 0 ; i < n ; ++i ){
                if( x <= a[ i ].id && a[ i ].id <= y ){
                    if( last == -1 ) last = a[ i ].val;
                    else{
                        last = a[ i ].val - last;
                        mini = min( mini , last );
                    }
                    if( mini == 0 ) goto end;
                    last = a[ i ].val;
                }
            }
            end:
            printf("%d\n" , mini );
        }
    }

    return 0;
}
