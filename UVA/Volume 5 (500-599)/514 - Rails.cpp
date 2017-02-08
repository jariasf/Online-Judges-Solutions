/*****************************************
 ***Problema: Rails
 ***ID: 514
 ***Juez: UVA
 ***Tipo: Ad hoc, Stack
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
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
#include<fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
int main( ){

    int N, len;
    bool first = false;
    while( scanf("%d" , &N ) , N ){
        int a[ N + 5 ], ini[ N + 5 ];
        while( scanf("%d" , &a[ 0 ]) , a[ 0 ] ){
            for( int i = 1 ; i < N ; ++i ){
                scanf("%d" , &a[ i ] );
            }
            int i = 1 , idx = 0;
            stack<int> S;
            while( idx < N){
                while( !S.empty() &&  a[ idx ] == S.top() ){
                    S.pop();
                    idx++;
                }
                if( idx == N || i > N ){ break; }
                for(; i <= N ; ++i ){
                    if( i == a[ idx ] ){
                        idx++;
                        i++;
                        break;
                    }
                    else{
                        S.push( i );
                    }
                }
            }
            if( idx == N )puts("Yes");
            else puts("No");
        }
        first = true;
        printf("\n");
    }

    return 0;
}
