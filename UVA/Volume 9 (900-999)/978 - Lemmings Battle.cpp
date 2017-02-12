/*****************************************
 ***Problema: Lemmings Battle!
 ***ID: 978
 ***Juez: UVA
 ***Tipo: Binary search
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

    int t , batles, green , blue , x , len;
    vector<int> g , b;
    vector<int>::iterator low;
    scanf("%d" , &t );
    for( int q = 0 ; q < t ; ++q ){
        if( q )putchar('\n');
        scanf("%d %d %d" , &batles  ,&green , &blue );
        for( int i = 0 ; i < green ; ++i ){
            scanf("%d" , &x );
            g.push_back( x );
        }
        for( int i = 0 ; i < blue ; ++i ){
            scanf("%d" , &x );
            b.push_back( x );
        }
        sort( g.begin() , g.end() );
        sort( b.begin() , b.end() );

        while( 1 ){

            len = min( batles , min( (int)g.size() , (int)b.size() )  );
            vector<int> gi , bi;

            for( int i = 0 ,lg, lb  ; i < len ; ++i  ){
                lg = g.size() - 1 ; lb = b.size() - 1;
                if( g[ lg ] > b[ lb ] ){
                    gi.push_back( g[ lg ] - b[ lb ] );
                }
                else if( b[ lb ] > g[ lg ]){
                    bi.push_back( b[ lb ] - g[ lg ] );
                }
                g.pop_back();
                b.pop_back();
            }

            //insertamos sobrevivientes en arreglo ordenado

            for( int i = 0 ; i < gi.size() ; ++i ){
                low = lower_bound( g.begin() , g.end() , gi[ i ] );
                g.insert( low , gi[ i ] );
            }

            for( int i = 0 ; i < bi.size() ; ++i ){
                low = lower_bound( b.begin() , b.end() , bi[ i ] );
                b.insert( low , bi[ i ] );
            }

            if( g.size() == 0 ){
                if( b.size() == 0 ){
                    puts("green and blue died");
                    break;
                }
                else{
                    puts("blue wins");

                    for( int i = b.size() - 1 ; i >=0 ; --i )
                        printf("%d\n" , b[ i ] );

                    break;
                }
            }
            else if( g.size() > 0 && b.size() == 0){
                puts("green wins");

                for( int i = g.size() - 1 ; i >=0 ; --i )
                    printf("%d\n" , g[ i ] );

                break;
            }
        }

        g.clear();
        b.clear();
    }

    return 0;
}
