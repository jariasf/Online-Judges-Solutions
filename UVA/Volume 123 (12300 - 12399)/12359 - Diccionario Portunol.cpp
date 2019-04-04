/*****************************************
 ***Problema: Diccionario Portunol
 ***ID: 12359
 ***Juez: UVA
 ***Tipo: Trie
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
#define MAX 26
struct Node{
    Node* hijo[ MAX ];
    Node(){
        for( int i = 0 ; i < MAX ; ++i ) hijo[ i ] = NULL;
    }
};


class Trie{
    public:

    Trie(){
        rootPrefix = new Node();
        rootSuffix = new Node();
    }

    void insertPrefix( char *s );
    void insertSuffix( char *s );
    void solve( Node* t , int depth );
    Node* getRoot();
    private:
    Node* rootSuffix , *rootPrefix;
};

Node* Trie::getRoot(){
    return rootPrefix;
}
void Trie::insertPrefix( char *s ){
    int i;
    Node* t = rootPrefix;
    for( i = 0 ; s[ i ] ; ++i ){
        if( t -> hijo[ s[ i ] - 'a' ] == NULL ){
            t -> hijo[ s[ i ] - 'a' ] = new Node();
        }
        t = t -> hijo[ s[ i ] - 'a' ];
    }
}

int suffix[ MAX ]; //cantidad de sufijos que inician con la letra suffix[ i ]
bool start[ MAX ];
void Trie::insertSuffix( char *s ){
    int i , len = strlen( s );
    Node* t = rootSuffix;
    start[ s[ len - 1 ] - 'a' ] = 1;
    for( i = len - 1 ; i >= 0 ; --i ){
        if( t -> hijo[ s[ i ] - 'a' ] == NULL ){
            t -> hijo[ s[ i ] - 'a' ] = new Node();
            suffix[ s[ i ] - 'a' ]++;
        }
        t = t -> hijo[ s[ i ] - 'a' ];
    }
}

long long ans;
void Trie::solve( Node* t , int depth ){
    for( int i = 0 ; i < MAX ; ++i ){
        if( t -> hijo[ i ] != NULL ){
            solve( t -> hijo[ i ] , depth + 1 );
            if( depth > 0 && start[ i ] ) ans++;
        }
        else if( depth > 0 ){
            ans += suffix[ i ];
        }
    }
}

#define MAXN 1005
char s[ MAXN ];
int main(){
    int n , m , i;
    while( scanf("%d %d" , &n , &m ) , n | m ){
        memset( suffix , 0 , sizeof( suffix ) );
        memset( start , 0 , sizeof( start ) );
        Trie *trie = new Trie();
        for( i = 0 ; i < n && scanf("%s" , &s ) ; ++i )
            trie -> insertPrefix( s );

        for( i = 0 ; i < m && scanf("%s" , &s ) ; ++i )
            trie -> insertSuffix( s );
        ans = 0;
        trie -> solve( trie -> getRoot() , 0 );
        cout<<ans<<endl;
        delete trie;
    }

    return 0;
}
