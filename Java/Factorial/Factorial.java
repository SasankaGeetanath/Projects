import java.util.*;

class Factorial{
	public static void main(String[] args ){
		int N, fact = 1;
		System.out.print("ENTER TO FIND THE FACTORIAL :");
		Scanner obj = new Scanner(System.in);
		N = obj.nextInt();
		for( int i = N; i >= 1; --i )
			 fact = fact * i;
		System.out.println(N + "TH FACTORIAL IS " + fact );
	}
}