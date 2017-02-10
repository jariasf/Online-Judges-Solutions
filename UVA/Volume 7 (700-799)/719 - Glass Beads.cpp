/*****************************************
 ***Problema: Glass Beads
 ***ID: 719
 ***Juez: UVA
 ***Tipo: Minimum Lexicographic Rotation
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
char s[10001];
int main(){
    int t;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%s",s ) ){
        int N = strlen( s ) , ans = 0 , p = 1 , l = 0;

        while( p < N && ans + l + 1 < N ){
            if( s[ ans + l ] == s[ ( p + l ) % N ] ) ++l;
            else if( s[ ans + l ] < s[ ( p + l ) % N ] ){
                p = p + l + 1;
                l = 0;
            }else{
                ans = max( ans + l + 1 , p );
                p = ans + 1;
                l = 0;
            }
        }
        //minimo numero de movimientos
        printf("%d\n",ans + 1 );
    }
    return 0;
}
