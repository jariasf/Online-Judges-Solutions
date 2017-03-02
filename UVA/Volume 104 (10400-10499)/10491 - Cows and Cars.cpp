/*****************************************
 ***Problema: Cows and Cars
 ***ID: 10491
 ***Juez: UVA
 ***Tipo: Probability
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
int main(){
    double ncows , ncars , nshow , p1 , p2;
    while( scanf("%lf %lf %lf" , &ncows , &ncars , &nshow ) != EOF ){
        p1 = ncows/( ncows + ncars ) * ncars/( ncows + ncars - nshow - 1 );
        p2 = ncars/( ncows + ncars ) * ( ncars - 1 )/( ncows + ncars - nshow - 1 );
        printf("%.5lf\n" , p1 + p2 );
    }
    return 0;
}
