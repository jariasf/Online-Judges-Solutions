/*****************************************
 ***Problema: The Last Non-zero Digit
 ***ID: 10212
 ***Juez: UVA
 ***Tipo: Prime Factorization
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
    long long n , m , i , dos , cinco , aux , MOD , ceros , ans;
    while( scanf("%lld %lld" , &n , &m ) != EOF ){
        dos = cinco = 0;
        m = n - m + 1;
        ans = 1;
        for( i = m ; i <= n ; ++i ){
            aux = i;
            while( aux % 2 == 0 ){
                dos++;
                aux /= 2;
            }
            while( aux % 5 == 0 ){
                cinco++;
                aux /= 5;
            }
            ans = ( ans % 10 * aux % 10 ) % 10;
        }
        if( dos < cinco ) for( i = dos ; i < cinco ; ++i ) ans = ( ans % 10 * 5 ) %10 ;
        else for( i = cinco ; i < dos ; ++i ) ans = ( ans % 10 * 2 ) %10 ;
        printf("%lld\n" , ans );
    }

    return 0;
}
