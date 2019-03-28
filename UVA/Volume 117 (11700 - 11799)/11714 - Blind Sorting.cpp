/*****************************************
 ***Problema: Blind Sorting
 ***ID: 11714
 ***Juez: UVA
 ***Tipo: Binary tree, decision tree
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cmath>

//1ero busco el elemento mas largo reisando todo el arreglo//
//luego para el segundo busco en un arbol binario( heap sort )
int main(){
    int n;
    while( scanf("%d" , &n ) == 1 ){
        printf("%d\n" , n - 1 + (int)log2( n - 1) );
    }
    return 0;
}
