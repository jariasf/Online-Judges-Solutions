/*****************************************
 ***Problema: Jill Rides Again
 ***ID: 507
 ***Juez: UVA
 ***Tipo: Maximum 1D sum
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int main(){
    int t , max, x , sum , idy ,n , l , bestlen;
    scanf("%d",&t);
    for( int q = 1 ; q <= t ; ++q ){
        sum = 0;
        max = 0;
        idy = 0; l =0;
        scanf("%d", &n);
        for(int i = 0 ; i < n - 1; i++){
           scanf("%d",&x);
           sum+=x;
           l++;
           if( sum > max || ( sum == max && bestlen < l) ) { max = sum; idy = i + 1; bestlen = l;}
           if( sum < 0) {sum = 0; l = 0; }
        }
        if( max > 0)printf("The nicest part of route %d is between stops %d and %d\n",q , idy - bestlen + 1 , idy + 1);
        else printf("Route %d has no nice parts\n",q);
    }
    return 0;
}
