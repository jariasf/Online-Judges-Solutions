/*****************************************
 ***Problema: Coin Change
 ***ID: 674
 ***Juez: UVA
 ***Tipo: DP
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int tabla[7500];
int coin[6]={1,5,10,25,50};
void Coin(){
    tabla[0]=1;
    int i,j,c;
    for(i = 0; i<=4; i++) {
		c = coin[i];
		for(j = c; j<=7500; j++) {
			tabla[j] += tabla[j-c];
		}
	}
}
int main(){
    int n;
    Coin();
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",tabla[n]);
    }
    return 0;
}
