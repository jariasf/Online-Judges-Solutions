/*****************************************
 ***Problema: Filling the Gaps
 ***ID: 552
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
#include <climits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 2 //alfabeto
struct Node{
    int words;
    Node *hijo[ MAX ];
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

    void printAllWords( Node *raiz , string s );
    void insert( Node *raiz , char *s , int l );
    int countAllWords( Node *raiz );
    Node* getRoot();
    bool contains( char *s );

    private:
    Node* root;
};

Node* Trie::getRoot(){
    return root;
}

void Trie::insert( Node *t , char *s , int l ){
    if( s[ l ] == '\0' ){
        t -> words = 1;
        return;
    }
    if( s[ l ] == '*' ){
        if( t -> hijo[ 0 ] == NULL ) t -> hijo[ 0 ] = new Node();
        insert( t -> hijo[ 0 ] , s , l + 1 );

        if( t -> hijo[ 1 ] == NULL ) t -> hijo[ 1 ] = new Node();
        insert( t -> hijo[ 1 ] , s , l + 1 );
    }
    else{
        if( t -> hijo[ s[ l ] - '0' ] == NULL ) t -> hijo[ s[ l ] - '0' ] = new Node();
        insert( t -> hijo[ s[ l ] - '0' ] , s , l + 1 );
    }

}

void Trie::printAllWords( Node *t, string word = ""){
    if( t -> words > 0 ){
        printf("%s\n" , word.c_str());
    }
    int i;
    for( i = 0 ; i < MAX ; ++i ){
        if( t -> hijo[ i ] != NULL ) printAllWords( t -> hijo[ i ] , word + ( char )( i + '0' ) );
    }
}

int Trie::countAllWords( Node *t ){
    int ans = 0;
    if( t -> words > 0 ){
        ans++;
    }
    int i;
    for( i = 0 ; i < MAX ; ++i ){
        if( t -> hijo[ i ] != NULL ) ans += countAllWords( t -> hijo[ i ] );
    }
    return ans;
}

bool Trie::contains( char *s ){
    int i;
    Node *t = root;
    for( i = 0 ; s[ i ] ; ++i ){
        if( t -> hijo[ s[ i ] - '0' ] == NULL ) return false;
        t = t -> hijo[ s[ i ] - '0' ];
    }
    return t -> words > 0;
}
#define MAXN 16
char s[ 1005 ][ MAXN ] , str[ MAXN ];
int main(){
    int len , n , i , j , sum;
    while( scanf("%d %d" , &len , &n ) , len | n ){
        Trie *trie = new Trie();
        for( i = 0 ; i < n && scanf("%s" , &s[ i ] ) ; ++i )
            trie -> insert( trie -> getRoot( )  , s[ i ] , 0 );

        int cnt = trie -> countAllWords( trie -> getRoot() );

        if( cnt >= n ){
            set< string > _set;
            for( i = 0 ; i < n ; ++i ){
                for( j = 0 ; j < len ; ++j )
                    if( s[ i ][ j ] == '1' ) s[ i ][ j ] = '0';
                _set.insert( s[ i ] );
            }
            if( _set.size() != n ) puts("NO");
            else printf("YES %d\n" , cnt );
        }
        else puts("NO");
    }
    puts("YES 0");

    return 0;
}
