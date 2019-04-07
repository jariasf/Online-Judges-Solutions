/*****************************************
 ***Problema: Hours and Minutes
 ***ID: 12531
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
int main(){
    int n;
    while( scanf("%d" , &n ) != EOF ){
        printf("%s\n" , ( n % 6 == 0 )?"Y":"N" );
    }
    return 0;
}
