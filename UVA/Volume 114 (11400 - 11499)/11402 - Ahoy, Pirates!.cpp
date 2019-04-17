/*****************************************
 ***Problema: Ahoy, Pirates! 
 ***ID: 11402
 ***Juez: UVA
 ***Tipo: Segment Tree
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
#define MAX 1024005
int n;
string s, str;
struct Node{
    long long c , val , sum;
    Node( long long cc , long long v , long long s ): c( cc ) , val( v ) , sum( s ){}
    Node(){}
}tree[ 4 * MAX ];

void update( int from , int to , long long by , int op = 0, int left = 0 , int right = n - 1 , int node = 0  ){
    if( left >= from && right <= to ){
        if( op ){
            if( tree[ node ].val == 0 ){
                tree[ node ].val = 1;
            }else if( tree[ node ].val == 1 ){
                tree[ node ].val = 0;
            }
            tree[ node ].sum = ( right - left + 1 ) - tree[ node ].sum;
            tree[ node ].c = 2;
        }else{
            tree[ node ].c = 1;
            tree[ node ].val = by;
            tree[ node ].sum = ( by * ( right - left  + 1 ) );
        }
        return;
    }

    int mid = ( left + right )>>1, L = 2 * node + 1 , R = 2 * node + 2 ;

    if( tree[ node ].c == 1 ){
        tree[ L ].val = tree[ R ].val = tree[ node ].val;
        tree[ L ].sum = ( tree[ node ].val ) * ( mid - left + 1 );
        tree[ R ].sum = ( tree[ node ].val ) * ( right - mid  );
        tree[ L ].c = tree[ R ].c = 1;
        tree[ node ].c = 0;
        tree[ node ].val = -1;
    }else if( tree[ node ].c == 2 ){
        tree[ L ].val = tree[ node ].val;
        tree[ R ].val = tree[ node ].val;
        if( tree[ node ].val  != -1 ){
            tree[ L ].sum = ( tree[ node ].val ) * ( mid - left + 1 );
            tree[ R ].sum = ( tree[ node ].val ) * ( right - mid  );
        }else{
            tree[ L ].sum = ( mid - left + 1 ) - tree[ L ].sum;
            tree[ R ].sum = ( right - mid  ) - tree[ R ].sum;
        }
        tree[ L ].c = tree[ R ].c = 2;
        tree[ node ].c = 0;
        tree[ node ].val = -1;
    }

    if( from <= mid ) update( from , to , by , op , left , mid ,  L );
    if( to > mid ) update( from , to , by , op , mid + 1 ,  right , R );
    tree[ node ].sum = tree[ R ].sum + tree[ L ].sum;
}

long long query( int from , int to , int left = 0 , int right = n - 1 , int node = 0 ){
    if( left >= from && right <= to ){
        return tree[ node ].sum;
    }

    int mid = ( left + right )>>1, L = 2 * node + 1 , R = 2 * node + 2;
    long long ans = 0 ;

    if( tree[ node ].c == 1 ){
        tree[ L ].c = 1;
        tree[ R ].c = 1;
        tree[ L ].val = tree[ node ].val;
        tree[ R ].val = tree[ node ].val;
        tree[ L ].sum = ( tree[ node ].val ) * ( mid - left + 1 );
        tree[ R ].sum = ( tree[ node ].val ) * ( right - mid );

        tree[ node ].c = 0;
        tree[ node ].val = -1;
    }else if( tree[ node ].c == 2 ){
        tree[ L ].val = tree[ node ].val;
        tree[ R ].val = tree[ node ].val;
        if( tree[ node ].val != -1 ){
        tree[ L ].sum = ( tree[ node ].val ) * ( mid - left + 1 );
        tree[ R ].sum = ( tree[ node ].val ) * ( right - mid );
        }else{
        tree[ L ].sum = ( mid - left + 1 ) - tree[ L ].sum;
        tree[ R ].sum = ( right - mid  ) - tree[ R ].sum;
        }
        tree[ L ].c = tree[ R ].c = 2;
        tree[ node ].c = 0;
        tree[ node ].val = -1;
    }

    if( from <= mid ) ans += query( from , to  , left , mid ,  L );
    if( to > mid ) ans += query( from , to  , mid + 1 ,  right , R );
    tree[ node ].sum = tree[ L ].sum + tree[ R ].sum;
    return ans;
}


void build( int left = 0 , int right = n - 1 , int node = 0  ){
    if( left == right ){
        tree[ node ] = Node( -1 , 0 , s[left] - '0' );
        return;
    }

    int mid = ( left + right )>>1, L = 2 * node + 1 , R = 2 * node + 2 ;
    update( left , mid ,  L );
    update( mid + 1 ,  right , R );
    tree[ node ].sum = tree[ L ].sum + tree[ R ].sum;
    tree[ node ].c = -1;
}

int main(){
    char c;
    int t , w , k , Q , u , v , cnt;
    scanf("%d" , &t );

    for( int q = 1 ; q <= t && scanf("%d" , &k ) ; ++q ){
        s = "";
        while( k-- > 0 && scanf("%d" , &w ) ){
            cin>>str;
            for( int i = 0 ; i < w ; ++i )
                s += str;
        }

        n = s.size();
        build( 0 , n - 1 );

        scanf("%d" , &Q );
        cnt = 1;
        printf("Case %d:\n" , q );
        while( Q-- > 0 && scanf(" %c %d %d" , &c , &u , &v ) ){
            if( c == 'F' ){
                update( u , v , 1 );
            }else if( c == 'E' ){
                update( u , v , 0 );
            }else if( c == 'I' ){
                update( u , v , 0 , 1 );

            }else{
                long long sum = query( u , v );
                printf("Q%d: %lld\n" , cnt++ , sum );
            }
        }
    }

    return 0;
}
