/*****************************************
 ***Problema: Perfection
 ***ID: 382
 ***Juez: UVA
 ***Tipo: Ad hoc, number theory
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<stdio.h>

int main(){
    int n,i,aux,sum,c=1;
    while(scanf("%d",&n) && n!=0){
        if(c==1)printf("PERFECTION OUTPUT\n");
        sum=0;
        aux=n;
        for(i=1;i<aux;i++){
            if(n%i==0){
               sum+=i;
            }
        }
        if(sum==aux) printf("%5d  PERFECT\n",aux);
        else if(sum<aux)printf("%5d  DEFICIENT\n",aux);
        else if(sum>aux)printf("%5d  ABUNDANT\n",aux);
        c++;
    }
    printf("END OF OUTPUT\n");

    return 0;
}
