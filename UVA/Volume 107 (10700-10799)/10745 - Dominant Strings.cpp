/*****************************************
 ***Problema: Dominant Strings
 ***ID: 10745
 ***Juez: UVA
 ***Tipo: Trie + Sorting
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

#define MAX 27

struct Node{
    int words;
    Node* hijo[ MAX ];
    Node(){
        words = 0;
        for( int i = 0 ; i < MAX ; ++i ) hijo[ i ] = NULL;
    }
};

class Trie{
    public:
    Trie(){
        root = new Node();
    }

    void insert( string s );
    bool contains( Node* t , string s , int len );
    Node* getRoot();
    private:
    Node* root;

};

Node* Trie:: getRoot(){
    return root;
}

void Trie::insert( string s ){
    int i;
    Node *t = root;
    for( i = 0 ; s[ i ] ; ++i ){
        if( t -> hijo[ s[ i ] - 'a' ] == NULL ) t -> hijo[ s[ i ] - 'a' ] = new Node();
        t = t -> hijo[ s[ i ] - 'a' ];
    }
    t -> words++;
}

bool Trie::contains( Node *t , string s , int len ){
    if( s[ len ] == '\0' ) return 1;
    if( t == NULL ) return 0;
    int i ;
    bool b = false;
    for( i = 0 ; i <= s[ len ] - 'a' ; ++i ){
        if( t -> hijo[ i ] != NULL ){
            b |= contains( t -> hijo[ i ] , s , ( s[ len ] - 'a' == i ? len + 1 : len ) );
            if( b ) return 1;
        }
    }
    return b;
}
#define MAXN 15005
char words[ MAXN ][ MAX ], aux[ MAX ];
int len;
struct Data{
    int first;
    string second;
    int len;
    Data( int f , string s , int l ): first( f ) , second( s ) , len( l ){}
};

bool cmp( Data s1 , Data s2 ){
    return s1.len > s2.len;
}
int main(){
    Trie* trie = new Trie();
    int i , j;
    len = 0;
    vector< Data > v;
    vector< string > ans;
    while( scanf("%s" , &words[ len ] ) != EOF ){
        strcpy( aux , words[ len++ ] );
        sort( aux , aux + strlen( aux ) );
        v.push_back( Data( len - 1 , aux , strlen( aux ) ) );
    }

    sort( v.begin() , v.end() , cmp );
    string ss;
    for( i = 0 ; i < len ; ++i ){
        if( trie -> contains( trie -> getRoot() , v[ i ].second , 0 ) )continue;
        trie -> insert( v[ i ].second );
        ans.push_back( words[ v[ i ].first ] );
    }
    sort( ans.begin() , ans.end() );
    for( i = 0 ; i < ans.size() ; ++i ) printf("%s\n" , ans[ i ].c_str() );

    delete trie;
    return 0;
}
