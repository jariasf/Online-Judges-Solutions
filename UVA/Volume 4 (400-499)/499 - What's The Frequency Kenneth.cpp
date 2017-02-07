/*****************************************
 ***Problema: What's The Frequency, Kenneth?
 ***ID: 449
 ***Juez: UVA
 ***Tipo: Ad hoc, Sorting
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;
#define MAX 5000

int main(){

    char s[MAX];
    int max, l;
    while( gets ( s ) ){
       int abc[60] = {0};
       l=strlen( s );
       for( int i = 0 ; i < l  ; ++i){
           if(isalpha( s[i] ) ){
              abc[ s[i]-'A' ]++;
           }
       }

       max = -1;
       for( int i = 0 ; i < 60 ; ++i ){ if(abc[i] != 0 ) max = std::max( max , abc[i] ); }

       for( int i = 0 ; i < 60 ; ++i ){
          if( abc[i] == max ){
             putchar((char)( i + 'A' ) );
          }
       }
       if(max != -1)printf(" %d\n",max);
    }
    return 0;
}
