/*****************************************
 ***Problema: Benefit
 ***ID: 11889
 ***Juez: UVA
 ***Tipo: Number Theory, LCM
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

int pot( int a , int b ){
    int r = 1;
    for( int i = 1 ; i <= b ; ++i ) r *= a;
    return r;
}

int main(){

    int t , A , B , C, aux, cnt1 , cnt2 ;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d %d" , &A , &C );

        if( C % A != 0 ){ printf("NO SOLUTION\n"); continue;}
        B  = 1;
        for( int i = 2 ; i * i <= C ; ++i ){
            cnt1 = cnt2 = 0;
            while( C % i == 0 ){
                cnt1++;
                C /= i ;
            }
            while( A % i == 0 ){
                cnt2++;
                A /= i;
            }
            if( cnt1 > cnt2 ) B *= pot( i , cnt1 );
        }
        if( C > 1 && A == 1 ) B *= C;
        printf("%d\n" , B );
    }

    return 0;
}
