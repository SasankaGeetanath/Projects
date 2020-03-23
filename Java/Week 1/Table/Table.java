import java.util.Scanner;
class Table{
	public static void main( String[] args ){
		int N, M;
		Scanner s = new Scanner(System.in);
		System.out.print("ENTER TO FIND THE TABLE :");
		N = s.nextInt();
		System.out.print("ENTER THE MAXIMUM LIMIT OF THE TABLE :");
		M = s.nextInt();
		for( int i = 1; i <= M; ++i ){
			System.out.println( N + " x " + i + " = " + N * i );
		}
		s.close();
	}
}