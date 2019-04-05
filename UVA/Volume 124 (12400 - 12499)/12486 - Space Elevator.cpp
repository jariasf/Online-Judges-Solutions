/*****************************************
 ***Problema: Space Elevator
 ***ID: 12486
 ***Juez: UVA
 ***Tipo: DP + Binary Search
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
#include <climits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 21

/**
Obtengo los digitos en un array para realizar el DP
**/
int digit[ MAX ] , sz;
void getDigits( unsigned long long n ){
    sz = 0;
    int digitInv[ MAX ] , i , j;
    while( n > 0 ){
        digitInv[ sz++ ] = n % 10;
        n /= 10;
    }
    for( i = sz - 1 , j = 0 ; i >= 0 ; --i , ++j ){
        digit[ j ] = digitInv[ i ];
    }
}

/**
Cuento la cantidad de numeros menores, que contienen digitos 4 y 13, a un numero dado con DP.
DP[ pos ][ correct ][ flag ][ ant ].
Estados:
* pos = la posicion del digito en el numero, empezamos desde la izquierda
* correct = si el numero posee digitos 4 y 13
* flag = para iterar sobre una cantidad de digitos x ejemplo si numero 504 si el flag es 0 en la posicion 0
         entonces puedo iterar desde 0 - 5. Si el flag es 1 en la posicion 1 puedo iterar 0 - 9.
* ant = digito anterior - para verificar el numero 13
**/

unsigned long long dp[ MAX ][ 2 ][ 2 ][ MAX ];
unsigned long long solve( int pos , bool correct , int flag, int ant ){
    if( pos == sz ){
        if( correct == 1 ) return 1;
        return 0;
    }

    if( ant >= 0 && dp[ pos ][ correct ][ flag ][ ant ] != -1LLU ) return dp[ pos ][ correct ][ flag ][ ant ];
    int maxDigit = digit[ pos ] , i;
    bool aux;
    if( flag ) maxDigit = 9;
    unsigned long long ans = 0;
    for( i = 0 ; i <= maxDigit ; ++i ){
        aux = correct;
        if( i == 4 || ( i == 3 && ant == 1 ) ) aux = 1;
        ans += solve( pos + 1 , aux , flag | ( ( i < digit[ pos ] )?1:0 ) , i );
    }
    if( ant >= 0 ) dp[ pos ][ correct ][flag ][ ant ] = ans;
    return ans;
}

int main(){
    unsigned long long n , cnt , left , right , mid , ans;
    while( scanf("%llu" , &n ) != EOF ){
        //Mediante busqueda binaria hallo la posicion
        left = 0; right = -1;
        while( left < right ){
            mid = ( left/2 + right/2 );
            getDigits( mid );
            memset( dp , -1 , sizeof( dp ) );
            cnt = solve( 0 , 0 , 0 , -1 );
            if( mid -cnt == n ) ans = mid;
            if( mid - cnt >= n ){
                right = mid;
            }
            else left = mid + 1;
        }
        printf("%llu\n" , ans );
    }
    return 0;
}
