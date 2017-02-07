/*****************************************
 ***Problema: Boggle Blitz
 ***ID: 487
 ***Juez: UVA
 ***Tipo: Backtracking, DFS
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
#define MAX 21
char ady[ MAX ][ MAX ];
vector<string> v;
int n;
bool seen[ MAX ][ MAX ];

int dx[ 8 ] = { 1 , -1 , 0 ,  0 , 1 , 1 , -1 , -1 };
int dy[ 8 ] = { 0 ,  0 , 1 , -1 , 1 , -1 , 1 , -1};
string s;
void dfs( int x , int y , int len  ){
    seen[ x ][ y ] = 1;
    s += ady[ x ][ y ];
    if( len >= 3 ){
        v.push_back( s );
    }
    for( int i = 0 ; i < 8 ; ++i ){
        int nx = dx[ i ] + x, ny = dy[ i ] + y;
        if( nx >= 0 && ny >= 0 && nx < n && ny < n && !seen[ nx ][ ny ] && ady[ nx ][ ny ] > ady[ x ][ y ] ){
            dfs( nx , ny , len + 1  );
            seen[ nx ][ ny ] = 0;
            s = s.substr( 0 , s.length() - 1 );
        }
    }

}

bool cmp( string s1 , string s2 ){
    if( s1.length() == s2.length() )return s1 < s2;
    else{
        if( s1.length() > s2.length()) return 0;
        else return 1;
    }
}

int main(){
    int t;
    scanf("%d" , &t );
    for( int q = 0 ; q < t ; ++q ){
        if( q )printf("\n");
        scanf("%d" , &n );

        for( int i = 0 ; i < n ; ++i )scanf("%s" , &ady[ i ] );
        v.clear();
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < n ; ++j ){
                memset( seen , 0 , sizeof( seen ) );
                s = "";
                dfs( i , j , 1  );
            }
        }

        if( v.size() > 0 ){
            sort( v.begin() , v.end() , cmp );
            string aux = v[ 0 ];
            cout<<v[ 0 ]<<endl;
            for( int i = 0 ; i < v.size(); ++i ){
                if( v[ i ] != aux )cout<<v[ i ]<<endl;
                aux = v[ i ];
            }
        }
    }
    return 0;
}
