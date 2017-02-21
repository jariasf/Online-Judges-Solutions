/*****************************************
 ***Problema: Ant on a Chessboard
 ***ID: 10161
 ***Juez: UVA
 ***Tipo: Recurrences
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

int main(){
    long long n , pos , x , y;
    while( scanf("%lld" , &n ) , n ){
        pos = ( long long ) ceil( sqrt( n ) ) - 1;
        if( pos & 1 ){
            if( pos * pos + pos + 1 >= n ){
                y = pos + 1;
                x = n - pos * pos;
            }
            else{
                x = pos + 1;
                y = ( pos + 1 ) - ( n - ( pos * pos + pos + 1 ) );
            }
        }
        else{
            if( pos * pos + pos + 1 >= n ){
                x = pos + 1;
                y = n - pos * pos;
            }
            else{
                y = pos + 1;
                x = ( pos + 1 )- ( n - ( pos * pos + pos + 1 ) ) ;
            }
        }
        printf("%lld %lld\n" , x , y );
    }
    return 0;
}
