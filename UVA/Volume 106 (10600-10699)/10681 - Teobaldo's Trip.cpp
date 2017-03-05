/*****************************************
 ***Problema: Teobaldo's Trip
 ***ID: 10681
 ***Juez: UVA
 ***Tipo: Matrix Exponentiation
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
#define MAX 101
typedef int type;
struct Matrix{
    type mat[ MAX ][ MAX ];
};

int n;
Matrix MatrixMult( Matrix A , Matrix B ){
    Matrix ans; int i , j , k;
    for( i = 0 ; i < n ; ++i )
        for( j = 0 ; j < n ; ++j )
            for( ans.mat[ i ][ j ] = k = 0 ; k < n ; ++k )
                ans.mat[ i ][ j ] |= A.mat[ i ][ k ] & B.mat[ k ][ j ];
    return ans;
}

void print( Matrix m ){
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < n ; ++j ){
            cout<<m.mat[ i ][ j ]<<" ";
        }
        cout<<endl;
    }
}

Matrix MatrixPow( Matrix A , int p ){
    int i , j;
    Matrix ans;
    for( i = 0 ; i < n ; ++i )
        for( j = 0 ; j < n ; ++j )
            ans.mat[ i ][ j ] = ( i == j );

    while( p ){
        if( p & 1 ) ans = MatrixMult( ans , A );
        A = MatrixMult( A , A );
        p >>= 1;
    }
    return ans;
}


int main(){
    int E , u , v , l;
    Matrix ady;
    while( scanf("%d %d" , &n , &E ) , n | E ){
        memset( ady.mat , 0 , sizeof( ady.mat ) );
        while( E-- > 0 && scanf("%d %d" , &u , &v ) ){
            ady.mat[ u - 1 ][ v - 1 ] = ady.mat[ v - 1 ][ u - 1 ] = 1;
        }
        scanf("%d %d %d" , &u , &v , &l );
        ady = MatrixPow( ady , l );
        if( ady.mat[ u - 1 ][ v - 1 ] > 0 ) puts("Yes, Teobaldo can travel.");
        else puts("No, Teobaldo can not travel.");
    }

    return 0;
}
