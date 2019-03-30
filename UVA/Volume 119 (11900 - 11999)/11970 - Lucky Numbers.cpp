/*****************************************
 ***Problema: Lucky Numbers
 ***ID: 11970
 ***Juez: UVA
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

/*
Idea es como tengo raiz cuadrada, el numero resultado de N-X debe ser una potencia de 2
como 1 4 9 16, etc
por lo tanto si tengo N = 33 busco un X < 33 y una potencia de 2 menor q 33 N - X = P -> N - P = X
1^2 2^2 3^2 4^2 5^2. dentro de esas posibilidades resto para ver el posible X
33 - 1 = 32   -> tenemos 1
33 - 4 = 29   -> tenemos 2
33 - 9 = 24   -> tenemos 3
33 - 16 = 17  -> tenemos 4
33 - 25 = 8   -> tenemos 5

vemos si modulo es cero es un lucky number, en este caso solo tenemos 2 posbiles q son 32 y 24
*/

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

#define MAX 31622 //maximo potencia de 2 menor a 10^9

int main(){

    int t, n , p, a[ 100005 ], len;
    scanf("%d" , &t );
    for( int q = 1 ; q <= t ; ++q ){
        scanf("%d" , &n );
        printf("Case %d:" , q );
        len = 0;
        for( int i = 1 ; i <= MAX ; ++i ){
            if( i * i  > n ){
                break;
            }
            else{
                int val = n - ( i * i );
                if( val != 0 && val % i == 0 ){
                    a[ len++ ] = val;
                }
            }
        }
        for( int i = len - 1 ; i >= 0 ; --i )printf(" %d" , a[ i ]);
        printf("\n");

    }

    return 0;
}
