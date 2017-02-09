/*****************************************
 ***Problema: Coconuts, Revisited
 ***ID: 616
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

int main(){
    int i , n , maxi , aux , cnt;
    while( scanf("%d" , &n ) , n > -1 ){
        printf("%d coconuts, " , n);
        maxi = -1;
        for( i = 2 ; i <= sqrt( n - 1 ) + 1 ; ++i ){
            aux = n;
            cnt = 0;
            while( cnt != i ){
                aux--;
                if( aux % i == 0 ){
                    aux -= aux/i;
                    cnt++;
                }
                else{
                    cnt = -1;
                    break;
                }
            }
            if( aux % i == 0 ) maxi = i;
        }
        if( maxi == -1 ) printf("no solution\n");
        else printf("%d people and 1 monkey\n" , maxi );
    }

    return 0;
}
