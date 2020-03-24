import java.util.Scanner;
import java.math.*;

public class CircularQueueFunctions {
    protected int front, rear, N;
    protected int[] cqueue;

    public CircularQueueFunctions( int size ) {
        front = -1;
        rear = -1;
        N = size;
        cqueue = new int[N];
    }

    public boolean isEmpty() {
        return front == -1;
    }

    public boolean isFull() {
        if( ( front == rear + 1 ) || ( rear == N  && front == 0 ) )  
            return true;
        else 
            return false;
    }

    public void enQueue( int value ) {
        if( isEmpty() ) {
            front = rear = 0;
            cqueue[rear] = value;
        }

        else if( rear == N && !isEmpty() ) {
            rear = 0;
            cqueue[rear] = value;
        }

        else 
            cqueue[rear] = value;
        rear++;
    }

    public void deQueue() {
        System.out.print("THE DELETED ELEMENT IS " + cqueue[front]);
        front++;
    }

    public void display() {
        if( front < rear ) {
            for ( int i = front; i < rear; ++i ) 
                System.out.print("->" + cqueue[i] + "\t" );
        }
        
        else {
            for ( int i = front; i < N; ++i )
                System.out.print( "->" + cqueue[i] + "\t" );
            for ( int i = 0; i < rear; ++i ) 
                System.out.print( "->" + cqueue[i] + "\t" );
        }
    }
}

public class CircularQueue {
    public static void main( String[] args ) {
        Scanner scan = new Scanner(System.in);

        System.out.print("ENTER THE MAXIUM LIMIT OF THE ARRAY : ");
        int N = scan.nextInt();
        int[] cqueue = new int[N];

        CircularQueueFunctions CQ = new CircularQueueFunctions(N);
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

                case 1 :    if( CQ.isFull() )
                                System.out.print("QUEUE OVERFLOW!");

                            else {
                                System.out.print("ENTER THE ELEMENT TO BE INSERTED : ");
                                CQ.enQueue( scan.nextInt() );
                            }

                break;

                case 2 :    if( CQ.isEmpty() ) 
                                System.out.print("QUEUE UNDERFLOW!");

                            else
                                CQ.deQueue();

                break;

                case 3 :    if( CQ.isEmpty() )
                                System.out.print("QUEUE UNDERFLOW!");

                            else 
                                CQ.display();

                break;

                case 4 :    if( CQ.isEmpty() )
                                System.out.print("THE QUEUE IS EMPTY.");

                            else
                                System.out.print("THE QUEUE IS NOT EMPTY.");

                break;

                case 5 :    if( CQ.isFull() ) 
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
