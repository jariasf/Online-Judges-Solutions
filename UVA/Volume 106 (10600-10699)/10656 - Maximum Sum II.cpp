/*****************************************
 ***Problema: Maximum Sum II
 ***ID: 10656
 ***Juez: UVA
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
int main(){
	int a, n, k;
	while ( scanf( "%d" , &n ) , n ) {
		for( k = 0 ; n-- > 0 && scanf( "%d", &a ) == 1 ; )
			if ( a > 0 )
				printf( k++ ? " %d" : "%d" , a );
		printf( ( !k ) ? "0\n" : "\n");
	}
	return 0;
}

