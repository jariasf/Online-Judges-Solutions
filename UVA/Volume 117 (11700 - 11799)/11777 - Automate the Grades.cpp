/*****************************************
 ***Problema: Automate the Grades
 ***ID: 11777
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

char get( int n ){
    if( n >= 90 ) return 'A';
    if( n >= 80 ) return 'B';
    if( n >= 70 ) return 'C';
    if( n >= 60 ) return 'D';
    return 'F';
}

int main(){

    int t, x,  a , b , c, maxi, maxi2;
    double sum;
    scanf("%d" , &t );
    for( int q = 1 ; q <= t ; ++q ){
        sum = 0;
        for( int j = 0 ; j < 4;  ++j ){
            scanf("%d" , &x );
            sum += x;
        }
        scanf("%d %d %d" , &a , &b , &c );
        maxi = a;
        if( b > maxi ){
            maxi = b;
            maxi2 = c;
            if( a > c ) maxi2 = a;
        }
        else if( c > maxi ){
            maxi = c;
            maxi2 = b;
            if( a > b ) maxi2 = a;
        }
        else{
            maxi2 = b;
            if( c > b ) maxi2 = c;
        }
        sum += ( maxi + maxi2 )/2.0;

        printf("Case %d: %c\n" , q , get( sum ) );

    }

    return 0;
}
