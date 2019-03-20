/*****************************************
 ***Problema: Generalized Matrioshkas
 ***ID: 11111
 ***Juez: UVA
 ***Tipo: Recursion
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
#define MAX 10005
int a[ MAX ],len;

struct Data{
    int sum , val;
    Data( int vv , int ss ): val( vv ) , sum( ss ){}
};

bool solve(){
    stack<Data> S;
    for( int i = 0 ; i < len ; ++i ){
        if( a[ i ] < 0 ) S.push( Data( -a[ i ] , 0 ) );
        else{
            if( !S.empty() ){
                Data top = S.top(); S.pop();
                if( top.val != a[ i ] ){ //si tengo -2 -1 2
                    return false;
                }
                if( !S.empty() ){
                    top = S.top(); S.pop(); //-7 -2 2, extraigo 7 para verificar suma
                    if( top.sum + a[ i ] >=  top.val )return false;
                    S.push( Data( top.val , top.sum + a[ i ] ) );
                }
            }
            else return false;
        }
    }
    if( !S.empty() ) return false;
    return true;
}

int main(){
    string s;
    int x;
    while( getline( cin , s ) ){
        len = 0;
        stringstream ss( s + " ");
        while( ss>>x ) a[ len++ ] = x;
        if( solve() ) puts(":-) Matrioshka!");
        else puts(":-( Try again.");
    }
    return 0;
}
