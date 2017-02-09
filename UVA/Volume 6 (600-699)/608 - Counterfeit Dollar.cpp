/*****************************************
 ***Problema: Counterfeit Dollar
 ***ID: 608
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

    int t, len;
    bool even[ 27 ];
    char l[ 3 ][ 27 ] , r[ 3 ][ 27 ] , go[ 3 ][ 5 ];

    scanf("%d" , &t );
    while( t-- ){
        memset( even , 0 , sizeof( even ) );

        for( int i = 0 ; i < 3 ; ++i ){
            scanf("%s %s %s" , &l[ i ] , &r[ i ] , &go[ i ] );

            if( go[ i ][ 0 ] =='e' )
            {
                len = strlen( l[ i ] );
                for( int j = 0 ; j < len ; ++j ){
                    even[ l[ i ][ j ] - 'A' ] = even[ r[ i ][ j ] - 'A' ] = 1;
                }
            }
        }

        //asumo q letter es el incorrecto, verifico si cumple con las condiciones
        for( int letter = 'A' ; letter <= 'L' ; ++letter ){
            if( even[ letter - 'A' ] ) continue;
            int left = -1; //-1 nada 1 left 2 right
            int up = -1;   //-1 nada, 1 up, 2 down
            int cnt = 0;   //apariciones de caracter, si tengo una comparacion de up o down con otro caracter
            //aparte del q supongo entonces no es.
            for( int i = 0 ; i < 3 ; ++i ){
                if( go[ i ][ 0 ] =='e' ){ cnt++; continue;}

                len = strlen( l[ i ] );
                left = -1;
                //si caracter esta al lado izquierdo
                for( int j = 0 ; j < len ; ++j ){
                    if( l[ i ][ j ] == letter ){
                        left = 1;
                        break;
                    }
                    else if( r[ i ][ j ] == letter ){ //si esta al lado derecho
                        left = 2;
                        break;
                    }
                }
                if( left == -1 )continue;

                if( up != -1 ){
                    //si el q supongo es mas pesado y me contradice diciendo q esta en los livianos, entonces noes
                   if( left == 1 ){
                       if( up == 1 && go[ i ][ 0 ] == 'u' )break;
                       else if( up == 2 && go[ i ][ 0 ] == 'd')break;
                   }
                   else if( left == 2 ){
                       if( up == 1 && go[ i ][ 0 ] == 'd' )break;
                       else if( up == 2 && go[ i ][ 0 ] == 'u')break;
                   }

                    cnt++;
                    continue;
                }
                cnt++;
                //se ejecutara una vez para ver si es pesado o liviano
                if( left == 2){
                    if( go[ i ][ 0 ] == 'u')up = 1;
                    else up = 2;
                }
                else if( left == 1 ){
                    if( go[ i ][ 0 ] == 'u')up = 2;
                    else up = 1;
                }
            }

            if( cnt == 3 ){
                printf("%c is the counterfeit coin and it is " , letter );
                if( up == 1 )printf("light.\n");
                else printf("heavy.\n");
                break;
            }
        }
    }
    return 0;
}

/*
TEST
10
ABCD EFGH even
I J even
K A even
A B even
DE FG up
KG LI down
F G up
G K even
A I even
ABCDE FGHIJ even
K A even
B D even
BEF AGI down
AEF BGI up
B C down
ABC DEF up
GHI JKL even
EF DA up
AFG JKL down
A J down
A D even
ED FG even
AB CI up
A D up
IL JK even
A B even
E L down
BEF JIL down
J A even
CEF BJI even


6
CBA DEF up
AF BC up
BA CD up
CBA DEF up
A B up
BA CD up
CBA DEF up
B A down
BA CD up
CBA DEF down
AF BC down
BA CD down
CBA DEF down
A B down
BA CD down
CBA DEF down
B A up
BA CD down
*/
