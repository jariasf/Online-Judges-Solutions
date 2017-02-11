/*****************************************
 ***Problema: Y3K Problem
 ***ID: 893
 ***Juez: UVA
 ***Tipo: Calendar java
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

import java.util.Calendar;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner( System.in );
		int n , d , m ,y;
		for(;;){
			n = sc.nextInt(); d= sc.nextInt(); m = sc.nextInt(); y =sc.nextInt();
			if( n == 0 && d == 0 && m == 0 && y == 0 )break;
			Calendar cal = Calendar.getInstance();
			cal.set( y , m - 1 , d );
			cal.add( Calendar.DATE , n );
			System.out.println( cal.get( Calendar.DATE )  + " " + 
							  ( cal.get( Calendar.MONTH ) + 1 )+ " "+ 
								cal.get( Calendar.YEAR ));
		}
	}
}
