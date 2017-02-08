/*****************************************
 ***Problema: Error Correction
 ***ID: 501
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int n,i,j,tabla[102][102],parf,imparf,sumf,sumc,imparc,parc,idxf,idxc;
    while(scanf("%d",&n) && n!=0){
        parf=0;
        imparf=0;
        parc=0;
        imparc=0;
        sumf=0;
        sumc=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&tabla[i][j]);
            }
        }

        for(i=0;i<n;i++){
            if(imparf>1 || imparc>1)break;
            for(j=0;j<n;j++){
                if(tabla[j][i]==1){sumc++;}
                if(tabla[i][j]==1){sumf++;}
            }
            if(sumc%2==0)parc++;
            else {imparc++;idxc=i;}
            sumc=0;
            if(sumf%2==0)parf++;
            else {imparf++;idxf=i;}
            sumf=0;
        }

        if(imparf>1 || imparc>1)printf("Corrupt\n");
        else if(imparf==0 && imparc==0) printf("OK\n");
        else {
            printf("Change bit (%d,%d)\n",idxf+1,idxc+1);
        }
    }

    return 0;
}
