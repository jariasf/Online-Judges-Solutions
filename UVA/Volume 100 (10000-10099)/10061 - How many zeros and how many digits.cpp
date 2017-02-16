/***********************************************
 ***Problema: How many zeros and how many digits
 ***ID: 10061
 ***Juez: UVA
 ***Tipo: Logarithms
 ***Autor: Jhosimar George Arias Figueroa
 ***********************************************/

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
/*
  Dado un numero N y una base B hallar:
   - Numero de zeros al final del N! en base B
   - Numero de digitos de N! en base B
*/
#define MAX 1050005
double f[ MAX ];
int trailzero( int num , int base )
{
    unsigned max = UINT_MAX , factordim , i ;
    for( i = 2 ; i <= base ; ++i )
    {
        factordim = 0;
        while( base % i == 0 )
        {
            factordim++;
            base /= i;
        }
        if( factordim > 0 )
        {
            int numfactor = 0 , j = i;
            for ( ; j <= num; j *= i )
                numfactor += num / j;
            if( max > numfactor / factordim )
                max = numfactor / factordim;
        }
    }
    return max;
}

int main(){
    int num , base , i;
    for( i = 1 ; i < MAX ; ++i ) f[ i ] = log( i ) + f[ i - 1 ];
    while( scanf("%d %d" , &num , &base ) != EOF ){
        printf("%u %0.lf\n" , trailzero( num , base ) , 
							  floor( f[ num ] / ( f[ base ] - f[ base - 1 ] ) + 1e-9 ) + 1.0 );
    }
    return 0;
}
