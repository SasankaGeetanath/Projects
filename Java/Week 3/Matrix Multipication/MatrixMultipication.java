import java.util.Scanner;

public class MatrixMultipication {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		while( true ) {
			System.out.print("\nENTER THE MAXIMUM LIMIT OF THE VALUE 'R1' : ");
			int r1 = scan.nextInt();
			System.out.print("\nENTER THE MAXIMUM LIMIT OF THE VALUE 'C1' : ");
			int c1 = scan.nextInt();
			System.out.print("\nENTER THE MAXIMUM LIMIT OF THE VALUE 'R2' : ");
			int r2 = scan.nextInt();
			System.out.print("\nENTER THE MAXIMUM LIMIT OF THE VALUE 'C2' : ");
			int c2 = scan.nextInt();
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
						
				scan.close();

				int[][] product = new int[r1][c2];
				for( int i = 0; i < r1; ++i ){
					for( int j = 0; j < c2; ++j ){
						product[i][j] = 0;
						for( int k = 0; k < c1; ++k )
							product[i][j] += arr[i][k] * brr[k][j];
					}
				}
				
				System.out.print("\n\nTHE MULTIPILED MATRIX IS : \n");
				for( int i = 0; i < r1; ++i ){
					for( int j = 0; j < c2; ++j )
						System.out.print( " " + product[i][j] + " " );
					System.out.print("\n");
				}

				System.out.print("\n\nTHE TRANSPOSED MATRIX IS : \n");
					for ( int i = 0; i < c2; i++){ 
						for ( int j = 0; j < r1; j++) 
							System.out.print(" " + product[j][i] + " " );
						System.out.print("\n");
					}
				break;
			}
			else
				System.out.print("\n\t\tWITH THE GIVEN VALUES CANT MULTIPLY THE MATRICES.\n\n");
		}
	}

	// static int[][] transpose ( int[][] a ) {
	// 	int[][] trans = new int[a[0].length][a.length];
	// 	for( int i = 0; i < a.length; ++k ) 
	// 		for( int j = 0; j < a[0].length; ++j )
	// 			trans[j][i] = a[i][j];
	// 	return trans;
	// }

	// static void print( int a[][] ) {
	// 	for( int i = 0; i < a.length; ++i ) 
	// 		for( int j = 0; j < a[0].length; ++j )
	// 			System.out.print();
	// }
}

// import java.util.Scanner;

// public class MatrixMultipication {

// 	static int[][] transpose ( int[][] a ) {
// 		int[][] trans = new int[a[0].length][a.length];
// 		for( int i = 0; i < a.length; ++i ) 
// 			for( int j = 0; j < a[0].length; ++j )
// 				trans[j][i] = a[i][j];
// 		return trans;
// 	}

// 	static void print( int[][] a ) {
// 		for( int i = 0; i < a.length; ++i ){ 
// 			for( int j = 0; j < a[0].length; ++j )
// 				System.out.print(" " + a[i][j] + " " );
// 			System.out.print("\n");
// 		}
// 	}


// 	public static void main(String[] args) {
// 		Scanner scan = new Scanner(System.in);
// 		while( true ) {
// 			System.out.print("\nENTER THE MAXIMUM LIMIT OF THE VALUE 'R1' : ");
// 			int r1 = scan.nextInt();
// 			System.out.print("\nENTER THE MAXIMUM LIMIT OF THE VALUE 'C1' : ");
// 			int c1 = scan.nextInt();
// 			System.out.print("\nENTER THE MAXIMUM LIMIT OF THE VALUE 'R2' : ");
// 			int r2 = scan.nextInt();
// 			System.out.print("\nENTER THE MAXIMUM LIMIT OF THE VALUE 'C2' : ");
// 			int c2 = scan.nextInt();
// 			int[][] arr = new int[r1][c1];
// 			int[][] brr = new int[r2][c2]; 
// 			if( c1 == r2 ){
// 				System.out.print("\n\tENTER THE VALUES INTO THE MATRIX A : " + "\n");
// 				for( int i = 0; i < r1; ++i )
// 					for( int j = 0; j < c1; ++j )
// 						arr[i][j] = scan.nextInt();

// 				System.out.print("\n\tENTER THE VALUES INTO THE MATRIX B : " + "\n");
// 				for( int i = 0; i < r2; ++i )
// 					for( int j = 0; j < c2; ++j )
// 						brr[i][j] = scan.nextInt();
						
// 				scan.close();

// 				int[][] product = new int[r1][c2];
// 				for( int i = 0; i < r1; ++i ){
// 					for( int j = 0; j < c2; ++j ){
// 						product[i][j] = 0;
// 						for( int k = 0; k < c1; ++k )
// 							product[i][j] += arr[i][k] * brr[k][i];
// 					}
// 				}
// 				System.out.print("\n\nTHE MULTIPILED MATRIX IS : \n");
// 				print(product);

// 				System.out.print("\n\nTHE TRANSPOSED MATRIX IS : \n");
// 				print(transpose(product));

// 				break;
// 			}
// 			else
// 				System.out.print("\n\t\tWITH THE GIVEN VALUES CANT MULTIPLY THE MATRICES.\n\n");
// 		}
// 	}
// }