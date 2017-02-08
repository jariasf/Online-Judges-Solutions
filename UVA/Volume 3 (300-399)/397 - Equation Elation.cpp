/*****************************************
 ***Problema: Equation Elation
 ***ID: 397
 ***Juez: UVA
 ***Tipo: String Parsing
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
#define MAX 1000
char s[ MAX ];
char token[ MAX ];
int idx , type , num , ant;
int ten[ ] = { 1 , 10 ,100 , 1000 , 10000 , 100000 , 1000000 , 10000000 };
bool isDigit( char c ){ return ( c >= '0' && c <= '9'); }
bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}
/*
Separo el string en tokens con sus tipos
*/
void next(){
    int len = 0 , i , j;
    //delete spaces
    token[ 0 ] = '\0';
    for( ; s[ idx ] ; ++idx ){ if( s[ idx ] != ' ' ) break; }

    if( isLetter( s[ idx ] ) ){
        for( ; s[ idx ] ; ++idx ){
            if( !isLetter( s[ idx ] ) )break;
            token[ len++ ] = s[ idx ];
        }
        token[ len ] = '\0';
        return;
    }

    if( !isDigit( s[ idx ] ) ){
        token[ len++ ] = s[ idx++ ];
        if( !isDigit( s[ idx ] ) || ( isDigit( s[ idx ] ) && ant == 'n' ) ){ type = s[ idx - 1 ];  return; }
    }

    for( ; s[ idx ] ; ++idx ){
        if( isDigit( s[ idx ] ) ) token[ len++ ] = s[ idx ];
        else break;
    }

    if( len != 0 ){
        int ini = ( isDigit( token[ 0 ] ) )?0:1;
        num = 0;
        for( i = len - 1 , j = 0 ; i >= ini ; --i ){
            num = ( token[ i ] - '0' ) * ten[ j++ ] + num;
        }
        type = 'n';
        if( ini ){
            if( token[ 0 ] == '-' )num = -num;
        }
        return;
    }
}

#define pb push_back
vector< int > v;
vector< int > types;
char end[ MAX ];
/*
Guardo en vector v los valores y en vector types los tipos de cada valor si es entero o signo
*/
void parse(){
    types.clear();
    v.clear();
    next();
    ant = type;
    v.pb( num );
    types.pb( type );
    while( type != '=' ){
        next();
        ant = type;
        if( type == '=' ) break;
        v.pb( type );
        types.pb( type );
        next();
        ant = type;
        v.pb( num );
        types.pb( type );
    }
    v.pb( type );
    types.pb( type );
    next();
    memcpy( end , token , sizeof( token ) );
}

void print(){
    int i , n = v.size() ;
    printf("%d" , v[ 0 ] );
    for( i = 1 ; i < n ; ++i ){
        if( i & 1 ) printf(" %c" , v[ i ] );
        else printf(" %d" , v[ i ] );
    }
    printf(" %s\n" , end );
}
/*
Busco iterando algun * o / y opero si no tengo esos signos
busco + o - y opera sino termino.
*/
void solve(){
    int i , n = v.size() , j , signo;
    vector< int > aux , auxT;
    while( true ){
        print();
        n = v.size();
        aux.clear();
        auxT.clear();
        signo = -1;
        for( i = 0 ; i < n ; ++i ){
            if( types[ i ] == '*' || types[ i ] == '/' ){
                signo = types[ i ];
                i--;
                break;
            }
        }
        if( signo == '*' || signo == '/' ){
            for( j = 0 ; j < i ; ++j ){
                aux.pb( v[ j ] );
                auxT.pb( types[ j ] );
            }
            if( signo == '*' ){
                aux.pb( v[ i ] * v[ i + 2 ] );
                auxT.pb( 'n' );
            }
            else{
                aux.pb( v[ i ]/v[ i + 2 ]);
                auxT.pb( 'n' );
            }
            for( j = i + 3 ; j < n ; ++j ){
                aux.pb( v[ j ] );
                auxT.pb( types[ j ] );
            }
        }
        else{

            for( i = 0 ; i < n ; ++i ){
                if( types[ i ] == '+' || types[ i ] == '-' ){
                    signo = types[ i ];
                    i--;
                    break;
                }
            }
            if( signo == '+' || signo == '-' ){
                for( j = 0 ; j < i ; ++j ){
                    aux.pb( v[ j ] );
                    auxT.pb( types[ j ] );
                }
                if( signo == '+' ){
                    aux.pb( v[ i ] + v[ i + 2 ] );
                    auxT.pb( 'n' );
                }
                else{
                    aux.pb( v[ i ] - v[ i + 2 ]);
                    auxT.pb( 'n' );
                }
                for( j = i + 3 ; j < n ; ++j ){
                    aux.pb( v[ j ] );
                    auxT.pb( types[ j ] );
                }
            }
            else break;
        }
        v = aux;
        types = auxT;
    }
}

int main(){
    bool b = false;
    while( gets( s ) ){
        if( b ) printf("\n");
        b = true;
        idx = 0;
        ant = -1;
        parse();
        solve();
    }
    return 0;
}
