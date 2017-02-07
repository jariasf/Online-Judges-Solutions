/*****************************************
 ***Problema: Decoder
 ***ID: 458
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<stdio.h>

int main(){
    char buffer;

    while(scanf("%c", &buffer)!=EOF)
        printf("%c",(buffer=='\n')? buffer:(buffer-7));

    return 0;
}
