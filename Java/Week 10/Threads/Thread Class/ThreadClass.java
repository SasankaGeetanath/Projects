class GoodMorning extends Thread {
	@Override
	public void run() {
		while( true ) {
			System.out.println("GOOD MORNING");
			try { Thread.sleep(1000); } catch( Exception e ) {} 
		}
	}
}

class Hello extends Thread {
    @Override
    public void run() {
        while( true ) {
            System.out.println("HELLO");      
            try {Thread.sleep(2000); }  catch ( Exception e ) {}
        } 
    }
}

class Welcome extends Thread {
    @Override
    public void run() {
        while( true ) {
            System.out.println("WELCOME!");      
            try {Thread.sleep(3000); }  catch ( Exception e ) {}
        } 
    }
}


public class ThreadClass {
	public static void main( String[] args ) {
		Thread t1 = new GoodMorning();
		Thread t2 = new Hello();
		Thread t3 = new Welcome();

		t1.start();
		try { Thread.sleep(1000); } catch( Exception e ) {}
		t2.start();
		try {Thread.sleep(2000); }  catch ( Exception e ) {}
		t3.start();
        try {Thread.sleep(3000); }  catch ( Exception e ) {}

	}
}