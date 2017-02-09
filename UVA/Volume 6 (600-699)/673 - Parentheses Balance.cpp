/*****************************************
 ***Problema: Parentheses Balance
 ***ID: 673
 ***Juez: UVA
 ***Tipo: Ad hoc, Stacks
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <stack>
using namespace std;
#define MAX 130
char s[ MAX ];
bool possible(){
    stack< char > S;
    for( int i = 0 ; s[ i ] ; ++i ){
        if( s[ i ] == '(' || s[ i ] == '[' ) S.push( s[ i ] );
        else{
            if( !S.empty() ){
                char c = S.top(); S.pop();
                if( ( s[ i ] == ')' && c != '(' )|| ( s[ i ] == ']' && c != '[' ) ) return false;
            }
            else return false;
        }
    }
    if( S.size() ) return false;
    return true;
}

int main(){
    int t;
    scanf("%d" , &t );
    gets( s );
    while( t-- ){
        gets( s );
        if( possible() ) puts("Yes");
        else puts("No");
    }
    return 0;
}
