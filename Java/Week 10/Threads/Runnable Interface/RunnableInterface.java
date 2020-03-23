class GoodMorning implements Runnable {
    @Override
    public void run() {
        while( true ) {
            System.out.println("Good Morning!");      
            try {Thread.sleep(1000); }  catch ( Exception e ) { }
        } 
    }
}

class Hello implements Runnable {
    @Override
    public void run() {
        while( true ) {
            System.out.println("HELLO!");      
            try {Thread.sleep(2000); }  catch ( Exception e ) { }
        } 
    }
}

class Welcome implements Runnable {
    @Override
    public void run() {
        while( true ) {
            System.out.println("WELCOME!");      
            try {Thread.sleep(3000); }  catch ( Exception e ) { }
        } 
    }
}

public class RunnableInterface { 
    public static void main( String[] args ) {
        Runnable t1 = new GoodMorning();
        Runnable t2 = new Hello();
        Runnable t3 = new Welcome();

        Thread T1 = new Thread(t1);
        Thread T2 = new Thread(t2);
        Thread T3 = new Thread(t3);

        T1.start();
        try {Thread.sleep(1000); }  catch ( Exception e ) { }
        T2.start();
        try {Thread.sleep(2000); }  catch ( Exception e ) { }
        T3.start();
        try {Thread.sleep(3000); }  catch ( Exception e ) { }
    }
}

