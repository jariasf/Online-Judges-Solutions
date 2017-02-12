/*****************************************
 ***Problema: Safe Salutations
 ***ID: 908
 ***Juez: UVA
 ***Tipo: DP, Catalan numbers
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<stdio.h>
#define MAX 10
int a[MAX+1];
int main(){
    
    a[0] = 1;
    int j;
    for(int i = 1; i <= MAX; i++){
        a[i] = 0;
        for(j = 0; j < i; j++){
            a[i] += a[j] * a[i-j-1];
        }
    }

    int n;
    bool button = false;

    while(scanf("%d",&n)!=EOF){
        if(button)
           printf("\n");
        else
            button = true;

        printf("%d\n",a[n]);
    }

    return 0;
}
