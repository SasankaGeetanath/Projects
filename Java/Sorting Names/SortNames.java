import java.util.Scanner;

public class SortNames{
	public static void main(String[] args) {
		int N;
		String temp;
		Scanner scan = new Scanner(System.in);
		System.out.print("ENTER THE TOTAL NAMES : ");
		N = scan.nextInt();
		Scanner give = new Scanner(System.in);
		String name[] = new String[N];
		for( int i = 0; i < N; ++i ){
			System.out.print("\n");
			System.out.print("\t\tENTER ALL THE NAME : ");
			name[i] = give.nextLine();
		}
		for( int i = 0; i < N; ++i ){
			for( int j = i + 1; j < N; ++j){
				if( name[i].compareTo(name[j]) > 0 ){
					temp = name[i];
					name[i] = name[j];
					name[j] = temp;
				}				
			}
		}
		System.out.println("\n\n\tTHE SORTED LIST OF NAMES :\n");
		for( int i = 0; i < N; ++i )
			System.out.println(name[i] + "\n" );
	}
}