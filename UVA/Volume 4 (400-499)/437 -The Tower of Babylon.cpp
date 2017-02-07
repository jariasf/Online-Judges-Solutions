/*****************************************
 ***Problema: The Tower of Babylon
 ***ID: 437
 ***Juez: UVA
 ***Tipo: LIS, DP
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
#define MAX 200
int n;
vector< vector<int> > v;
bool inside( vector<int> a , vector<int> b ){
    return a[ 0 ] < b[ 0 ] && a[ 1 ] < b[ 1 ];
}

int val[ MAX ];
int main(){
    int x , y ,z , ans , q = 1;
    while( scanf("%d" , &n ) , n ){
        v.clear();
        for( int i = 0 ; i < n ; ++i ){
            vector<int> vv( 3 );
            scanf("%d %d %d" , &vv[ 0 ] , &vv[ 1 ] , &vv[ 2 ] );
            sort( vv.begin() , vv.end() );
            do{
                v.push_back( vv );
            }while( next_permutation( vv.begin() , vv.end() ) );
        }
        sort( v.begin() , v.end() );
        n = v.size();
        ans = 0;
        for( int i = 0 ; i < n ; ++i ) val[ i ] = v[ i ][ 2 ];
        for( int i = 0 ; i < n ; ++i ){
            for( int j = i + 1 ; j < n ; ++j ){
                if( inside( v[ i ] , v[ j ] ) && val[ j ] < val[ i ] + v[ j ][ 2 ] ){
                   val[ j ] =  val[ i ] + v[ j ][ 2 ];
                }
            }
        }
        for( int i = 0 ; i < n ; ++i )
           ans = max( ans , val[ i ] );
        printf("Case %d: maximum height = %d\n" , q++ , ans );
    }
    return 0;
}
