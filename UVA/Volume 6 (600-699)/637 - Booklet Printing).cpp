/*****************************************
 ***Problema: Booklet Printing
 ***ID: 637
 ***Juez: UVA
 ***Tipo: Ad hoc
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

    int n, blank , len , k , i, sheet , cnt , s , f;
    while( scanf("%d" , &n ) , n ){
        printf("Printing order for %d pages:\n" , n );

        if( n == 1 ){
            puts("Sheet 1, front: Blank, 1");
            continue;
        }
        if( n == 2 ){
            puts("Sheet 1, front: Blank, 1");
            puts("Sheet 1, back : 2, Blank");
            continue;
        }
        blank = n % 4;
        k = 1;
        i = 1;
        len = n / 4 + ( ( n % 4 == 0)? 0:1 );
        sheet = len * 4;
        s = 1;
        cnt = 0;
        //numero de blanks
        blank = sheet % n;
        for( f = 1; k <= blank ; ++k , ++i ){
            if( f ){
                printf("Sheet %d, front: Blank, %d\n" , s , i);
                f = 0;
                cnt = ( cnt + 1 ) % 2;
            }
            else{
                printf("Sheet %d, back : %d, Blank\n" , s , i);
                f = 1;
                cnt = ( cnt + 1 ) % 2;
            }
            if( cnt == 0 ) s++;
        }

        for( int j = n ; k <=len * 2 ; ++k , j-- , i++ ){
            if( f ){
                printf("Sheet %d, front: %d, %d\n" , s , j , i);
                f = 0;
                cnt = ( cnt + 1 ) % 2;
            }
            else{
                printf("Sheet %d, back : %d, %d\n" , s , i , j );
                f = 1;
                cnt = ( cnt + 1 ) % 2;
            }
            if( cnt == 0 ) s++;
        }
    }

    return 0;
}
