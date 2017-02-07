/*****************************************
 ***Problema: Kindergarten Counting Game
 ***ID: 494
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/


#include<string>
#include<iostream>
using namespace std;
int main(){
    string linea,str;
    int i,cont,l;
    while(getline(cin,linea)){
        cont=0;
        str="";
        l=linea.length();
        for(i=0;i<l;i++){
            if(isalpha(linea[i])){
               str=str+linea[i];
            }
            else{
               if(str.length()>0){cont++;}
               str="";
            }
        }
        printf("%d\n",cont);
    }
    return 0;
}
