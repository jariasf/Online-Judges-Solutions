/*****************************************
 ***Problema: Naughty Sleepy Boys
 ***ID: 10427
 ***Juez: UVA
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

#define MAX 20
int start[ MAX ],  end[ MAX ];

void gen(){
    start[ 0 ] = 1; end[ 0 ] = 9;
    start[ 1 ] = 10; end[ 1 ] = 189;
    for( int i = 1 ; i < 10 ; ++i ){
        start[ i ] = start[ i - 1 ] * 10;
        end[ i ] = ( ( start[ i ] * 10 ) - start[ i ] ) * ( i + 1 ) + end[ i - 1 ];
    }
}

int getDigit( int num , int idx ){
    int cnt = 0;
    while( num > 0 ){
        if( cnt == idx ) return num % 10;
        cnt++;
        num /= 10;
    }
    return num % 10;
}

int main(){

    gen();
    int n , idx, num;
    while( scanf("%d" , &n ) != EOF ){
        //busco cuantos digitos tiene el indice
        for( idx = 0 ; idx < 9 ; ++idx )
            if( n <= end[ idx ] ) break;

        num = start[ idx ]; //numero inicial
		//veo la posicion comenzando desde 0 en el bloq
        n = n - 1 - ( ( idx - 1 >= 0 )? end[ idx - 1 ]:0 ); 
        num += n / ( idx + 1 );
        printf("%d\n" , getDigit( num , idx  - ( n % ( idx + 1 ) ) ) );
    }

    return 0;
}

/*
189
190
191
192
193
1000
10000
100000
1000000
10000000
99999999
*/
