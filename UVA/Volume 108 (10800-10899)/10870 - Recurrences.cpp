/*****************************************
 ***Problema: Recurrences
 ***ID: 10870
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
#define MAX 20
int n , MOD;
typedef long long type;
struct Matrix{
    int r , c;
    type mat[ MAX ][ MAX ];
};

Matrix MatrixMult( Matrix A , Matrix B ){
    Matrix ans; int i , j , k;
    for( i = 0 ; i < n ; ++i )
        for( j = 0 ; j < n ; ++j )
            for( ans.mat[ i ][ j ] = k = 0 ; k < n ; ++k )
                ans.mat[ i ][ j ] += A.mat[ i ][ k ] * B.mat[ k ][ j ] , ans.mat[ i ][ j ] %= MOD;
    return ans;
}

Matrix MatrixPow( Matrix A , long long p ){
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

Matrix MatrixMultDif( Matrix A , Matrix B ){
    Matrix ans; int i , j , k;
    ans.r = A.r;
    ans.c = B.c;
    for( i = 0 ; i < A.r ; ++i )
        for( j = 0 ; j < B.c ; ++j )
            for( ans.mat[ i ][ j ] = k = 0 ; k < A.c ; ++k )
                ans.mat[ i ][ j ] += A.mat[ i ][ k ] * B.mat[ k ][ j ] , ans.mat[ i ][ j ] %= MOD;
    return ans;
}

void print( Matrix m ){
    for( int i = 0 ; i < m.r ; ++i ){
        for( int j = 0 ; j < m.c ; ++j ){
            cout<<m.mat[ i ][ j ]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int idx , i;
    Matrix ans , fib;
    while( scanf("%d %d %d" , &n , &idx , &MOD ) , n | idx | MOD ){
        memset( ans.mat , 0 , sizeof( ans.mat ) );
        for( i = 0 ; i < n && scanf("%lld" , &ans.mat[ 0 ][ i ] ) ; ++i );
        for( i = 0 ; i < n && scanf("%lld" , &fib.mat[ n - i - 1 ][ 0 ] ) ; ++i );
        for( i = 0 ; i < n ; ++i ) ans.mat[ i + 1 ][ i ] = 1;
        fib.r = n; fib.c = 1;
        ans = MatrixPow( ans , idx - 1 );
        ans.r = ans.c = n;
        ans = MatrixMultDif( ans , fib );
        ans.r = n; ans.c = 1;
        printf("%lld\n" , ans.mat[ n - 1 ][ 0 ] );
    }
    return 0;
}
