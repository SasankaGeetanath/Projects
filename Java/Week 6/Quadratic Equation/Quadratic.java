import java.util.Scanner;

public class Quadratic {
    public static void main( String[] args ) {
        Scanner scan = new Scanner(System.in);
        System.out.print("\nENTER THE VALUE OF a IN THE QUADRATIC EQUATION = ");
        double a = scan.nextDouble();
        System.out.print("\nENTER THE VALUE IF b IN THE QUADRATIC EQUATION = ");
        double b = scan.nextDouble();
        System.out.print("\nENTER THE VALUE OF c IN THE QUADRATIC EQUATION = ");
        double c = scan.nextDouble();

        double discriminant = ( b * b ) - (4 * a * c );

        if( discriminant >= 0 ) {
                double root1 = ( (-b + Math.sqrt(discriminant) ) / ( 2 * a ) );
                double root2 = ( (-b - Math.sqrt(discriminant) ) / ( 2 * a ) );

                System.out.println("\nBOTH THE ROOTS OF THE QUADRATIC EQUATION ARE REAL \n");
                System.out.println("\tROOT1 =  " + root1);
                System.out.println("\tROOT2 =  " + root2);
        }

        else { 
            double real = ( (-b) / ( 2 * a ) );
            double imaginary = ( (Math.sqrt( -discriminant ) ) /( 2 * a) );

            System.out.println("\nTHE ROOTS ARE REAL AND IMAGINARY = \n");
            System.out.println("\tROOT1 = " + real + " + " + imaginary + "i");
            System.out.println("\tROOT2 = " + real + " - " + imaginary + "i");
        }
    }
}

