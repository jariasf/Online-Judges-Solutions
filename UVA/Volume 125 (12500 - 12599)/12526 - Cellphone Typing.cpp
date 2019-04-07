/*****************************************
 ***Problema: Cellphone Typing
 ***ID: 12526
 ***Juez: UVA
 ***Tipo: Trie
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
using namespace std;
#define MAX 28
#define END 27
struct Node{
    Node *hijo[ MAX ];
    Node(){
        for( int i = 0 ; i < MAX ; ++i ) hijo[ i ] = NULL;
    }
};

class Trie{
    public:
    Trie(){
        root = new Node();
    }
    int solve( Node*t , char *s , int len , int sum );
    void insert( char *s );
    Node* getRoot();

    private:
    Node* root;
};

Node* Trie::getRoot(){
    return root;
}

void Trie::insert( char *s ){
    int i;
    Node *t = root;
    for( i = 0 ; s[ i ] ; ++i ){
        if( t -> hijo[ s[ i ] - 'a' ] == NULL )
            t -> hijo[ s[ i ] - 'a' ] = new Node();
        t = t -> hijo[ s[ i ] - 'a' ];
    }
    t -> hijo[ END ] = new Node();
}

int Trie::solve( Node*t , char *s , int len , int sum ){
    if( s[ len ] == '\0') return sum;
    int i , son = 0 , ans = 0;
    for( i = 0 ; i < MAX ; ++i ) if( t -> hijo[ i ] != NULL ) son++;
    if( len == 0 ) son = 2;
    ans += solve( t -> hijo[ s[ len ] - 'a' ] , s , len + 1 , sum + ( son > 1 ? 1 : 0 ) );
    return ans;
}

char s[ 100005 ][ 90 ];
int main(){
    int n , i , ans;
    while( scanf("%d" , &n ) != EOF ){
        Trie* trie = new Trie();
        for( i = 0 ; i < n && scanf("%s" , &s[ i ] ) ; ++i )
            trie -> insert( s[ i ] );
        ans = 0;
        for( i = 0 ; i < n  ; ++i )
            ans += trie -> solve( trie -> getRoot() , s[ i ] , 0 , 0 );
        printf("%.2lf\n" , ans/( double ) n );
        delete trie;
    }
    return 0;
}
