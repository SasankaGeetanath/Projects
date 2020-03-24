import java.util.Scanner;

public class ExceptionFormat {
    public static void main( String[] args ) throws NumberFormatException, ArithmeticException {
        Scanner scan = new Scanner(System.in);
    
        System.out.print("ENTER THE DIVIDENT : ");
        Double N = scan.nextDouble();
        System.out.print("ENTER THE DIVISOR : ");
        Double M = scan.nextDouble();
        scan.close();

        if (N - N.intValue() != 0.0 || M - M.intValue() != 0.0)
            throw new NumberFormatException("THE NUMBERS AREN'T INTEGERS.");
        else if ( M == 0 )
            throw new ArithmeticException("CANT DIVIDE WITH ZERO.");
        else 
            System.out.println( "THE VALUE IS " + N/M );
    }
}
