/*****************************************
 ***Problema: Ferry Loading IV
 ***ID: 11034
 ***Juez: UVA
 ***Tipo: Queue
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
#define LEFT 0
#define RIGHT 1

int main(){

    int n , l , m , w, pos , viajes;
    char s[ 6 ];
    scanf("%d" , &n);
    while( n-- ){
        scanf("%d %d" , &l , &m );
        l *= 100;
        queue<int> left, right;
        while( m-- ){
            scanf("%d %s" , &w , &s );
            if( s[ 0 ] == 'l') left.push( w );
            else right.push( w );
        }
        viajes = 0;
        pos = LEFT;
        while( !left.empty() || !right.empty() ){
            w = 0;
            if( pos == LEFT ){
                while( !left.empty() ){
                    if( w + left.front() > l )break;
                    w += left.front();
                    left.pop();
                }
            }
            else{
                while( !right.empty() ){
                    if( w + right.front() > l )break;
                    w += right.front();
                    right.pop();
                }
            }
            viajes++;
            pos = !pos;
        }
        printf("%d\n" , viajes );
    }

    return 0;
}
