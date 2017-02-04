/*****************************************
 ***Problema: Count Cantor
 ***ID: 264
 ***Juez: UVA
 ***Tipo: Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 4775

int val[MAX];
void solve(){
    for(int i=1;i<=MAX;i++){
       val[i]=i*(i+1)/2;
    }
}

int binarySearch(int a){
    int p=1,q=MAX,m;

    while(p<=q){
        m=(p+q)/2;
        if(val[m]==a) {return m;}
        if(val[m]<a){
            p=m+1;
        }
        else{
            q=m-1;
        }

    }
    return m;
}
int main(){
    solve();
    int casos,n;
    scanf("%d",&casos);
    while(casos--){
       scanf("%d",&n);
       int m=binarySearch(n);

       printf("TERM %d IS ",n);
       int aux;
       if(val[m]<n)aux=m+1;
       else aux=m;
       if(aux%2==0){
           if(n==val[m]){
              printf("%d/1",val[m]-val[m-1]);
           }
           else if(n<val[m]){
              printf("%d/%d",n-val[m-1],val[m]-n+1);
           }
           else if(n>val[m]){
              printf("%d/%d",n-val[m],val[m+1]-n+1);
           }
       }
       else{
           if(n==val[m]){
              printf("1/%d",val[m]-val[m-1]);
           }
           else if(n<val[m]){
              printf("%d/%d",val[m]-n+1,n-val[m-1]);
           }
           else if(n>val[m]){
              printf("%d/%d",val[m+1]-n+1,n-val[m]);
           }
       }
       putchar('\n');
    }

    return 0;
}
