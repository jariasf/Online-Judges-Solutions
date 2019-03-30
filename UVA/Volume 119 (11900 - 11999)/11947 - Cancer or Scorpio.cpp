/*****************************************
 ***Problema: Cancer or Scorpio
 ***ID: 11947
 ***Juez: UVA
 ***Tipo: Ad hoc Time Calendar
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		int t , d , m , y;
		char s[] = new char[15 ];
		Scanner sc = new Scanner( System.in );
		t = sc.nextInt();
		String zodiac = "";
		for( int i = 1 ; i <= t ; ++i ){
			s = sc.next().toCharArray();
			m= (s[ 0 ]- '0') * 10 + ( s[ 1 ] - '0' );
			d = (s[ 2 ]- '0') * 10 + ( s[ 3 ] - '0' );
			y = (s[ 4 ]- '0') * 1000 + ( s[ 5 ] - '0' ) * 100 + ( s[ 6 ] - '0' ) * 10+ ( s[ 7 ] - '0' );
			Calendar c = Calendar.getInstance();
			//System.out.println( d +"/"+m+"/"+y);
			c.set( y , m - 1 , d );
			c.add( Calendar.DATE , 280 );
			d = c.get( Calendar.DATE );
			m = c.get( Calendar.MONTH ) + 1;
			y = c.get( Calendar.YEAR );
			//System.out.println( d +"/"+m+"/"+y);
			zodiac = "capricorn";
			if( c.compareTo( new GregorianCalendar( y , 0 , 21 ) ) >= 0  ) zodiac = "aquarius";
			if( c.compareTo( new GregorianCalendar( y , 1 , 20 ) ) >= 0  ) zodiac = "pisces";
			if( c.compareTo( new GregorianCalendar( y , 2 , 21 ) ) >= 0  ) zodiac = "aries";
			if( c.compareTo( new GregorianCalendar( y , 3 , 21 ) ) >= 0  ) zodiac = "taurus";
			if( c.compareTo( new GregorianCalendar( y , 4 , 22 ) ) >= 0  ) zodiac = "gemini";
			if( c.compareTo( new GregorianCalendar( y , 5 , 22 ) ) >= 0  ) zodiac = "cancer";
			if( c.compareTo( new GregorianCalendar( y , 6 , 23 ) ) >= 0  ) zodiac = "leo";
			if( c.compareTo( new GregorianCalendar( y , 7 , 22 ) ) >= 0  ) zodiac = "virgo";
			if( c.compareTo( new GregorianCalendar( y , 8 , 24 ) ) >= 0  ) zodiac = "libra";
			if( c.compareTo( new GregorianCalendar( y , 9 , 24 ) ) >= 0  ) zodiac = "scorpio";
			if( c.compareTo( new GregorianCalendar( y , 10 , 23 ) ) >= 0  ) zodiac = "sagittarius";
			if( c.compareTo( new GregorianCalendar( y , 11 , 23 ) ) >= 0  ) zodiac = "capricorn";

			System.out.printf( "%d %02d/%02d/%04d %s\n" , i , m , d , y , zodiac );

		}
	}

}

/*
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    return 0;
}*/
