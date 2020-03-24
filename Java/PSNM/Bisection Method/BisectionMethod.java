// public class BisectionMethod {

//     private static final double EPSILON = 1e-8;

//     private double f( double x ) {
//         return ( x*Math.log10(x) - 1.2 );
//     }

//     public double find( double xPositive, double xNegative ) {

//         double x = 0;

//         while( Math.abs( xPositive - xNegative ) > EPSILON ) {

//             x = ( xPositive + xNegative )/2;

//             if( f(x) > 0 ) 
//                 xPositive = x;
//             else 
//                 xNegative = x;
//         }

//         return x;
//     }

//     public static void main( String[] args ) {
        
//         BisectionMethod bisectionMethod = new BisectionMethod();

//         System.out.print(bisectionMethod.find(2, 3 ) );
//     }
// }

import java.util.Scanner;

public class BisectionMethod {

    private static final double EPSILON = 1e-8;

    static double f( double x ) {
        return ( Math.exp(x) - x - 2 );
    }

    static void bisectionMethod ( double xPositive, double xNegative ) {

        if( f(xPositive) * f(xNegative) >= 0 ) 
            System.out.println("YOU HAVE NOT ASSUMED RIGHT " + xPositive + " AND " + xNegative );

        else {
            double c = xPositive, g = xNegative, h = xPositive;
            int i = 1;
            while( Math.abs(g - h) >= EPSILON ) {
                g = c;
                c = ( xPositive + xNegative )/2;
                h = c;
                if( f(c) * f(xPositive) == 0 )
                    break;

                else if( f(c) * f(xPositive) < 0 ){
                    xNegative = c;
                    System.out.print("\n\tITERATION " + i + " f(xPositive) * f(xNegative) > 0 ROOT LIES B/W " + xPositive + " AND " +  xNegative );
                }
                else {
                    xPositive = c;
                    System.out.print("\n\tITERATION " + i + " f(xPositive) * f(xNegative) > 0 ROOT LIES B/W " + xPositive + " AND " +  xNegative );
                }
                i++;
            }
            System.out.println("\n\nTHE VALUE OF THE ROOT IS " + c );
        }
    }

    public static void main( String[] args ) {
        Scanner scan = new Scanner(System.in);
        System.out.println(" ( Math.exp(x) - x - 2 ) IS EQAUTION.");
        System.out.print("ENTER THE VALIE OF xPositive : " );
        double xPositive = scan.nextDouble();
        System.out.print("ENTER THE VALUE OF xNegative : ");
        double xNegative = scan.nextDouble();
        BisectionMethod.bisectionMethod( xPositive, xNegative );
    }
}