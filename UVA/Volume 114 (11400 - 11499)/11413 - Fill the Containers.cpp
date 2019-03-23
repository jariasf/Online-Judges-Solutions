/*****************************************
 ***Problema: Fill the Containers
 ***ID: 11413
 ***Juez: UVA
 ***Tipo: Binary Search
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
/*
Hallamos la suma de todos y buscamos el minimo valor del de mayor capacidad
{ 2 , 3 } { 4 }   { 3 , 4 } { 2 }
tenemos de mayor capacidad 2, el minimo es 5.
para ello si el numero de elementos q me kedan es mayor q el numero de contenedores
puedo ir sumando sino solamente evaluo contenedores
x ejemplo
5 3 2 5 y tengo 4 contenedores
lo posible sera 5 , 3 , 2 , 5
si tengo 3 contenedores puedo sumar los intermedios
5 , 5 , 5
*/
/*
casos
5 3
1 2 3 4 8
5 4
5 3 2 1 4
5 4
3 2 1 5 4
5 4
5 3 2 3 2
4 4
5 3 2 5

output
8
5
5
5
5
*/
#define MAX 1005
int a[ MAX ] , n , k ;

bool possible( int mid ){
    int sum = 0 , K = k - 1;
    for( int i = 0 ; i < n ; ++i ){
        if( a[ i ] > mid ) return false;
        if( n - i > K && sum + a[ i ] <= mid ){
            sum += a[ i ];
        }
        else{
            K--;
            sum = a[ i ];
        }
    }
    if( n >= k && K != 0 ) return false;
    return true;
}

int main(){
    int left , right , mid, ans;
    while( scanf("%d %d" , &n , &k ) == 2 ){
        right = 0;
        for( int i = 0 ; i < n ; ++i ){
            scanf("%d" , &a[ i ] );
            right += a[ i ];
        }
        left = 1;
        ans = 1<<30;
        right += 5;
        while( left < right ){
            mid = ( left + right ) >> 1;
            if( possible( mid ) ){
                ans = mid;
                right = mid;
            }
            else left = mid + 1;
        }
        printf("%d\n" , ans );
    }
    return 0;
}
