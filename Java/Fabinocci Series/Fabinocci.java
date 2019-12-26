import java.util.Scanner;

public class Fabinocci{
	public static void main(String[] args){
		int N;
		Scanner scan = new Scanner(System.in);
		System.out.print("ENTER THE LIMIT OF THE FABINOCI SERIES : ");
		N = scan.nextInt();
		System.out.println("\nTHE " + N + "TH" + " FABINOCCI NUMBER IS \n" + RFab(N));
	}

	public static int RFab( int N ){
		if( N == 0 || N == 1 )
			return N;
		else
			return RFab( N - 1 ) + RFab( N - 2 );
	}

	public static int Fab( int N ){
		int a = 1, b = 1;
		System.out.print(a + " " + b );
		for( int i = 2; i < N; ++i ){
			int c = a + b;
			System.out.print(" " + c );
			a = b;
			b = c;	
		}
		return b;
	}
}	