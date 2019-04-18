/*****************************************
 ***Problema: Necklace
 ***ID: 11001
 ***Juez: UVA
 ***Tipo: Math
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
#define EPS 1e-9
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

int main(){
int v , v0;
    while( scanf("%d %d" , &v , &v0 ) , v , v0 ){
        double d = -1;
        int ans = 0 , len = 0;

        for( int i = 1 ; i <= v ; ++i ){
            double _v = v/(double)i;
            if( _v <= v0 )
                break;
            double _d = sqrt(_v - (double)v0 ) * 0.3 * i ;
            if(_d <= 0 )
                continue;
            if( _d > d + EPS ){
                d = _d;
                ans = i;
                len = 1;
            }else if( fabs(_d - d ) < EPS ){
                len++;
            }
        }
        if( len == 1 )
            printf("%d\n" , ans );
        else
            puts("0");
    }
    return 0;
}
