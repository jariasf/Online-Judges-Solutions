/*****************************************
 ***Problema: To Carry or not to Carry
 ***ID: 10469
 ***Juez: UVA
 ***Tipo: Bitwise
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int main(){
    unsigned int a , b;
    while( scanf("%u %u" , &a  ,&b ) != EOF ){
        printf("%u\n" , a^b );
    }

    return 0;
}
