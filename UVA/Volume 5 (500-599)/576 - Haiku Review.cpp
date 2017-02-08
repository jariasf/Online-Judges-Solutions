/*****************************************
 ***Problema: Haiku Review
 ***ID: 576
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

bool isVowel(char a){if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u' || a=='y'){return true;}return false;}

int main(){
    char s[205],ant,ef[6]={'e','/','o','/','i','\0'};
    int l,i,cont,nexts;
    bool vowel;
    while(gets(s)){
        if(strcmp(s,ef)==0)break;
        l=strlen(s);
        cont=0;nexts=0;
        ant='z';
        for(i=0;i<l;i++){
           if(i+1==l)nexts++;
           vowel=isVowel(s[i]);
           if(s[i]=='/'){
               nexts++;
               if(nexts==1){if(cont!=5) {printf("1\n");break;}}
               if(nexts==2){if(cont!=7) {printf("2\n");break;}}
               cont=0;
               ant=s[i];
               continue;
           }
           if(!vowel){ant=s[i];continue;}
           if(vowel && isVowel(ant)){ant=s[i];}
           else if(vowel){cont++;ant=s[i];}
        }
        if(nexts==3){
          if(cont!=5){printf("3\n");}
          else printf("Y\n");
        }
    }

    return 0;
}
