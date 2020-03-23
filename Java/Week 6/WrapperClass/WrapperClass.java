import java.util.Scanner;

class WrapperClass {
    public static void main( String[] args ) {
        Scanner scan = new Scanner(System.in);
        System.out.print("ENTER THE FLOAT VALUE INTO THE OBJECT : ");
        Float F = new Float( scan.nextFloat() );
        System.out.print("ENTER THE DOUBLE VALUE INTO THE OBJECT : ");
        Double D = new Double( scan.nextDouble() );

        System.out.println("THE FLOAT VAULE AFTER SETTING PRECISION OF 3 : " + String.format("%.3f\n", F) );
        System.out.println("THE DOUBLE VAULE AFTER SETTING PRECISION OF 6 : " + String.format("%.6f\n", D) );
    }
}