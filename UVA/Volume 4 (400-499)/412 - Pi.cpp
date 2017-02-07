/*****************************************
 ***Problema: Pi
 ***ID: 412
 ***Juez: UVA
 ***Tipo: Ad hoc, simulation, number theory, gcd
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int gcd(int a,int b){
   return  (b==0)? a:gcd(b,a%b);
}
int main(){
    int n,i,c,j,cont,acu;
    while(scanf("%d",&n)!=EOF){
       if(n==0)break;
       cont=0;
       acu=0;
       int casos[n];
       for(i=0;i<n;i++){
          scanf("%d",&c);
          casos[i]=c;
       }
       for(i=0;i<n;i++){
          for(j=i+1;j<n;j++){
             if(gcd(casos[i],casos[j])==1)cont++;
             acu++;
          }
       }
       if(cont==0) printf("No estimate for this data set.\n");
       else{ printf("%0.6lf\n",sqrt(6.0*acu/cont));
       }
    }

    return 0;
}
