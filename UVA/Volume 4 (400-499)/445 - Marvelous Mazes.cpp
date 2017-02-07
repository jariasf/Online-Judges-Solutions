/*****************************************
 ***Problema: Marvelous Mazes
 ***ID: 445
 ***Juez: UVA
 ***Tipo: Ad hoc, Simulation
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    char ch;
    int d=0;
    while((ch = getc(stdin))!= EOF){

      if(ch=='!'){putchar('\n');d=0;}
      else if(isdigit(ch)){
         d+=(ch-'0');
      }
      else if(ch=='\n')putchar('\n');
      else{
         while(d--){
           if(ch=='b')putchar(' ');
           else putchar(ch);
         }
         d=0;
      }
    }
    return 0;
}
