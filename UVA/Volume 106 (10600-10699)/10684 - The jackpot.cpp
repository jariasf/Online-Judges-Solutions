/*****************************************
 ***Problema: The jackpot
 ***ID: 10684
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int main(){
    int n, max, x , sum;
    while( scanf("%d",&n)  && n){
        sum = 0;
        max = 0;
        for(int i = 0 ; i < n; i++){
           scanf("%d",&x);
           sum+=x;
           if( sum > max) max = sum;
           if( sum < 0) sum = 0;
        }
        if( max > 0)printf("The maximum winning streak is %d.\n",max);
        else printf("Losing streak.\n");
    }
    return 0;
}
