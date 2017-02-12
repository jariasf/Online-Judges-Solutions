/*****************************************
 ***Problema: Kaprekar Numbers
 ***ID: 974
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

int a[ 20 ] = { 9, 45 , 55, 99,297,703,999,2223,2728,4879,4950,5050,5292,7272,7777,9999,17344,22222,38962};
int main(){

    int t , q , L , U , i , b;
    scanf("%d" , &t );

    for( q = 0 ; q < t && scanf("%d %d" , &L , &U ); ++q ){
        if( q ) printf("\n");
        printf("case #%d\n" , q + 1 );
        b = 0;
        for( i = 0 ; i < 20 ; ++i ){
            if( a[ i ] >= L && a[ i ] <= U ){
                printf("%d\n" , a[ i ] );
                b = 1;
            }
        }
        if( !b ) puts("no kaprekar numbers");
    }

    return 0;
}
