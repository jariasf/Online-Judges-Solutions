/*****************************************
 ***Problema: Network Connections
 ***ID: 793
 ***Juez: UVA
 ***Tipo: Union Find
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

#define MAX_SIZE 100005
int parent[ MAX_SIZE ] , rank[ MAX_SIZE ];
void Make_Set( const int x ){
    for( int i = 0 ; i < x ; ++i ){
        parent[ i ] = i;
        rank[ i ] = 0;
    }
}

int Find( const int x ){
    if( parent[ x ] != x ) parent[ x ] = Find( parent[ x ] );
    return parent[ x ];
}

bool sameSet( int x , int y ){
    return ( Find( x ) == Find( y ) );
}

void Union( const int x, const int y ){
    int PX = Find( x ) , PY = Find( y );
    if( rank[ PX ] > rank[ PY ] ) parent[ PY ] = PX;
    else{
        parent[ PX ] = PY;
        if( rank[ PX ] == rank[ PY ] ) rank[ PY ]++;
    }
}

char c[1000];

int main(){
    string s;
    int V , u , v , t;
    scanf("%d" , &t );
    for( int q = 0 ; q < t && scanf("%d" , &V) ; ++q ){
        if( q )
            printf("\n");
        Make_Set( V );
        int pos , neg;
        pos = neg = 0;
        getline( cin , s );
        while( getline( cin , s ) && s.length() > 0 ){

            stringstream ss( s );
            ss>>c>>u>>v;
            if( c[0] == 'c' ){
                Union( u - 1 , v - 1 );
            }else if( c[0] == 'q'){
                if( sameSet( u - 1 , v - 1) ){
                    pos++;
                }else
                    neg++;
            }
        }
        printf("%d,%d\n" , pos , neg );
    }

    return 0;
}
