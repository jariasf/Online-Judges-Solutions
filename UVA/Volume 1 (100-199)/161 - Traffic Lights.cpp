/*****************************************
 ***Problema: Traffic Lights
 ***ID: 161
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

#define VERDE 0
#define NARANJA 1
#define ROJO 2
int main(){
    int a , b , c, value[ 105 ] , len , light[ 105 ] , green[ 105 ];
    while( scanf("%d %d %d" , &a , &b , &c ) , a | b | c ){
        value[ 0 ] = a;
        value[ 1 ] = b;
        light[ 0 ] = light[ 1 ] = VERDE;
        green[ 0 ] = a - 5;
        green[ 1 ] = b - 5;
        len = 2;
        while ( c != 0 ){
            value[ len ] = c;
            green[ len ] = c - 5;
            light[ len++ ] = VERDE;
            scanf("%d" , &c );
        }

        int min , i , t;
        for( t = 0 ; t <= 18000 ; ){

            for( min = green[ 0 ]  , i = 1 ; i < len ; ++i ){
                if( min > green[ i ] ) min = green[ i ];
            }

            for( t += min , i = 0 ; i < len ; ++i ){
                if( ( green[ i ] -= min ) > 0 )continue;
                if( light[ i ] == VERDE ){
                    light[ i ] = NARANJA;
                    green[ i ] = 5;
                }
                else if( light[ i ] == NARANJA ){
                    light[ i ] = ROJO;
                    green[ i ] = value[ i ];
                }
                else{
                    light[ i ] = VERDE;
                    green[ i ] = value[ i ] - 5;
                }
            }

            for( i = 0 ; i < len ; ++i ){
                if( light[ i ] != VERDE )break;
            }
            if( i == len )break;
        }
        if( t > 18000 ){
            puts("Signals fail to synchronise in 5 hours");
        }
        else{
            printf("%.2d:%.2d:%.2d\n" , t/3600 , ( t % 3600 )/60 , t % 60 );
        }
    }

    return 0;
}
