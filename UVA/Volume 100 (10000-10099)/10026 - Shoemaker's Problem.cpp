/*****************************************
 ***Problema: Shoemaker's Problem
 ***ID: 10026
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
#define MAX 1005
struct Node{
    int day , cost, id;
    bool operator <( const Node n1 ) const{
        int f1 = day * n1.cost , f2 = n1.day * cost ;
        return f1 < f2;
    }
    Node(){}
}a[ MAX ];

int main(){
    int t , n;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d" , &n );
        for( int i = 0 ; i < n ; ++i ){
            scanf("%d %d" , &a[ i ].day , &a[ i ].cost );
            a[ i ].id  = i + 1;
        }
        stable_sort( a ,a + n);
        printf("%d" , a[ 0 ].id );
        for( int i = 1 ; i < n ; ++i )
            printf(" %d" , a[ i ].id );
        printf("\n");
        if( t > 0 ) printf("\n");
    }
    return 0;
}
