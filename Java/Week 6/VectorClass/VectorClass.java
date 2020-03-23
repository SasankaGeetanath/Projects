import java.util.*;


public class VectorClass<T> extends Vector<T> {

	@Override
	public synchronized String toString() {
		StringBuffer str = new StringBuffer();
		for( T i : this ){
			str.append("->").append(i).append("\t");	
		}
		return str.toString();	
	}

    public static void main( String[] args ) {
        Scanner scan = new Scanner(System.in);

	VectorClass<Integer> vec = new VectorClass<>();        
        while( true ) {
        	System.out.println("\n\n\tVECTOR LIST\t\n\n");
        	System.out.println("1.ENTER TO ADD AN ELEMENT IN TO THE VECTOR.");
        	System.out.println("2.ENTER TO REMOVE AN ELEMENT FROM THE VECTOR.");
        	System.out.println("3.ENTER TO CLEAR THE VECTOR.");
        	System.out.println("4.ENTER TO DISPLAY ALL THE ELEMENTS IN THE VECTOR.");
        	System.out.println("5.ENTER TO CHECK WHETHER THE VECTOR IS EMPTY OT NOT.");
        	System.out.println("6.ENTER TO CHECK WHETHER THE VECTOR CONTAINS A SPECFIC ELEMENT OR NOT.");
        	System.out.println("7.ENTER TO CHECK THE CAPACITY OF THE VECTOR.");
        	System.out.println("8.ENTER TO SORT ALL THE ELEMENTS IN THE VECTOR.");
        	System.out.println("9.ENTER TO CHECK THE SIZE OF THE VECTOR.");
        	System.out.println("10.EXIT.");
        	System.out.print("\n\nENTER YOUR CHOICE : ");

        	switch( scan.nextInt() ) {

        		case 1 : 	System.out.print("ENTER THE ELEMENT TO BBE ADDED : ");
							vec.add( scan.nextInt() );
				break;

				case 2 :    System.out.print("ENTER THE ELEMENT TO BE REMOVED : ");
							if( vec.removeElement( scan.nextInt() ) )
								System.out.println("THE ELEMENT IS DELETED.");
							else 
								System.out.println("THE ELEMENT IS NOT PRESENT IN THE LIST.");
				break;

				case 3 :    if( vec.isEmpty() )
								System.out.println("THE VECTOR IS EMPTY.");
							else{
								vec.clear();
								System.out.println("THE VECTOR IS EMPTY.");
							}
				break;

				case 4 :    if( vec.isEmpty() )
								System.out.println("THE VECTOR IS EMPTY.");
							else
								System.out.print( vec.toString() );
				break;

				case 5 :    if( vec.isEmpty() )
								System.out.println("THE VECTOR IS EMPTY.");
							else 
								System.out.println("THE VECTOR IS NOT EMPTY.");
				break;

				case 6 :    System.out.print("ENTER THE ELEMENT TO BE SEARCHED FOR : ");
							if( vec.contains(scan.nextInt()) )
								System.out.println("THE ELEMENT IS PRESENT IN THE VECTOR.");
							else 
								System.out.println("THE ELEMENT IS NOT PRESENT IN THE VECTOR.");
				break;   

				case 7 :    if( vec.isEmpty() )
								System.out.println("THE VECTOR IS EMPTY.");
							else{
								System.out.println("THE CAPACITY OF THE VECTOR IS " + "\t");
								System.out.println("\n");
								vec.capacity();
							}
				break;

				case 8 :    if( vec.isEmpty() )
								System.out.println("THE VECTOR IS EMPTY.");
							else{
								Collections.sort(vec);
								System.out.print("THE SORTED VECTOR IS " + "\n" + vec.toString() );
							}
				break;    

				case 9 :    if( vec.isEmpty() )
								System.out.println("THE VECTOR IS EMPTY.");
							else
								System.out.println("THE SIZE OF THE VECTOR IS " + vec.size() );
				break;    

				case 10 :   System.exit(1);

				default :   System.out.println("ENTER A VALID CHOICE.");
        	}
        }
    }
}