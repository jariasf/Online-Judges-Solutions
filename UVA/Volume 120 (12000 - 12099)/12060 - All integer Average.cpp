/*****************************************
 ***Problema: All Integer Average
 ***ID: 12060
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cmath>
int gcd(int a , int b){
   return  ( b == 0 ) ? a:gcd( b , a % b );
}
int main(){

    int q = 1, n , x;
    bool negative;
    int num, denom , digitos;
    while( scanf("%d" , &n ) , n ){
        denom = n;
        num = 0;
        while( n-- ){
            scanf("%d" , &x );
            num += x;
        }
        negative = false;
        if( num < 0 ){ negative = true; num = -num;}
        printf("Case %d:\n" , q++ );
        if( negative && num % denom == 0 )printf("- ");
        else if( negative )printf("  ");
        if( num % denom == 0 ){
            printf("%d\n" , num/denom);
        }
        else{
            int mcd = gcd( num , denom );
            num = num/mcd; denom /= mcd;

            digitos = (int) log10( denom ) + 1;
            int aux = num/denom , nn = num;
            int d= (int) log10( aux ) + 1;
            for( int i = 0 ; i < d ; ++i )printf(" ");

            if( num > denom ) num = num - ( aux * denom);
            printf("%*d\n" , digitos , num);
            if( negative )printf("- ");
            if( aux > 0 ){

                printf("%d" , aux );
            }

            for( int i = 0 ; i < digitos ; ++i )printf("-");
            printf("\n");
            if( negative )printf("  ");
            for( int i = 0 ; i < d ; ++i )printf(" ");
            printf("%d\n",  denom);

        }
    }
    return 0;
}
