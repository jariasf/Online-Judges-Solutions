/*****************************************
 ***Problema: Binomial Theorem
 ***ID: 11955
 ***Juez: UVA
 ***Tipo: Binomial theorem
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
long long binomial[1000][1000];
void PascalTriangle(long N, long K){
    for (int k = 1; k <= K; k++) binomial[0][k] = 0;
    for (int n = 0; n <= N; n++) binomial[n][0] = 1;

    for (int n = 1; n <= N; n++){
       for (int k = 1; k <= K; k++){
          binomial[n][k] = binomial[n-1][k-1] + binomial[n-1][k];
          if( binomial[ n - 1 ][ k - 1 ] == 0 )continue;
       }
    }
}


int main(){
    PascalTriangle( 51 , 51 );
    int t, p;
    string s , cad, s1 ,s2;
    cin>>t;
    for( int q = 1 ; q <= t ; ++q ){

        cin>>s;
        cad ="";
        for( int i = 0 ; i < s.length(); ++i ){
            if( isalpha( s[ i ] ) || isdigit( s[ i ] ) )cad += s[ i ];
            else cad +=" ";
        }
        cad+= " ";
        stringstream ss( cad );
        ss>>s1>>s2>>p;
        cout<<"Case "<<q<<": "<<s1;
        if( p > 1 ) cout<<"^"<<p;
        for( int i = 1 , pot = p - 1 , pot2 = 1 ; i < p && pot >= 1 ; ++i , --pot , pot2++ ){
            cout<<"+"<<binomial[ p ][ i ]<<"*"<<s1;
            if( pot > 1 ) cout<<"^"<<pot;
            cout<<"*"<<s2;
            if( pot2 > 1 )cout<<"^"<<pot2;
        }
        cout<<"+"<<s2;
        if( p > 1 ) cout<<"^"<<p;
        cout<<endl;
    }

    return 0;
}
