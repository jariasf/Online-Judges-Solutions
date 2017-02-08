/*****************************************
 ***Problema: Nesting a Bunch of Brackets
 ***ID: 551
 ***Juez: UVA
 ***Tipo: Stack
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

struct Data{
    int idx, p;
    Data( int pp , int id ):p( pp ), idx( id ){}
};
//(* 1, { 2 ( 3 [ 4
int main(){

    char s[ 3005 ];
    int l;
    while( gets( s ) ){
        l = strlen( s );
        stack< Data > S;
        int ans = -1;
        for( int i = 0 , j = 0 ; i < l ; ++i , ++j ){
            if( s[ i ] == '(' ){
                if( i + 1 < l && s[ i + 1 ] == '*' ){
                    S.push( Data( 1 , j + 1 ) ); i++;
                }
                else{
                    S.push( Data( 3 , j + 1 ) );
                }
            }
            else if( s[ i ] == '{') S.push( Data( 2 , j + 1 ) );
            else if( s[ i ] == '[') S.push( Data( 4 , j + 1 ) );
            else if( s[ i ] == '}'){
                if( S.empty() ){
                    ans = i + 1;
                    break;
                }
                else{

                    if( S.top().p != 2 ){
                        ans = S.top().idx + 1;
                        break;
                    }
                    S.pop();
                }
            }
            else if( s[ i ] == ']' ){
                if( S.empty() ){
                    ans = j + 1;
                    break;
                }
                else{

                    if( S.top().p != 4 ){
                        ans = S.top().idx;
                        break;
                    }
                    S.pop();
                }
            }
            else if( s[ i ] == '*' ){
                if( i + 1 < l && s[ i + 1 ] == ')'){
                    if( S.empty() ){
                        ans = i + 1;
                        break;
                    }
                    else{
                        if( S.top().p != 1 ){
                            ans = S.top().idx;
                            break;
                        }
                        S.pop();
                    }
                }
            }
            else if( s[ i ] == ')'){
                if( S.empty() ){
                    ans = i + 1;
                    break;
                }
                else{
                    if( S.top().p != 2 ){
                        ans = S.top().idx;
                        break;
                    }
                    S.pop();
                }
            }
        }
        if( ans == -1 ) puts("YES");
        else printf("NO %d\n" , ans );
    }
    return 0;
}
