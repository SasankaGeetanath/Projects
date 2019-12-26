import java.util.Scanner;

public class MatrixMultipication{
	public static void main(String[] args) {
		int r1, r2, c1, c2;
		Scanner scan = new Scanner(System.in);
		while( true ){
			System.out.print("\nENTER THE MAXIMUM LIMIT OF THE VALUE 'A' : ");
			r1 = scan.nextInt();
			System.out.print("\nENTER THE MAXIMUM LIMIT OF THE VALUE 'B' : ");
			c1 = scan.nextInt();
			System.out.print("\nENTER THE MAXIMUM LIMIT OF THE VALUE 'C' : ");
			r2 = scan.nextInt();
			System.out.print("\nENTER THE MAXIMUM LIMIT OF THE VALUE 'D' : ");
			c2 = scan.nextInt();
			int[][] arr = new int[r1][c1];
			int[][] brr = new int[r2][c2]; 
			if( c1 == r2 ){
				System.out.print("\n\tENTER THE VALUES INTO THE MATRIX A : " + "\n");
				for( int i = 0; i < r1; ++i )
					for( int j = 0; j < c1; ++j )
						arr[i][j] = scan.nextInt();

				System.out.print("\n\tENTER THE VALUES INTO THE MATRIX B : " + "\n");
				for( int i = 0; i < r2; ++i )
					for( int j = 0; j < c2; ++j )
						brr[i][j] = scan.nextInt();

				int[][] product = new int[c2][r1];
				for( int i = 0; i < r1; ++i ){
					for( int j = 0; j < c2; ++j ){
						product[i][j] = 0;
						for( int k = 0; k < c1; ++k )
							product[i][j] += arr[i][k] * brr[k][i];
					}
				}
				System.out.print("\n\nTHE MULTIPILED MATRIX IS : \n");
				for( int i = 0; i < r1; ++i ){
					for( int j = 0; j < c2; ++j )
						System.out.print( " " + product[i][j] + " " );
					System.out.print("\n");
				}
				System.out.print("\n\nTHE TRANSPOSED MATRIX IS : \n");
				 // int[][] crr = new int [c2][r1];
					//  for ( int i = 0; i < c2; i++) 
				 //         for ( int j = 0; j < r1; j++) 
				 //           crr[i][j] = product[j][i]; 
				for( int i = 0; i < r1; ++i ){
					for( int j = 0; j < c2; ++j )
						System.out.print( " " + product[j][i] + " " );
					System.out.print("\n");
				}

				break;
			}
			else
				System.out.print("\n\t\tWITH THE GIVEN VALUE CANT MULTIPLY THE MATRICES.\n\n");
		}
	}
}