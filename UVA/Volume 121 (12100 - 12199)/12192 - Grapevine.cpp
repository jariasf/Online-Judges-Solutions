/*****************************************
 ***Problema: Grapevine
 ***ID: 12192
 ***Juez: UVA
 ***Tipo: Binary Search
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
#define COL 1
#define ROW 0
#define MAX 505
int a[ MAX ][ MAX ];
int h , w;
int rows[ MAX ];
int searchRow(int row, int L){
    int left = 0, right = w;
    int mid;
    while( left < right ){
        mid = ( left + right )>>1;
        if( a[row][ mid ] < L ){
            left = mid + 1;
        }else{
            right = mid;
        }
    }

    return left;
}

int searchDiag(int row, int col, int U, int flag){
    int left, right;

    if( flag == ROW ){
        left = row; right = h;
    }else{
        left = col; right = w;
    }

    int mid;
    while( left < right ){
        mid = ( left + right )>>1;

        int value;
        if( flag == ROW ){
            value = a[mid][col + mid - row];
        }else
            value = a[row + mid - col][mid];

        if( value <= U ){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    return left - 1;
}

int main(){
    int Q, L , U;
    while( scanf("%d %d" , &h , &w) , h | w){
        for( int i = 0 ; i < h ; ++i )
            for( int j = 0 ; j < w && scanf("%d" , &a[i][j]) ; ++j );
        scanf("%d" , &Q);
        while(Q-- > 0 && scanf("%d %d", &L, &U ) ){
            int ans = 0;
            for( int i = 0 ; i < h ; ++i ){
                int col = searchRow(i, L);
                if( a[i][col] > U ) continue;
                //search in diagonal (consider case where row or col are not square)
                int colLeft = w - col;
                int rowLeft = h - i;
                if( colLeft < rowLeft ){
                    int colIndex = searchDiag(i, col, U, COL );
                    if( colIndex == -1 ) continue;
                    ans = max( ans, colIndex - col + 1 );
                }else{
                    int rowIndex = searchDiag(i, col, U, ROW );
                    if( rowIndex == -1 ) continue;
                    ans = max( ans , rowIndex - i + 1 );
                }
            }
            printf("%d\n" , ans );
        }
        printf("-\n");
    }

    return 0;
}
