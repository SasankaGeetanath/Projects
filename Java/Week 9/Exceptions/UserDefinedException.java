import java.util.Scanner;
import userexception.MyException;

public class UserDefinedException {
    public static void main ( String[] args ) {
        Scanner scan = new Scanner(System.in);
        
        System.out.print("ENTER ANY VALUE : ");
        int a = scan.nextInt();
        System.out.print("ENTER ANY VALUE : ");
        int b = scan.nextInt();
        scan.close();
        float c = 0;

        try {
            c = (float)a / (float)b;
            if( c == 0.00 ) 
                throw new MyException("NUMBER IS TOO SMALL!");
        }

        catch( MyException e ) {
            System.out.println(e.getMessage());
            System.out.println("CAUGHT YOU!");
        }

        finally {
            System.out.println(c);
        }
    }
} 