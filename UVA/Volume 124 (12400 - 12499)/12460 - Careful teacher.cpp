/*****************************************
 ***Problema: Careful teacher
 ***ID: 12460
 ***Juez: UVA
 ***Tipo: Union Find
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

#define MAX 200005

int padre[ MAX ];   //Este arreglo contiene el padre del i-esimo nodo
int rango[ MAX ];   //profundidad de cada vértice
void MakeSet( int n ){
    for( int i = 0 ; i < n ; ++i ){
        padre[ i ] = i;      //Inicialmente el padre de cada vértice es el mismo vértice
        rango[ i ] = 0;      //Altura o rango de cada vértice es 0
    }
}
int Find( int x ){
    if( x == padre[ x ] ){          //Si estoy en la raiz
        return x;                   //Retorno la raiz
    }
    //else return Find( padre[ x ] ); //De otro modo busco el padre del vértice actual, hasta llegar a la raiz.
    else return padre[ x ] = Find( padre[ x ] ); //Compresion de caminos
}
//Método para unir 2 componentes conexas usando sus alturas (rangos)
void Union( int x , int y ){
    int xRoot = Find( x );    //Obtengo la raiz de la componente del vértice X
    int yRoot = Find( y );    //Obtengo la raiz de la componente del vértice Y
    if( rango[ xRoot ] > rango[ yRoot ] ){ //en este caso la altura de la componente del vértice X es
                                           //mayor que la altura de la componente del vértice Y.
        padre[ yRoot ] = xRoot;            //el padre de ambas componentes será el de mayor altura
    }
    else{                    //en este caso la altura de la componente del vértice Y es mayor o igual que la de X
        padre[ xRoot ] = yRoot;            //el padre de ambas componentes será el de mayor altura
        if( rango[ xRoot ] == rango[ yRoot ] ){ //si poseen la misma altura
            rango[ yRoot ]++;              //incremento el rango de la nueva raíz
        }
    }
}
#define MAXN 10005
char s[ MAXN ] , su[ MAXN ] , sv[ MAXN ] , aux[ MAXN ];
struct Estado{
    string first;
    int second, id;
    Estado( string f , int s , int i ): first( f ) , second( s ) , id( i ){}
};
vector< Estado > v;

bool cmp( Estado p1 , Estado p2 ){
    return p1.second < p2.second || ( p1.second == p2.second && p1.first < p2.first );
}

int main(){
    map< string , int > mp;
    int cnt = 1;
    while( scanf("%s" , &s ) , s[ 0 ] != '-' ){
        v.push_back( Estado( string( s ) , strlen( s ) , cnt ) );
        mp[ s ] = cnt++;
    }
    MakeSet( cnt );
    sort( v.begin() , v.end() , cmp );
    int sz = v.size();
    for( int i = 0 ; i < sz ; ++i ){
        for( int j = i + 1 ; j < sz ; ++j ){
            if( v[ j ].second > v[ i ].second ) break;
            int dif = 0;
            for( int k = 0 ; k < v[ i ].second ; ++k ){
                if( v[ i ].first[ k ] != v[ j ].first[ k ] ) dif++;
                if( dif > 1 ) break;
            }
            if( dif == 1 ) Union( v[ i ].id , v[ j ].id );
        }
    }
    int u , v;
    while( scanf("%s %s" , &su , &sv ) == 2 ){
        u = mp[ su ];
        v = mp[ sv ];
        if( u && v && Find( u ) == Find( v ) ) puts("Yes");
        else puts("No");
    }
    return 0;
}
