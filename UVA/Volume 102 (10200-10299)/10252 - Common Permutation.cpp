/*****************************************
 ***Problema: Common Permutation
 ***ID: 10252
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

using namespace std;

int main(){
    char s1[4005], s2[4005];
    int v;
    while( gets(s1) && gets(s2)){
        int a[26] = {0}, b[26] = {0};
        for( int i = 0 ; s1[i] ; ++i ){
           if( s1[i] >= 'a' && s1[i] <= 'z') a[ s1[i] - 'a']++;
        }

        for( int i = 0 ; s2[i] ; ++i ){
           if( s2[i] >= 'a' && s2[i] <= 'z') b[ s2[i] - 'a']++;
        }

        for(int i = 0 ; i < 26 ; ++i ){
            v = ( a[i] < b[i] ) ? a[i] : b[i];
            while( v-- ) putchar(i+'a');
        }
        putchar('\n');

    }

    return 0;
}
