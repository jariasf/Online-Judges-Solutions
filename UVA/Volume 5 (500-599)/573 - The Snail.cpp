/*****************************************
 ***Problema: The Snail
 ***ID: 573
 ***Juez: UVA
 ***Tipo: Ad hoc, simulation, math
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    double H,U,D,F;
    int day;
    double loss,d_cover;
    while(scanf("%lf",&H) && H)
    {
	  scanf("%lf%lf%lf", &U, &D,&F);
	  loss = (U*F)/100;
	  day = 0;
	  d_cover = 0;

	  while(1)
	  {
	      day++;
	      d_cover += U; if(d_cover >H) break;
	      d_cover -= D; if(d_cover<0) break;
	      U -= loss; if(U<0) U = 0;

	  }
	  if(d_cover>H)
	    printf("success on day %d\n",day);
	  else
	    printf("failure on day %d\n",day);

    }

    return 0;
}
