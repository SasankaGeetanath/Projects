abstract class Shape {
	abstract void numberOfSide();
}

class Trapezoid extends Shape {
	@Override
	void numberOfSide() {
		System.out.println("TRAPEZOID HAS GOT 4 SIDES IN IT.");
	}
}

class Triangle extends Shape {
	@Override
	void numberOfSide() {
		System.out.println("TRIANGLE HAS GOT 3 SIDES IN IT.");
	}
}

class Hexagon extends Shape {
	@Override
	void numberOfSide() {
		System.out.println("HEXAGON HAS GOT 6 SIDES IN IT.");
	}
}

public class Abstract {
	public static void main(String[] args) {
		Trapezoid tra = new Trapezoid();
		Triangle tri = new Triangle();
		Hexagon hexa = new Hexagon();
		tra.numberOfSide();
		tri.numberOfSide();
		hexa.numberOfSide();
	}
}