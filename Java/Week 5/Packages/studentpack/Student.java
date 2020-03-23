package studentpack;

public class Student {
    public String name, roll; 

    public Student( String NAME, String ROLL) {
        this.name = NAME;
        this.roll = ROLL;
    }
    
    public void studentInfo() {
        System.out.print("\nHII...MY NAME IS " + this.name + " AND MY ROLL NUMBER IS " + this.roll );
    }
}
 
