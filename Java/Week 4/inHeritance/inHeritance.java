class Rodent {
	void display() 
		System.out.println("I AM A RODENT.!");
}

class Mouse extends Rodent {
	@Override
	void display() 
		System.out.println("I AM A MOUSE.!");
}

class Gerbil extends Rodent {
	@Override
	void display()
		System.out.println("I AM A GERBIL.!");
}

class Hamster extends Rodent {
	@Override
	void display() 
		System.out.println("I AM A HAMSTER.!");
}

public class inHeritance {
	public static void main(String[] args) {
		Rodent[] arr = new Rodent[4];
		arr[0] = new Rodent();
		arr[1] = new Mouse();
		arr[2] = new Gerbil();
		arr[3] = new Hamster();
		for( int i = 0; i < 4; ++i ) 
			arr[i].display();
	}
}