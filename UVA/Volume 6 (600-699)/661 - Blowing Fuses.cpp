/*****************************************
 ***Problema: Blowing Fuses
 ***ID: 661
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int n,m,c,num,cont=1;
    bool flag;

    while(scanf("%d %d %d",&n,&m,&c)){
        if(!n && !m && !c)break;
        int a[n+1],maxi=0,sum=0;
        bool visitado[n+1];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i+1]);
            visitado[i+1]=false;
        }

        flag=true;
        while(m--){
           scanf("%d",&num);

           if(!visitado[num]){
              sum+=a[num];
              visitado[num]=true;
           }
           else{
              sum-=a[num];
              visitado[num]=false;
           }
           maxi=max(maxi,sum);
           if(sum>c){flag=false;}
        }
        printf("Sequence %d\n",cont++);
        if(!flag){
          printf("Fuse was blown.\n\n");
        }
        else{
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n\n", maxi);
        }

    }

    return 0;
}
