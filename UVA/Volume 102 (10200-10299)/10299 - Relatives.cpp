/*****************************************
 ***Problema: Relatives
 ***ID: 10299
 ***Juez: UVA
 ***Tipo: Number theory, totient function
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int countRelativelyPrime(int n) {
	int sum = n, i;
	for(i = 2; i*i<=n; i++) {
		if(n % i == 0) {
			sum -= sum/i;
		}
		while(n%i == 0) n /= i;
	}
	if(n > 1) sum -= sum/n;
	return sum;
}

int main(){
    int n;
    while(scanf("%d",&n) && n){
        if( n == 0 )break;
        if( n == 1 )printf("0\n");
        else printf("%d\n",countRelativelyPrime(n));

    }
    return 0;
}
