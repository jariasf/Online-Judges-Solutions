/*****************************************
 ***Problema: Zero or One
 ***ID: 12646
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
int main(){
    int a , b , c;
    while( scanf("%d %d %d" , &a , &b , &c ) != EOF ){
        if( (a && !b && !c) || ( !a && b && c ) ) puts("A");
        else if( (!a && b && !c) || ( a && !b && c ) ) puts("B");
        else if( (!a && !b && c) || ( a && b && !c ) ) puts("C");
        else puts("*");
    }
    return 0;
}
