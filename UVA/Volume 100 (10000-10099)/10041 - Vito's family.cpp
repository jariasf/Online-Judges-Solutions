/*****************************************
 ***Problema: Vito's family
 ***ID: 10041
 ***Juez: UVA
 ***Tipo: Sorting, Median
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
#define MAX 505
int a[ MAX ] , n;

int getSum( int val ){
    int sum = 0;
    for( int i = 0 ; i < n ; ++i ){
        sum += abs( val - a[i] );
    }
    return sum;
}

int main(){
    int t , mini , maxi;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d" , &n ) ){
        mini = 1<<30;
        maxi = 0;
        set<int> _s;
        for( int i = 0 ; i < n && scanf("%d" , &a[i]) ; ++i ){
            mini = min( mini , a[i] );
            maxi = max( maxi , a[i] );
        }
        sort( a , a + n );
        int ans = 1<<30;
        int median = n/2;
        ans = getSum( a[ median ] );
        if( median - 1 >= 0 )
            ans = min( ans , getSum( a[ median - 1 ] ) );
        if( median + 1 < n )
            ans = min( ans , getSum( a[ median + 1 ] ) );
        printf("%d\n" , ans );
    }

    return 0;
}

