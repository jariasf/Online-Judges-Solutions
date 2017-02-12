/*****************************************
 ***Problema: Joana and the Odd Numbers
 ***ID: 913
 ***Juez: UVA
 ***Tipo: Recurrences
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
int main(){
    long long n , pos;
    while( scanf("%lld" , &n ) != EOF ){
        pos = ( ( n + 1 )/2 ) * ( n + 1 )/2;
        printf("%lld\n" , pos * pos - ( pos - 3 ) * ( pos - 3 )  );
    }
    return 0;
}
