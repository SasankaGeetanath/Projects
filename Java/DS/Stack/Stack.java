import java.util.Scanner;

public class Stack {
    public static void main( String[] args ) {
        Scanner scan = new Scanner(System.in);

        System.out.print("ENTER THE SIZE OF THE ARRAY : ");
        int N = scan.nextInt();
        int[] stack = new int[N];

        Operations O = new Operations(N);

        while( true ) {
            System.out.print("\n\n\tSTACK\t\n\n");
            System.out.println("1.ENTER TO PUSH INTO THE STACK.");
            System.out.println("2.ENTER TO POP FROM THE STACK.");
            System.out.println("3.ENTER TO DISPLAY ALL THE ELEMENTS IN THE STACK.");
            System.out.println("4.ENTER TO CHECK WHETHER THE STACK IS EMPTY OR NOT.");
            System.out.println("5.ENTER TO CHECK WHETHER THE STACK IS FULL OR NOT.");
            System.out.println("6.ENTER TO CHECK THE PRESENT SIZE OF THE STACK.");
            System.out.println("7.ENTER TO CHECK THE ELEMENT IS PRESENT IN THE STACK OR NOT.");
            System.out.println("8.EXIT.");
            System.out.print("\n\nENTER YOUR CHOICE : ");
            
            switch( scan.nextInt() ) {

                case 1 :    if( O.isFull() ) 
                               System.out.print("STACK OVEFLOW!");
                            else {
                                System.out.print("ENTER THE VALUE TO BE PUSHED : ");
                                O.push( scan.nextInt() );
                            } 
                break;

                case 2 :    if( O.isEmpty() )
                                System.out.print("STACK UNDERFLOW!");
                            else 
                                O.pop();
                break;

                case 3 :    if( O.isEmpty() )
                                System.out.print("STACK UNDERFLOW!");
                            else 
                                O.display();
                break;

                case 4 :    if( O.isEmpty() )
                                System.out.print("THE STACK IS EMPTY.");
                            else 
                                System.out.print("THE STACK IS NOT EMPTY.");
                break;

                case 5 :    if( O.isFull() )
                                System.out.print("THE STACK IS FULL.");
                            else 
                                System.out.print("THE STACK IS NOT FULL.");
                break;

                case 6 :    System.out.print("PRESENT SIZE OF THE STACK IS " + O.size() );

                break;

                case 7 :    if( O.isEmpty() )
                                System.out.print("THE STACK IS EMPTY.");
                            else{
                                System.out.print("ENTER THE ELEMENT TO BE SEARCH FOR : ");
                                if( O.search( scan.nextInt( ) ) )
                                    System.out.print("THE ELEMENT IS PRESENT IN THE STACK.");
                                else
                                    System.out.print("THE ELEMENT IS NOT PRESENT IN THE STACK.");
                            }
                break;
                
                case 8 :    System.exit(1);

                default :   System.out.print("ENTER A VALID CHOICE.");
            }
        }
    }
}