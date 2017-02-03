/*****************************************
 ***Problema: Ecological Bin Packing
 ***ID: 102
 ***Juez: UVA
 ***Tipo: Ad hoc, Brute Force
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
#define MAX 5
#define BLUE 0
#define GREEN 1
#define CLEAR 2

int color[ MAX ][ MAX ];
char s[ 4 ] = "BGC";
int main(){

    while( scanf("%d" , &color[0][0] ) != EOF ){
        for( int i = 1 ; i < 3 && scanf("%d" , &color[0][i]); ++i );
        for( int i = 0 ; i < 3 && scanf("%d" , &color[1][i]); ++i );
        for( int i = 0 ; i < 3 && scanf("%d" , &color[2][i]); ++i );

        int a[] = { 0 , 1 , 2 };
        int mini = 1<<30;
        string res = "";
        do{
            int ans = 0;
            for( int i = 0 ; i < 3 ; ++i ){
                for( int j = 0 ; j < 3 ; ++j ){
                    if( a[i] != j ){
                        ans += color[ i ][ j ];
                    }
                }
            }

            if( ans < mini ){
                mini = ans;
                res = "";
                for( int i = 0 ; i < 3 ; ++i )
                    res += s[ a[i]];
            }else if( ans == mini ){
                string aux = "";
                for( int i = 0 ; i < 3 ; ++i )
                    aux += s[a[i]];
                if( aux < res )
                    res = aux;
            }

        }while( next_permutation( a , a + 3 ));
        printf("%s %d\n" , res.c_str() , mini );
    }

    return 0;
}
