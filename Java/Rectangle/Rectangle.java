import java.util.Scanner;

class Rectangle{
	static int length, width;

	Rectangle(int Length, int Width ){
		length = Length;
		width = Width;
	}

	public static int Area(){
		return length * width;
	}

	public static int Perimeter(){
		return 2*(length + width);
	}
	public static void main( String[] args ){
		System.out.print("ENTER THE LENGTH AND WIDTH OF THE RECTANGLE :");
		Scanner scan = new Scanner(System.in);
		int l  = scan.nextInt();
		int w = scan.nextInt();
		// Rectangle obj = new Rectangle(scan.nextInt(), scan.nextInt());
		Rectangle.length = l;
		Rectangle.width = w;

		System.out.println("THE AREA OF THE RCTANGLE IS " + Rectangle.Area());
		System.out.println("THE PERIMETER OF THE RECTANGLE IS " + Rectangle.Perimeter());
	}
	
}
