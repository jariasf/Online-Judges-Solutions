/*****************************************
 ***Problema: Palindromes
 ***ID: 401
 ***Juez: UVA
 ***Tipo: Ad hoc, strings, palindromes
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

bool isPalindrome(char *c,int l){
    for(int i=0,j=l-1;i<=l/2 && j>=l/2;i++,j--){
        if(c[i]!=c[j])return false;
    }
    return true;
}

bool isMirror(char *c,int l){
    for(int i=0,j=l-1;i<=l/2 && j>=l/2;i++,j--){
        if(c[i]=='A' && c[j]=='A')continue;
        if(c[i]=='E' && c[j]=='3')continue;
        if(c[i]=='3' && c[j]=='E')continue;
        if(c[i]=='H' && c[j]=='H')continue;
        if(c[i]=='I' && c[j]=='I')continue;
        if(c[i]=='J' && c[j]=='L')continue;
        if(c[i]=='L' && c[j]=='J')continue;
        if(c[i]=='M' && c[j]=='M')continue;
        if(c[i]=='O' && c[j]=='O')continue;
        if(c[i]=='S' && c[j]=='2')continue;
        if(c[i]=='T' && c[j]=='T')continue;
        if(c[i]=='U' && c[j]=='U')continue;
        if(c[i]=='V' && c[j]=='V')continue;
        if(c[i]=='W' && c[j]=='W')continue;
        if(c[i]=='X' && c[j]=='X')continue;
        if(c[i]=='Y' && c[j]=='Y')continue;
        if(c[i]=='Z' && c[j]=='5')continue;
        if(c[i]=='5' && c[j]=='Z')continue;
        if(c[i]=='1' && c[j]=='1')continue;
        if(c[i]=='2' && c[j]=='S')continue;
        if(c[i]=='8' && c[j]=='8')continue;
        else return false;

    }
    return true;
}

int main(){
    char s[25];
    int l;
    bool ip,im;
    while(gets(s)){
        l=strlen(s);
        ip=isPalindrome(s,l);
        im=isMirror(s,l);
        if(!ip && !im)    printf("%s -- is not a palindrome.\n\n",s);
        else if(ip && !im)printf("%s -- is a regular palindrome.\n\n",s);
        else if(!ip && im)printf("%s -- is a mirrored string.\n\n",s);
        else if(ip && im) printf("%s -- is a mirrored palindrome.\n\n",s);
    }
    return 0;
}
