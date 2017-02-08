/*****************************************
 ***Problema: ClockHands
 ***ID: 579
 ***Juez: UVA
 ***Tipo: Ad hoc Time
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

//http://en.wikipedia.org/wiki/Clock_angle_problem
#include <stdio.h>

double abs( double x ){
    if( x < 0 )x = -x;
    return x;
}

//angulo de la hora partiendo desde 12
double angleHour( int h , int m ){
    return ( h * 60 + m )/2.0;
}

//angulo de la mano de minuto partiendo desde 12
double angleMinute( int m ){
    return m * 6;
}

//angulo entre dos manos desde 12 en sentido horario
double angleHands( int h , int m ){
    return abs( ( 60.0 * h - 11.0 * m )/2.0 );
}

double min( double a , double b){
    if( a < b )return a;
    return b;
}

int main(){
    int h ,m;
    double ang;
    while( scanf("%d:%d" , &h , &m ) , h ){
        ang = angleHands( h , m );
        printf( "%.3lf\n" , min( 360 - ang , ang ) );
    }

    return 0;
}
