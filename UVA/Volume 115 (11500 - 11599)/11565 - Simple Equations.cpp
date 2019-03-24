/*****************************************
 ***Problema: Simple Equation
 ***ID: 11565
 ***Juez: UVA
 ***Tipo: Brute Force
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
#define MAX 101
int main(){

    int t , A , B ,C;
    bool b;
    scanf("%d" , &t );
    while( t-- ){
        b = false;
        scanf("%d %d %d" , &A , &B , &C );
        for( int x = -100 ; x < MAX ; ++x ){
            for( int y = -100 ; y < MAX ; ++y ){
                if( x == y )continue;
                for( int z = -100 ; z < MAX ; ++z ){
                     if( y == z || x == z )continue;
                     if( x + y + z == A  && x * y * z == B && x * x + y * y + z * z == C ){
                        printf("%d %d %d\n"  , x , y , z );
                        b = true;
                        x = MAX;
                        y = MAX;
                        break;
                    }
                }
            }
        }
        if( !b )printf("No solution.\n");
    }


    return 0;
}
