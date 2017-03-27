/*****************************************
 ***Problema: 2 the 9s
 ***ID: 10922
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

int main(){

    char s[ 1005 ];
    int degree;
    long long sum, number;
    while( scanf("%s" , &s ) , strcmp( s , "0" )){
        sum = 0;
		for( int i = 0 ; s[ i ] ; ++i ){
			sum += s[ i ] - '0';
		}
		degree = 0;
		number = sum;
        while( number % 9 == 0 ){
            degree++;
            if( number == 9 )break;
            sum = 0;
            while( number > 0 ){
                sum += number % 10;
                number /= 10;
            }
            number = sum;
        }

        if( degree == 0 )printf("%s is not a multiple of 9.\n", s );
        else printf("%s is a multiple of 9 and has 9-degree %d.\n", s, degree );
    }

    return 0;
}
