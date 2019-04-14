/*****************************************
 ***Problema: Yell Classico
 ***ID: 12580
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
#define MAX 2005
int a[ MAX ];

struct Node{
    int val , idx ;
    Node( int v , int i ):val(v) , idx(i){}
};

struct cmp{
    bool operator() ( const Node &a, const Node &b){
       return (a.val < b.val || (a.val == b.val && a.idx > b.idx));
   }
};

int main(){

    int t , q , n;
    scanf("%d" , &t );
    for( q = 1 ; q <= t && scanf("%d" , &n ) ; ++q ){
        for( int i = 0 ; i < n && scanf("%d" , &a[i] ) ; ++i );
        printf("Case %d:" , q );
        if( n < 11 ){
            puts(" go home!");
        }else{
            int left = 0;
            for( int i = 0 ; i < 11 ; ++i ){
                int maxi = 0;
                for( int j = left ; j < n - 10 + i ; ++j ){
                    if( maxi < a[ j ] ){
                        maxi = a[ j ];
                        left = j + 1;
                    }
                }

                printf(" %d" , maxi );
            }
            printf("\n");
        }
    }

    return 0;
}
