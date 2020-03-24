import java.util.Scanner;

public class RegulaFalisi {

    static double DIFF = 0.01;

    static double f( double x ) {
        return x*x*x - 2*x - 5 ;
    }

    static void regualaFalsi( double a, double b ) {
        if( ( f(a) * f(b) ) >= 0 ) 
            System.out.print("YOU HAVE NOT ASSUMED RIGHT A AND B.");

            double c = a, g = b, h = a;
        int i = 1;
      
        while( Math.abs(h - g) >= DIFF ) {
                g = c;
                c = ( a*f(b) - b*f(a) ) / ( f(b) - f(a) );
                h = c;
                if( f(c) * f(a) == 0 )
                    break;

                else if( f(c) * f(a) < 0 ){
                    b = c;
                    System.out.print("\n\tITERATION " + i + " f(a) * f(b) > 0 ROOT LIES B/W " + a + " AND " +  b );
                }
                else {
                    a = c;
                    System.out.print("\n\tITERATION " + i + " f(a) * f(b) > 0 ROOT LIES B/W " + a + " AND " +  b );
                }
                i++;
            }

        System.out.println("\n\nTHE VALUE OF ROOT IS " + (int)c );
    }

    public static void main( String[] args ) {
        Scanner scan = new Scanner(System.in);

        System.out.println(" (x*x*x - 2*x - 5 ) IS EQAUTION.");
        System.out.print("ENTER THE VALUE OF A : " );
        double a = scan.nextDouble();
        System.out.print("ENTER THE VALUE OF B : " );
        double b = scan.nextDouble();

        RegulaFalisi.regualaFalsi(a,b);
    }
}