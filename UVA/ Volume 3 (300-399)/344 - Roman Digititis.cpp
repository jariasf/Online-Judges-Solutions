/*****************************************
 ***Problema: Roman Digititis
 ***ID: 344
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;
int tabla[102][6];
string roman[102];
void romanos(){
    roman[0]="";
    roman[1]="i";
    roman[2]="ii";
    roman[3]="iii";
    roman[4]="iv";
    roman[5]="v";
    roman[6]="vi";
    roman[7]="vii";
    roman[8]="viii";
    roman[9]="ix";
    roman[10]="x";
    roman[20]="xx";
    roman[30]="xxx";
    roman[40]="xl";
    roman[50]="l";
    roman[60]="lx";
    roman[70]="lxx";
    roman[80]="lxxx";
    roman[90]="xc";
    roman[100]="c";
    int aux;
    for(int i=11;i<100;i++){
        if(i<20){aux=10;}
        else if(i>=20 && i<30){aux=20;}
        else if(i>=30 && i<40){aux=30;}
        else if(i>=40 && i<50){aux=40;}
        else if(i>=50 && i<60){aux=50;}
        else if(i>=60 && i<70){aux=60;}
        else if(i>=70 && i<80){aux=70;}
        else if(i>=80 && i<90){aux=80;}
        else if(i>=90 && i<100){aux=90;}
        roman[i]=roman[aux]+roman[i-aux];
    }
}

void cantidades(){
    int i,j,l,conti=0,contv=0,contx=0,contl=0,contc=0;
    for(i=1;i<=100;i++){
        l=roman[i].length();
        for(j=0;j<l;j++){
            if(roman[i][j]=='i'){conti++;}
            else if(roman[i][j]=='v'){contv++;}
            else if(roman[i][j]=='x'){contx++;}
            else if(roman[i][j]=='l'){contl++;}
            else if(roman[i][j]=='c'){contc++;}
        }
        tabla[i][0]=conti;
        tabla[i][1]=contv;
        tabla[i][2]=contx;
        tabla[i][3]=contl;
        tabla[i][4]=contc;
    }
}
int main(){
    int l,i,n;
    romanos();
    cantidades();
    while(scanf("%d",&n) && n!=0){
        printf("%d: %d i, %d v, %d x, %d l, %d c\n",n,tabla[n][0],tabla[n][1],tabla[n][2],tabla[n][3],tabla[n][4]);

    }
    return 0;
}

