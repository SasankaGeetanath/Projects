import java.util.Scanner;

public class Fibanocci{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		System.out.print("ENTER THE LIMIT OF THE FABINOCI SERIES : ");
		int N = scan.nextInt();
		System.out.print("\n\n\tFIBANOCCI SERIES\t\n\n");
		System.out.print("\n1.ENTER TO FIND IN THE NON-RECUSRIVE METHOD.");
		System.out.print("\n2.ENTER TO FIND IN THE RECUSRIVE METHOD.");
		System.out.print("\n\nENTER YOUR CHOICE : ");
		switch (scan.nextInt()) {
			case 1:     System.out.println("\nTHE " + N + "TH" + " FABINOCCI NUMBER IS \n" + Fab(N));
						break;

			case 2:     System.out.println("\nTHE " + N + "TH" + " FABINOCCI NUMBER IS \n" + RFab(N));
						break;
		}
		scan.close();
	}

	public static int RFab( int N ){
		if( N == 1 || N == 2 )
			return 1;
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