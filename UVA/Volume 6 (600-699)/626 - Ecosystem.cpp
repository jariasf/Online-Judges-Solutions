/*****************************************
 ***Problema: Ecosystem
 ***ID: 626
 ***Juez: UVA
 ***Tipo: Brute Force
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
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define pii pair<int , int >
#define psi pair<string , int>
#define all( x ) x.begin(),x.end()
int MIN( int a , int b ){ return ( a < b ) ? a : b; }
int MAX( int a , int b ){ return ( a < b ) ? b : a; }
string toStr(int n){string s;ostringstream buffer;buffer<<n;s=buffer.str();return s;}
int toInt(string str){int n;istringstream buffer(str);buffer>>n;return n;}
long long pot(long long a,long long b){if(!b)return 1;if(b&1)return a*pot(a*a,b>>1); else return pot(a*a,b>>1);}
int n;
#define ppi pair< int , pair< int , int > >
#define MAX 105
struct Data{
    int x , y , z;
    Data( int xx , int yy ,int zz ) : x(xx) , y( yy) , z(zz) {}
    Data(){}
};

bool cmp( Data d1 , Data d2 ){
    return ( d1.x < d2.x || d1.x == d2.x && d1.y < d2.y || d1.x == d2.x && d1.y == d2.y && d1.z < d2.z );
}

int ady[ MAX ][ MAX ];
int main(){
    while( scanf("%d" , &n ) != EOF ){
        for( int i = 0 ; i < n ; ++i )
            for( int j = 0 ; j < n && scanf("%d" , &ady[i][j] ) ; ++j );
        vector< Data > v;
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < n ; ++j ){
                if( ady[i][j] && i != j ){
                    for( int k = 0 ; k < n ; ++k ){
                        if( ady[ j ][ k ] && i != k ){
                            if( ady[ k ][ i ] && i != k && j != k && i != j ){
                                if( (i < j && j < k) || ( i > j && j > k ) ){
                                    v.pb( Data( i + 1 , j + 1 , k + 1 ) );
                                }
                            }
                        }
                    }
                }
            }
        }

        sort( v.begin() , v.end() , cmp );

        for( int i = 0 ; i < v.size() ; ++i ){
            printf("%d %d %d\n" , v[i].x , v[i].y , v[i].z );
        }
        printf("total:%d\n\n" , v.size());
    }

    return 0;
}
