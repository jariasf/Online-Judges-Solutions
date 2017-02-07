/*****************************************
 ***Problema: Overlapping Rectangles
 ***ID: 460
 ***Juez: UVA
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<stdio.h>

int max(int a,int b){return (a>b)?a:b;}
int min(int a,int b){return (a<b)?a:b;}

int main(){

   int test,n,xll1,xll2,yll1,yll2,xur1,xur2,yur1,yur2,it;
   while(scanf("%d",&test)!=EOF){
       for(it=0;it<test;it++){
             scanf("%d %d %d %d",&xll1,&yll1,&xur1,&yur1);
             scanf("%d %d %d %d",&xll2,&yll2,&xur2,&yur2);
             xll1=max(xll1,xll2);
             yll1=max(yll1,yll2);
             xur1=min(xur1,xur2);
             yur1=min(yur1,yur2);
             if((xll1>=xur1) || (yll1>=yur1)){
                printf("No Overlap\n");
             }
             else{
                printf("%d %d %d %d\n",xll1,yll1,xur1,yur1);
             }
             if(it<test-1)printf("\n");
       }
   }
   return 0;
}
