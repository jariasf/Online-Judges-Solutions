/*****************************************
 ***Problema: Schedule of a Married Man
 ***ID: 12136
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int main(){

    int t , hi , mi , hf , mf , wife_ini , wife_fin , meet_ini , meet_fin ;

    scanf("%d" , &t );

    for( int q = 1 ; q <= t ; ++q ){

        scanf("%d:%d %d:%d" , &hi , &mi , &hf , &mf );

        wife_ini = hi * 60 + mi;
        wife_fin = hf * 60 + mf;
        scanf("%d:%d %d:%d" , &hi , &mi , &hf , &mf );

        meet_ini = hi * 60 + mi;
        meet_fin = hf * 60 + mf;

        printf("Case %d: " , q );
        if( ( meet_ini <= wife_ini && meet_fin >= wife_fin ) || ( meet_ini <= wife_fin && meet_ini >= wife_ini ) || ( meet_fin <= wife_fin &&meet_fin >= wife_ini )  )
            puts("Mrs Meeting");
        else puts("Hits Meeting");
    }

    return 0;
}
