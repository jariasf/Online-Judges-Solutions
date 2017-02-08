/*****************************************
 ***Problema: Jugs
 ***ID: 571
 ***Juez: UVA
 ***Tipo: BFS
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
#define MAX 1005
int n , A , B;
bool seen[ MAX ][ MAX ];
string s[ 7 ] = { "" , "fill A" , "fill B" , "empty A" , "empty B" , "pour A B" , "pour B A" };
struct Estado{
    int a , b;
    string exp;
    Estado( int aa , int bb ,string s ): a( aa ) , b( bb ) , exp( s ){}
};
void bfs(){
    queue< Estado > Q;
    Q.push( Estado( 0 , 0 , "" ) );
    memset( seen , 0 , sizeof( seen ) );
    int a , b;
    string exp;
    while( !Q.empty() ){
        Estado act = Q.front(); Q.pop();
        if( seen[ act.a ][ act.b ] ) continue;
        a = act.a; b = act.b; exp = act.exp;
        if( b == n ){
            for( int i = 0 ; i < exp.length() ; ++i ){
                printf("%s\n" , s[ exp[ i ] - '0' ].c_str() );
            }
            printf("success\n");
            return;
        }
        seen[ a ][ b ] = 1;
        if( !seen[ A ][ b ] && a == 0 )Q.push( Estado( A , b , exp + "1" ) );
        if( !seen[ a ][ B ] && b == 0 )Q.push( Estado( a , B , exp + "2" ) );
        if( !seen[ 0 ][ b ] ) Q.push( Estado( 0 , b , exp + "3" ) );
        if( !seen[ a ][ 0 ] ) Q.push( Estado( a , 0 , exp + "4" ) );
        if( a > 0 ){
            int aux = min( B - b , a );
            if( !seen[ a - aux ][ b + aux ] ) Q.push( Estado( a - aux , b + aux , exp + "5" ) );
        }
        if( b > 0 ){
            int aux = min( A - a , b );
            if( !seen[ a + aux ][ b - aux ] ) Q.push( Estado( a + aux , b - aux , exp + "6" ) );
        }
    }
    return;
}

int main(){
    while( scanf("%d %d %d" , &A ,&B , &n ) != EOF ) bfs();
    return 0;
}
