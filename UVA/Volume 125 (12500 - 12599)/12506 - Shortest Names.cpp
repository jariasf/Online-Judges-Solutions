/*****************************************
 ***Problema: Shortest Names
 ***ID: 12506
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
#define MAX 26 //alfabeto
struct Node{
    int prefijos , words;
    Node *hijo[ MAX ];
    Node(){
        prefijos = words = 0;
        for( int i = 0 ; i < MAX ; ++i ) hijo[ i ] = NULL;
    }
};

class Trie{

    public:

    Trie(){
        numNodos = 1;
        root = new Node();
    }

    int solve( Node *t , int len );
    void insert( char *s );
    Node* getRoot();

    private:

    Node* root;
    int numNodos;
};

Node* Trie::getRoot(){
    return root;
}
//Insertamos cadena al trie
void Trie::insert( char *s ){
    int i;
    Node *t = root;
    for( i = 0 ; s[ i ] ; ++i ){
        if( t -> hijo[ s[ i ] - 'a' ] == NULL ){
            t -> hijo[ s[ i ] - 'a' ] = new Node();
        }
        t = t -> hijo[ s[ i ] - 'a' ];
        t -> prefijos++;
    }
    t -> words++;
}
int ans;
int Trie::solve( Node *t , int len ){
    if( t -> prefijos == 1 ) return len;
    int ans = 0;
    for( int i = 0 ; i < MAX ; ++i ){
        if( t -> hijo[ i ] != NULL ){
            ans += solve( t -> hijo[ i ] , len + 1 );
        }
    }
    return ans;
}
#define MAXN 1000001
char s[ MAXN ];
int main(){
    int t , n , i;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d" , &n ) ){
        Trie* trie = new Trie();
        for( i = 0 ; i < n && scanf("%s" , &s ) ; ++i ){
            trie -> insert( s );
        }
        ans = 0;
        ans = trie -> solve( trie -> getRoot() , 0 );
        printf("%d\n" , ans );
        delete trie;
    }

    return 0;
}
