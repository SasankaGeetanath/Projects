import java.util.Scanner;

class Operations {
    protected int front, rear, N;
    protected int[] queue;

    Operations( int size ) {
        N = size;
        front = -1;
        rear = -1;
        queue = new int[N];
    }

    public boolean isEmpty() {
        return front == rear;
    }

    public boolean isFull() {
        if( rear == N )
            return true;
        else
            return false;
    }

    public void enQueue( int value ) {
        if( isEmpty() ) 
            front = rear = 0;
        queue[rear] = value;
        rear++;
    }

    public void deQueue() {
        System.out.print("THE DELETED ELEMENT IS " + queue[front]);
        front++;
    }

    public void display() {
        for( int i = front; i < rear; ++i ) 
            System.out.print("->" + queue[i] + "\t");
    }
}

public class Queue {
    public static void main( String[] args ) {
        Scanner scan = new Scanner(System.in);

        System.out.print("ENTER THE MAXIMUN LIMIT OF THE ARRAY : ");
        int N = scan.nextInt();
        int[] queue = new int[N];

        Operations O = new Operations(N);

        while( true ) {
            System.out.print("\n\n\tQUEUE\t\n\n");
            System.out.println("1.ENTER TO INSERT INTO THE QUEUE.");
            System.out.println("2.ENTER TO DELETE FROM THE QUEUE.");
            System.out.println("3.ENTER TO DISPLAY ALL THE ELEMENTS IN THE QUEUE.");
            System.out.println("4.ENTER TO CHECK WHETHER THE QUEUE IS EMPTY OR NOT.");
            System.out.println("5.ENTER TO CHECK WHETHER IS QUEUE IS FULL OR NOT.");
            System.out.print("6.EXIT.");
            System.out.print("\n\nENTER YOUR CHOICE : ");

            switch( scan.nextInt() ) {

                case 1 :    if( O.isFull() )
                                System.out.print("QUEUE OVERFLOW!");

                            else {
                                System.out.print("ENTER THE ELEMENT TO BE INSERTED : ");
                                O.enQueue( scan.nextInt() );
                            }

                break;

                case 2 :    if( O.isEmpty() ) 
                                System.out.print("QUEUE UNDERFLOW!");

                            else
                                O.deQueue();

                break;

                case 3 :    if( O.isEmpty() )
                                System.out.print("QUEUE UNDERFLOW!");

                            else 
                                O.display();

                break;

                case 4 :    if( O.isEmpty() )
                                System.out.print("THE QUEUE IS EMPTY.");

                            else
                                System.out.print("THE QUEUE IS NOT EMPTY.");

                break;

                case 5 :    if( O.isFull() ) 
                                System.out.print("THE QUEUE IS FULL.");

                            else 
                                System.out.print("THE QUEUE IS NOT FULL.");

                break;

                case 6 :    System.exit(1);

                default :   System.out.print("ENTER A VALID CHOICE.");
            }
        }
    }
}