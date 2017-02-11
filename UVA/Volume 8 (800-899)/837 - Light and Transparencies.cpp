/*****************************************
 ***Problema: Light and Transparencies
 ***ID: 837
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Segment{
    double xmin;
    double xmax;
    double r;
    Segment(double x1 , double y1 , double r1 ): xmin( x1 ),xmax( y1 ),r( r1 ){}
};

//a q segmento pertenece si son dos multiplico
double segment( vector<Segment> s , double x ){
    double value = 1.0;
    for(int i = 0 ; i < s.size() ; ++i )
        if( s[ i ].xmin <= x && x < s[ i ].xmax ) value *= s[ i ].r;

    return value;
}

int main(){
    int casos , n;
    double x1 , y1 , x2 , y2 , r;
    scanf( "%d" , &casos );
    for( int q = 0 ; q < casos ; ++q ){
        if( q ) putchar('\n');
        scanf( "%d" , &n );
        vector<Segment> p;
        vector<double> v;
        while( n-- ){
            scanf( "%lf %lf %lf %lf %lf" , &x1 , &y1 , &x2 , &y2 , &r );
            if( x2 < x1 )swap( x1 , x2 );
            Segment p1( x1 , x2 , r );
            p.push_back( p1 );
            v.push_back( x1 );
            v.push_back( x2 );
        }
        //obtengo puntos ordenados para recorrerlos y ver si
        //pertenecen a segmento determinado
        sort( v.begin() , v.end() );
        printf( "%d\n" , v.size() + 1 );
        printf("-inf %.3lf 1.000\n" , v[ 0 ] );
        for(int i = 0 ; i < v.size() - 1 ; ++i ){
           printf( "%.3lf %.3lf %.3lf\n" , v[ i ] , v[ i + 1 ] , segment( p , v[ i ] ) );
        }
        printf( "%.3lf +inf 1.000\n" , v[ v.size() - 1 ] );

    }

    return 0;
}
