/*****************************************
 ***Problema: Multiplying by Rotation
 ***ID: 550
 ***Juez: UVA
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int main(){
    int base , n , m , i;
    while( scanf("%d %d %d" , &base , &n , &m ) != EOF ){
        if( m == 1 ) puts("1");
        else{
            int act = n , carry = 0;
            for( i = 1 ; ; ++i ){
                act = act * m + carry;
                carry = act / base;
                act %= base;
                if( carry == 0 && act == n ) break;
            }
            printf("%d\n" , i );
        }
    }

    return 0;
}
