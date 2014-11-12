/*****************************************
 ***Problema: Automated Checking Machine
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

#define MAX 10
int a[ MAX ];
int main(){
    int x;
    while( scanf("%d %d %d %d %d" , &a[0] , &a[1] , &a[2] , &a[3] , &a[4] ) != EOF ){
        bool b = true;
        for( int i = 0 ; i < 5 && scanf("%d" , &x ) ; ++i ){
            if( x == a[i] )
                b = false;
        }
        if( !b )
            puts("N");
        else
            puts("Y");
    }
    return 0;
}
