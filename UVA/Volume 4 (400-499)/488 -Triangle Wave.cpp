/*****************************************
 ***Problema: Triangle Wave
 ***ID: 488
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int casos,w,f;
    string s;
    scanf("%d",&casos);
    cin.get();
    while(casos--){
        scanf("%d %d",&w,&f);
        while(f--){

           for(int i=1;i<=w;i++){
              for(int j=1;j<=i;j++){
                 printf("%d",i);
              }
              putchar('\n');
           }
           for(int i=w-1;i>=1;i--){
              for(int j=i;j>=1;j--){
                 printf("%d",i);
              }
              putchar('\n');
           }
           if(f)putchar('\n');
        }
        if(casos)putchar('\n');
    }

    return 0;
}
