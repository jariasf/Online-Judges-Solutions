/*****************************************
 ***Problema: The House of Santa Claus
 ***ID: 291
 ***Juez: UVA
 ***Tipo: Graph Theory, traversal, DFS, Euler
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

char num[10];
char ady[7][7];

void Enlazar()  {
      ady[1][2] = 1;  ady[2][1] = 1;
      ady[2][3] = 1;  ady[3][2] = 1;
      ady[5][2] = 1;  ady[2][5] = 1;
      ady[3][5] = 1;  ady[5][3] = 1;
      ady[1][5] = 1;  ady[5][1] = 1;
      ady[1][3] = 1;  ady[3][1] = 1;
      ady[5][4] = 1;  ady[4][5] = 1;
      ady[3][4] = 1;  ady[4][3] = 1;
}

void print()  {
  int i;
  printf("1");
  for(i = 0; i<8; i ++)
    printf("%d",num[i]);
  putchar('\n');
}
void dfs(int inicial,int level){
    int j,k;
    if(level==8){
      print();
      return;
    }
    for(int i=1;i<=5;i++){
        if(ady[inicial][i] && ady[i][inicial]){
          num[level]=i;
          ady[i][inicial]=ady[inicial][i]=0;
          dfs(i,level+1);
          j=level;
          k=num[j];
          ady[k][inicial]=1;
          ady[inicial][k]=1;

        }
    }
    j=level-2;
    if(j>=0) {
      k = num[j];
      ady[k][inicial] = 1;
      ady[inicial][k] = 1;
    }


}

int main(){

    Enlazar();
    dfs(1,0);

    return 0;
}
