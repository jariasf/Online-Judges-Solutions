/*****************************************
 ***Problema: Just the facts
 ***ID: 568
 ***Juez: UVA
 ***Tipo: Math, factorials
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<stdio.h>

int main(){
       int N;
       unsigned long long fact = 1;
       int factorial[10005];
       for(int i=1;i<=10000;i++){
            fact *= i;
            while( !(fact % 10) )
                    fact /= 10;

            fact %= 1000000;
            factorial[i]=fact;
       }

       while(scanf("%d",&N)!=EOF){
       		printf("%5d -> %d\n",N,factorial[N]%10);
       }

       return 0;
}

