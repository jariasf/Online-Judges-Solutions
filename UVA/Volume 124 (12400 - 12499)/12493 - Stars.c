/*****************************************
 ***Problema: Stars
 ***ID: 12493
 ***Juez: UVA
 ***Tipo: Phi de Euler
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

long long countRelativelyPrime( long long n ) {
	long long sum = n, i;
	for(i = 2 ; i * i <= n ; ++i ) {
		if( n % i == 0 ) {
			sum -= sum/i;
		}
		while( n % i == 0 ) n /= i;
	}
	if( n > 1 ) sum -= sum/n;
	return sum;
}

int main(){
    long long n;
    while( scanf("%lld" , &n ) != EOF ){
        printf("%lld\n" , countRelativelyPrime( n )/2 );
    }
    return 0;
}
