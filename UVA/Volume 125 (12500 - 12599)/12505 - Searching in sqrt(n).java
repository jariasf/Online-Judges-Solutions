/*****************************************
 ***Problema: Searching in sqrt(n)
 ***ID: 12505
 ***Juez: UVA
 ***Tipo: BigNum
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.MathContext;

public class Main {

	static int bin[] , len;
	static String floatToBin( BigDecimal num ){
		String[] str = num.toPlainString().split("\\.");
		num = new BigDecimal("0." + str[ 1 ] );
		String ans = "";
		bin = new int[ 125 ];
		int i;
		len = 1;
		while( len < 122 ){
			num = num.multiply( new BigDecimal("2") );
			if( num.compareTo( new BigDecimal("1.0" ) ) >= 0 ){
				bin[ len++ ] = 1;
				num = num.subtract( new BigDecimal("1.0" ) );
			}
			else{
				bin[ len++ ] = 0;
			}
		}
		for( i = 1 ; i < 122 ; ++i ){
			ans += Integer.toString( bin[ i ] );
		}
		return ans;
	}
    public static BigDecimal sqrt(BigDecimal x, MathContext mc) {
        BigDecimal g = x.divide(BigDecimal.valueOf(2), mc);
        boolean done = false;
        final int maxIterations = mc.getPrecision() + 1;
        for (int i = 0; !done && i < maxIterations; i++) {
            BigDecimal r = x.divide(g, mc);
            r = r.add(g);
            r = r.divide(BigDecimal.valueOf(2), mc);
            done = r.equals(g);
            g = r;
        }
        return g;
    }
	public static void main(String[] args) throws NumberFormatException, IOException {
		InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringBuffer sb = new StringBuffer("");
        String m = "";
        int cases = Integer.parseInt( br.readLine());
        for (int i = 0; i < cases; i++) {
            String str[] = br.readLine().split(" ");
            BigDecimal bd = new BigDecimal( Integer.parseInt( str[ 0 ] ) );
            BigDecimal temp = sqrt( bd , new MathContext( 100 ) );
            String find = floatToBin(temp);
            int index = find.indexOf( str[1] );
            sb.append( index ).append("\n");
        }
        System.out.print(sb);
	}

}
