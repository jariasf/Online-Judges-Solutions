/*****************************************
 ***Problema: Train Swapping
 ***ID: 299
 ***Juez: UVA
 ***Tipo: Sorting, counting inversions
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int countBSort(int a[],int l){
    int cont=0,i,j,tmp;

    for(i=0;i<l-1;i++){
		for(j=i+1;j<l;j++){
        	if(a[j]<a[i]){
            	std::swap(a[j],a[i]);
            	cont++;
        	}
      	}
    }
    return cont;
}

int main(){
    int n,cantidad,i,resp;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&cantidad);
        int array[cantidad];
        for(i=0;i<cantidad;i++){
            scanf("%d",&array[i]);
        }

        //BUBLE SORT O(n^2)
        resp=countBSort(array,cantidad);
        printf("Optimal train swapping takes %d swaps.\n",resp);
    }

    return 0;
}
