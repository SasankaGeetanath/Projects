package reportpack;

import studentpack.*;
import sportspack.*; 
import java.util.Scanner; 

class Sport implements SportInterface {
    int N;
    String[] S;
    public void howStudentPlays() {
        Scanner scan = new Scanner(System.in);
        System.out.print("\nENTER THE TOTAL NUMBER OF SPORTS PLAYED : ");
        N = scan.nextInt();
        System.out.print("\nENTER ALL THE SPORTS WHICH YOU PLAY : ");
        S = new String[N];
        for( int i = 0; i < N; ++i )
            S[i] = scan.next();
        scan.close();
    }
}

public class Report {
    public static void main( String[] args ) {
        Scanner scan = new Scanner(System.in);
        System.out.print("\nENTER THE NAME AND ROLL NUMBER OF THE STUDENT : ");
        Student stu = new Student( scan.nextLine() , scan.next() );

        Sport games = new Sport();
        games.howStudentPlays();
        System.out.println("\n\tHERE IS THE REPORT OF " + stu.name);
        stu.studentInfo();
        System.out.println("\nI PLAY " + games.N + " SPORTS AND THEY ARE" );
        for( int i = 0; i < games.N; ++i )
            System.out.print("\t" + games.S[i]);
    }
}
