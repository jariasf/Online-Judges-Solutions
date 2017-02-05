/*****************************************
 ***Problema: Packets
 ***ID: 311
 ***Juez: UVA
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int main(){
    int a , b , c , d , e , f , ans;
    while( scanf("%d %d %d %d %d %d" , &a , &b , &c , &d , &e , &f ) , a | b | c | d  |e |f ){
        ans = f;
        ans += e;
        a -= e * 11;

        ans += d;
        int falta = d * ( 36 - 16 );
        if( b > 0 ){
            int numB = 5 * d;
            if( b >= numB ) b -= numB , falta -= 4 * numB;
            else falta -= 4 * b , b = 0;
        }
        if( falta > 0 && a > 0 ){
            a -= falta;
        }
        ans += c/4;
        if( c % 4 != 0 ){
            falta = ( 36 - 9 * ( c % 4 ) );
            int cubo = c % 4;
            if( b > 0 ){
                if( cubo == 1 ){
                    if( b >= 5 ) b -= 5 , falta -= 4 * 5;
                    else falta -= 4 * b , b = 0;
                }
                else if( cubo == 2 ){
                    if( b >= 3 ) b -= 3 , falta -= 4 * 3;
                    else falta -= 4 * b , b = 0;
                }
                else if( cubo == 3 ){
                    if( b >= 1 ) b -= 1 , falta -= 4;
                    else falta -= 4 * b , b = 0;
                }
            }

            if( falta > 0 && a > 0 ){
                a -= falta;
            }
            ans++;
        }

        ans += b / 9;
        if( b % 9 != 0 ){
            ans++;
            falta = 36 - ( 4 * (b % 9) );
            a -= falta;
        }

        if( a > 0 ){
            ans += a / 36;
            if( a % 36 != 0 ) ans++;
        }
        printf("%d\n" , ans );
    }

    return 0;
}


/*
0 0 4 0 0 1
7 5 1 0 0 0
11 12 13 14 15 16
10 10 10 10 10 10
5000 1400 300 200 100 100
1 2 3 0 0 0
0 4 2 0 100 0
71 55 113 33 19 19
123 1420 1616 1321 101 0
9999 9999 9999 9999 999 999
731 165 9975 1235 874 11
1500 3000 1000 500 200 1
0 0 0 0 0 0
*/
