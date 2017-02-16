/*****************************************
 ***Problema: Jimmy's Riddles
 ***ID: 10058
 ***Juez: UVA
 ***Tipo: Strings Grammar Check
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
/*
STATEMENT = ACTION | STATEMENT , ACTION
ACTION = ACTIVE_LIST VERB ACTIVE_LIST
ACTIVE_LIST = ACTOR | ACTIVE_LIST and ACTOR
ACTOR = NOUN | ARTICLE NOUN
ARTICLE = a | the
NOUN = tom | jerry | goofy | mickey | jimmy | dog | cat | mouse
VERB = hate | love | know | like | VERBs
*/

#define MAX 67000
char s[ MAX ] , token[ MAX ];
int idx , type , error;
char article[ 2 ][ 4 ] = { "a" , "the"};
char noun[ 8 ][ 8 ] = { "tom" , "jerry" , "goofy" , "mickey" , "jimmy" , "dog" , "cat" , "mouse" };
char verb[ 4 ][ 6 ] = { "hate" , "love" , "know" , "like"  };
bool isLetter( char c ){ return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }
void next(){
    if( error ){ type = 'f'; return;}
    if( idx == strlen( s ) ){ type = 'f'; token[ 0 ] = '\0'; return; } //f - finish
    //Eliminamos espacios en blanco
    for( ; s[ idx ] ; ++idx ) if( s[ idx ] != ' ' ){ break;}
    //Si puro espacios en blanco entonces terminamos
    if( idx == strlen( s ) ){ type = 'f'; token[ 0 ] = '\0'; return; }
    //Buscamos palabra
    int len = 0 , i , j;
    token[ 0 ] = '\0';
    //Obtengo token
    for( ; s[ idx ] ; ++idx ){
        if( !isLetter( s[ idx ] ) )break;
        token[ len++ ] = s[ idx ];
    }
    token[ len ] = '\0';
    //si no tenglo palabra tengo coma
    if( len == 0 ){
        token[ 0 ] = ','; token[ 1 ] = '\0';
        type = ','; idx++;
        return;
    }
    //Article
    for( i = 0 ; i < 2 ; ++i ) if( !strcmp( article[ i ] , token ) ){ type = 'a'; return; }
    //Noun
    for( i = 0 ; i < 8 ; ++i ) if( !strcmp( noun[ i ] , token ) ){ type = 'n'; return; }
    //And
    if( !strcmp("and" , token ) ){ type = '&'; return; }
    //Verbo = Verbos | hates | ...
    for( i = 0 ; i < 4 ; ++i ){
        for( j = 0 ; j < len ; ++j )
            if( token[ j ] != verb[ i ][ j ] ) break;
        if( j == len ){ type = 'v'; return; }
        for( ; j < len ; ++j )
            if( token[ j ] != 's') break;

        if( j == len ){ type = 'v'; return; }
    }
    error = 1;
    type = 'f';
    return;
}


int action(){
    //( Articulo Noun | Noun ) and ( Articulo Noun | Noun )...
    while( true ){
        if( type == 'a' ) next();
        if( type != 'n' ) return 0;
        next();
        if( type != '&' ) break;
        next();
    }
    // ____ Verb
    if( type != 'v' ) return 0;
    next();
    // ( Articulo Noun | Noun ) and ( Articulo Noun | Noun )...
    while( true ){
        if( type == 'a' ) next();
        if( type != 'n' ) return 0;
        next();
        if( type != '&' ) break;
        next();
    }
    return 1;
}

int statement(){
    next();
    while( type != 'f' ){
        if( !action() ) return 0;
        if( type == 'f' ) return 1;
        if( type != ',') return 0;
        next();
    }
    return 0;
}

int main(){
    while( gets( s ) ){
        token[ 0 ] = '\0'; idx = error = 0; type = -1;
        if( statement() && !error ) puts("YES I WILL");
        else puts("NO I WON'T");
    }
    return 0;
}

