/*****************************************
 ***Problema: Secret Research
 ***ID: 621
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int casos;
    string s;
    scanf("%d",&casos);
    while(casos--){
        cin>>s;
        if(s=="78" || s=="1" || s=="4")putchar('+');
        else if(s.substr(s.length()-2,s.length())=="35")putchar('-');
        else if(s[0]=='9' && s[s.length()-1]=='4')putchar('*');
        else if(s.substr(0,3)=="190")putchar('?');
        putchar('\n');
    }

    return 0;
}
