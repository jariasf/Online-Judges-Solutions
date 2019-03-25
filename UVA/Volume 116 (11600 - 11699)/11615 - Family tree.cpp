/*****************************************
 ***Problema: Family Tree
 ***ID: 11615
 ***Juez: UVA
 ***Tipo: Tree
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
    int t , a , b , h , na , nb;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d %d %d" , &h , &a , &b );
        a++; b++;
        //entre que pontencia de dos esta
        na = (int)( ceil( log( a ) / log( 2 ) ) );
        nb = (int)( ceil( log( b ) / log( 2 ) ) );
        printf("%d\n" , ( 1<<h ) - min( ( 1<<( h - na + 1 ) ) - 2 , ( 1<<( h - nb + 1 ) ) - 2 ) - 1 );
    }

    return 0;
}
