/*****************************************
 ***Problema: Eeny Meeny
 ***ID: 180
 ***Juez: UVA
 ***Tipo: Simulation, Josephus
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

int survivor( int n , int m ){
    int s = 0;
    for( int i = 1 ; i <= n ; ++i ) s= ( s + m ) % i;
    return s + 1;
}

int main(){
    int l , u, mini, s, resp;

    while( scanf("%d %d" , &l , &u ) && l|u ){
        mini = 1<<30;
        for( int i = l ; i <= u ; ++i ){
            s = survivor( i , 15 );
            cout<<s<<endl;
            if( abs( 1 - s ) < mini ){ mini = abs( 1 - s ); resp = s; }
        }
        cout<<resp<<endl;
    }
    return 0;
}
