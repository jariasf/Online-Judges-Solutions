/*****************************************
 ***Problema: Power of Matrix
 ***ID: 11149
 ***Juez: UVA
 ***Tipo: Matrix Exponentiation , Math
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<string>
#include<cstring>
#include<set>
#include<vector>
#include<sstream>
#include<cmath>
#include<queue>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define MAX 45
#define MOD 10
typedef int type;
int n;
struct Matrix{
    type mat[ MAX ][ MAX ];
};
Matrix I , inicial;
Matrix MatrixMult( Matrix A , Matrix B ){
    Matrix ans;
    int i , j , k;
    for( i = 0 ; i < n ; ++i )
        for( j = 0 ; j < n ; ++j )
            for( ans.mat[ i ][ j ] = k = 0 ; k < n ; ++k )
                ans.mat[ i ][ j ] += A.mat[ i ][ k ] * B.mat[ k ][ j ] , ans.mat[ i ][ j ] %= MOD;
    return ans;
}

Matrix MatrixSum( Matrix A , Matrix B ){

    int i , j;
    for( i = 0 ; i < n ; ++i )
        for( j = 0 ; j < n ; ++j ){
            A.mat[ i ][ j ] = ( A.mat[ i ][ j ] % MOD + B.mat[ i ][ j ] % MOD ) % MOD;
        }
    return A;
}

Matrix MatrixPow( Matrix A , int p ){
    int i , j;
    Matrix ans = I;
    while( p ){
        if( p & 1 ) ans = MatrixMult( ans , A );
        A = MatrixMult( A , A );
        p >>= 1;
    }
    return ans;
}

Matrix ceros;
Matrix solve( Matrix A , int p){
    if( p == 0 ) return ceros;
    if( p & 1 )
        return MatrixSum( MatrixMult( solve( A , p/2 ) , MatrixSum( I , MatrixPow( A , p/2 )  ) ) , MatrixPow( A , p ) );
    return MatrixMult( solve( A , p/2 ) , MatrixSum( I , MatrixPow( A , p/2 )  ) );
}

int main(){
    int k , i , j;
    while( scanf("%d %d" , &n ,&k ) , n ){
        Matrix ans;
        for( i = 0 ; i < n ; ++i )
            for( j = 0 ; j < n && scanf("%d" , &inicial.mat[ i ][ j ] ); ++j ){
                inicial.mat[ i ][ j ] %= MOD;
                I.mat[ i ][ j ] = ( i == j );
            }
        ans = solve( inicial , k  );

        for( i = 0 ; i < n ; ++i ){
            for( j = 0 ; j < n ; ++j ){
                if( j ) printf(" ");
                printf("%d" , ans.mat[ i ][ j ] );
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
