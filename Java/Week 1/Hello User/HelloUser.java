import java.util.Scanner;

public class HelloUser{
	public static void main( String[] args ){
		String name;
		Scanner scan = new Scanner(System.in);
		System.out.print("ENTER THE USER NAME : ");
		name = scan.nextLine();
		scan.close();
		System.out.println("WELCOME DEAR " + name + "!" );
	}
}