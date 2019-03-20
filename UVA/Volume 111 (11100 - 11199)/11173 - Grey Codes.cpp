/*****************************************
 ***Problema: Grey Codes
 ***ID: 11173
 ***Juez: UVA
 ***Tipo: Bitwise
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int solve(int n ,int k){
    if(n == 1)return  k;
    if(n > 1){
       if( k < (1<<(n - 1)) )return solve(n - 1 , k);
       if( k >= (1<<( n -1 )) )return  (1<<(n - 1)) + solve( n - 1, (1<<n) - k - 1 );
    }
}

int main(){
    int t , n , k;
    scanf("%d",&t);
    while(t -- ){
        scanf("%d %d",&n,&k);
        printf("%d\n",solve( n , k) );

    }
    return 0;
}
