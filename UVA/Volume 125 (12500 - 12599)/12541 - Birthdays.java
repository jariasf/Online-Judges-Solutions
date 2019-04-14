/*****************************************
 ***Problema: Birthdays
 ***ID: 12451
 ***Juez: UVA
 ***Tipo: Calendar JAVA
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/
import java.util.Calendar;
import java.util.Scanner;

class Main {

	public static void main(String[] args) {
		int n , year , day , month;
		Scanner sc= new Scanner( System.in );
		n = sc.nextInt();
		String name , menor = "", mayor = "";
		Calendar min = Calendar.getInstance() , max = Calendar.getInstance();
		min.set( 8000 , 1 , 1 ); max.set( 1 , 1 , 1 );
		for( int i = 0 ; i < n ; ++i ){
			name = sc.next();
			day = sc.nextInt();
			month = sc.nextInt();
			year = sc.nextInt();
			Calendar c = Calendar.getInstance();
			c.set(year, month - 1, day );
			if( min.compareTo( c ) > 0 ){
				min = c;
				menor = name;
			}
			if( max.compareTo( c ) < 0 ){
				max = c;
				mayor = name;
			}
		}
		System.out.println( mayor + "\n" + menor );
	}

}
