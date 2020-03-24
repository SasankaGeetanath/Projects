import java.util.StringTokenizer;
import java.util.Scanner;

public class StringTokenizerClass {
	public static void main( String[] args ) {
		Scanner scan = new Scanner(System.in);

		int sum = 0;
		System.out.print("ENTER THE SPACED STRINGS IN A SINGLE LINE : ");
		StringTokenizer str = new StringTokenizer( scan.nextLine() );
		scan.close();
		while( str.hasMoreTokens() ) {
			int x = Integer.parseInt(str.nextToken() );
			sum += x;
			System.out.print("\t" + x );
		}
		System.out.println("\nTHE TOTAL SUM OF THE SPACED INTEGERS IS " + sum );
	}
}
