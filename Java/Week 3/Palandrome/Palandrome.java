import java.util.Scanner;

public class Palandrome{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.print("ENTER THE STRING NAME : ");
		String name = scan.nextLine();
		int N = name.length();
		String temp = "";

		for( int i = N - 1; i >= 0; --i )
			temp = temp + name.charAt(i);
			
		if( name.equals(temp) )
			System.out.print( name + " IS PALANDROME.");
		else
			System.out.print( name + " IS NOT PALANDROME.");
	}
}