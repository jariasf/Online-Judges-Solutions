/*****************************************
 ***Problema: Determinate Prime
 ***ID: 10650
 ***Juez: TJU
 ***Tipo: Number Theory, sieve, primes, PA
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

#define MAX 32100
int prime[MAX],p[MAX];

void sieve(){
    for(int i = 0 ; i<MAX; i++)p[i]=1;

    for(int i = 2 ;i*i < MAX; i++){
        if(p[i]){
            for(int j = 2 ; j*i<MAX ; j++){
               p[j*i] = 0;
            }
        }
    }
    int id=0;
    for(int i = 2 ; i<MAX; i++){
        if(p[i])prime[id++]=i;
    }

}

int main(){
    sieve();
    int L,U,idx, cont,index,ant,act,dist;

    while(scanf("%d %d",&L,&U)){
        if(L == 0 && U == 0)break;

        int tmp = L;

        if(U < L){
           L = U;
           U = tmp;
        }
        idx=0;
        while(prime[idx]<L){
            idx++;
        }
        //arreglo de progresiones
        int a[MAX];
        //anterior de limite para verificar si anterior de L esta en la secuencia
        idx--;

        ant = prime[idx++]; act = prime[idx++]; dist = act-ant;
        a[0] = ant; a[1] = act;

        ant = act;
        cont = 2;
        index = 2;
        // U+50 para ver el limite superior si hay algun primo q esta en la secuencia y mayor a  U
        for(int i = prime[idx]; i <= U + 50 ; i = prime[++idx]){
            if(i - ant == dist){
				a[index++]=i;
				cont++;
			}
            else {
               if( cont > 2 ){

                  if( a[0] >= L && a[index-1] <= U){

                      printf("%d" , a[0]);
                      for(int j = 1; j < index; j++){
                          printf(" %d" , a[j]);
                      }
                      printf("\n");

                  }
               }
               cont=2; a[0]=ant; a[1]=i; dist= i - ant; index = 2; //inicializo todo
            }
            ant=i;
        }
    }
    return 0;
}
