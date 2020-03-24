import java.util.Scanner;

public class NewtonRaphson {

	static final double EPS = 0.01;

	static double f( double x ) {
        return x*x*x - 2*x - 5;
    }

	static double derivFunction( double x ) {
		return 3*x*x - 2;
	}

	static void newtonRaphson( double x ) {
		int i = 1;
		double h = f( x ) / derivFunction( x );

		while( Math.abs(h) >= EPS ) {
			h = f(x)/derivFunction(x);
			x -= h;
			System.out.println("\tITERATION " + i + " Xo = " + String.format("%.3f", x ));
			i++;
		} 

		System.out.println("\nTHE VALUE OF THE ROOT IS " + Math.round( (x*100.0)/100.0));
	}

	public static void main( String[] args ) {
		
		Scanner scan = new Scanner(System.in);

		System.out.println(" ( x*x*x - 2*x - 5 ) IS EQAUTION.");
		System.out.print("ENTER THE Xo VALUE : ");
		double Xo = scan.nextDouble();
		NewtonRaphson.newtonRaphson(Xo);
	}
}