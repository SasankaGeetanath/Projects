import java.util.Scanner;

class Rectangle{
	static int length, width;

	Rectangle(int Length, int Width ){
		this.length = Length;
		this.width = Width;
	}

	public int Area(){
		return this.length * this.width;
	}

	public int Perimeter(){
		return 2*(this.length + this.width);
	}
	public static void main( String[] args ){
		System.out.print("ENTER THE LENGTH AND WIDTH OF THE RECTANGLE :");
		Scanner scan = new Scanner(System.in);
		int l = scan.nextInt();
		int w = scan.nextInt();
		// Rectangle obj = new Rectangle(scan.nextInt(), scan.nextInt());
		this.length = l;
		this.width = w;

		System.out.println("THE AREA OF THE RCTANGLE IS " + this.Area() );
		System.out.println("THE PERIMETER OF THE RECTANGLE IS " + this.Perimeter() );
	}
	
}
