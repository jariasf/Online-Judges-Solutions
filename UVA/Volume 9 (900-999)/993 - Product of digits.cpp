/*****************************************
 ***Problema: Product of digits
 ***ID: 993
 ***Juez: UVA
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<string>
#include<sstream>
#include<time.h>

using namespace std;

int minProd(int n){
    vector<int> factores;
    int i;
    for(i=9;i>=2;i--){
        while(n%i==0){
            factores.push_back(i);
            n=n/i;
        }
        if(n==1){break;}
    }
    //si n>9 ejemplo 22, factores tendria solo 2 y n seria 11 saldira de ciclo
    if(n>9){
        printf("-1\n");
        return 0;
    }
    //recorremos arreglo e imprimos pero alreves xq pide el minimo
    for(int i=factores.size()-1;i>=0;i--){
        printf("%d",factores.at(i));
    }
    printf("\n");
    return 0;

}

int main(){
    int casos,n,i;
    while(scanf("%d",&casos)!=EOF){
        for(i=0;i<casos;i++){
 	    	scanf("%d",&n);
    	    if(n<0 || n>1000000000){break;}
       	    if(n==0){printf("0\n"); continue;}
            if(n==1){printf("1\n"); continue;}
            minProd(n);
       }
    }
    return 0;
}
