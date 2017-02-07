/*****************************************
 ***Problema: Graph Connectivity
 ***ID: 459
 ***Juez: UVA
 ***Tipo: Graph theory, union-find
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include <cstring>
#include<vector>
#include<set>
using namespace std;
#define MAX_SIZE 30

///UNION-FIND
int parent[MAX_SIZE],rank[MAX_SIZE];
void Make_Set(int x){
    parent[x]=x;
    rank[x]=0;
}

int Find(int x){
    if(parent[x]!=x) parent[x]=Find(parent[x]);
    return parent[x];
}

void Union(int PX, int PY){

    if(rank[PX]>rank[PY]) parent[PY]=PX;
    else{
        parent[PX]=PY;
        if(rank[PX]==rank[PY]) rank[PY]++;
    }
}

void Merge(int x,int y){
    Union(Find(x),Find(y));
}
///END UNION FIND

int main(){
    int casos,nv,i,orig,dest,cont;
    char tmp,C,input[20],*p,f,s;
    gets(input);
    sscanf(input,"%d",&casos);
    gets(input);
    while(casos--){
         gets(input);
         f=input[0];
         nv=f-'A';

         for(i=0;i<=nv;i++){
           Make_Set(i);
         }
         while(gets(input)){
            p=strtok(input," ");
            if(p==NULL)break;
            sscanf(p, "%c%c", &f, &s);
            orig=(f-'A');
            dest=(s-'A');
            Merge(orig,dest);
         }

         int cnt = 0;

         for( i = 0 ; i <= nv ; ++i ){
            if( parent[ i ] == i ) cnt++;
         }
         printf("%d\n" , cnt );

         if(casos>0) {
	       putchar('\n');
         }

    }
    return 0;
}
