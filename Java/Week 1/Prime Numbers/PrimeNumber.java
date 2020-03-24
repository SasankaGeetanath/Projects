import java.util.Scanner;

public class PrimeNumber{
	public static void main(String[] args) {
		int N, M, flag;
		System.out.print("ENTER THE INERVALS OF THE PRIME NUMBERS : ");
		Scanner scan = new Scanner(System.in);
		N = scan.nextInt();
		M = scan.nextInt();
		System.out.println("THE PRIME NUMBERS BETWEEN " + N + " AND " + M + " ARE :");
		while( N < M ){
			flag = 0; 
			for( int i = 2; i <= N / 2; ++i ){
				if( N % i == 0 ){
					flag = 1;
					break;
				}
			}
			if( flag == 0 )
				System.out.print(" " + N  + " ");
			++N;
		}
	}
}