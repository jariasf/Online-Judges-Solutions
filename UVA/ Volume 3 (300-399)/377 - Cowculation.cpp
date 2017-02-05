/*****************************************
 ***Problema: Cowculation
 ***ID: 377
 ***Juez: UVA
 ***Tipo: Number Theory, Bases(base - 4)
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<sstream>
using namespace std;

string completar(string str,string num2){
    for(int i=0;i<8-num2.length();i++){
         str="0"+str;
    }
    return str+=num2;
}

string completar2(string str,string num2){
    for(int i=0;i<num2.length()-str.length();i++){
         str="0"+str;
    }
    return str;
}


string convertir(string n){
    string resp="";
    for(int i=0;i<n.length();i++){
       if(n[i]=='V')resp+="0";
       if(n[i]=='U')resp+="1";
       if(n[i]=='C')resp+="2";
       if(n[i]=='D')resp+="3";
    }
    return resp;
}

string toString(int n){
   string r;
   stringstream s;
   s<<n;
   s>>r;
   return r;
}

string simboloA(string n1,string n2){
    string resp="";
    if(n1.length()<n2.length()){n1=completar2(n1,n2);}
    if(n2.length()<n1.length()){n2=completar2(n2,n1);}
    int carry=0,c1,c2;
    for(int i=n1.length()-1;i>=0;i--){
        c1=n1[i]-'0';
        c2=n2[i]-'0';
        if(c1+c2+carry>=4){
           resp=toString(c1+c2+carry-4)+resp;
           carry=1;
        }
        else {resp=toString(c1+c2+carry)+resp;carry=0;}

    }
    if(carry>0)resp=toString(carry)+resp;
    return resp;
}

string simboloL(string n2){
    return n2+"0";
}

string simboloR(string n2){
    return "0"+n2.substr(0,n2.length()-1);
}

string simboloN(string n2){
    return n2;
}

string opcion(char s,string n1,string n2){
   string resp;
   switch(s){
         case 'A': resp=simboloA(n1,n2);
         break;
         case 'L': resp=simboloL(n2);
         break;
         case 'R': resp=simboloR(n2);
         break;
         case 'N': resp=simboloN(n2);
         break;
   }
   return resp;
}

int main(){
    int n,i,;
    string num1,num2,resp,str;
    char s1,s2,s3;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      cin>>num1>>num2>>s1>>s2>>s3>>resp;
      if(i==0)printf("COWCULATIONS OUTPUT\n");
      str="";
      num1=convertir(num1);
      num2=convertir(num2);
      resp=convertir(resp);
      num2=opcion(s1,num1,num2);
      num2=opcion(s2,num1,num2);
      num2=opcion(s3,num1,num2);
      num2=completar(str,num2);
      if(num2.compare(resp)==0)printf("YES\n");
      else printf("NO\n");
      if(i==n-1) printf("END OF OUTPUT\n");

    }


    return 0;
}
