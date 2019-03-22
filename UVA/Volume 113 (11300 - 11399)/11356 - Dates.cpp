/*****************************************
 ***Problema: Dates
 ***ID: 11356
 ***Juez: UVA
 ***Tipo: Calendar
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

import java.util.Calendar;
import java.util.Scanner;

public class uva11356 {

	public static void main(String[] args) {
		Scanner sc = new Scanner( System.in);
		int t = sc.nextInt() , y , m , d , days;
		String line, months[ ] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" ,"December"};
		String a[];
		for( int i = 1 ; i <= t ; ++i ){
			line = sc.next();
			days = sc.nextInt();
			a = line.split("-");
			y = Integer.parseInt( a[ 0 ] );
			d = Integer.parseInt( a[ 2 ] );
			m = 0;
			for( int q = 0 ; q < months.length ; ++q ){
				if( months[ q ].equals( a[ 1 ] ) ){
					m = q;
					break;
				}
			}
			Calendar c = Calendar.getInstance();

			c.set( y , m , d );
			c.add( Calendar.DATE , days );
			System.out.printf("Case %d: %04d-%s-%02d\n" , i , c.get( Calendar.YEAR ) , months[ c.get( Calendar.MONTH ) ] , c.get( Calendar.DATE ) );
		}
	}

}
