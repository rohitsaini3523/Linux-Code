import java.util.Scanner;

class rc {
    public String name;
    public int rollno;
    public double marks[] = new double[5];

    public rc() {
        name = "-";
        rollno = 0;
        for (int i = 0; i < 5; i++) {
            marks[i] = 0;
        }
    }
    
    double avg() {
        int average = 0;
        for (int i = 0; i < 5; i++) {
            average += marks[i];
        }
        average = average / 5;
        return average;
    }

    String grade(double k) {
        if (k > 90) {
            return "A";
        } else if (k <= 90 && k > 80) {
            return "B";
        } else {
            return "C";
        }
    }

    void reportcard() {
        System.out.print("\nName: " + name);
        System.out.print("\nRoll No: " + rollno);
        System.out.print("\nMarks: ");
        for (int i = 0; i < 5; i++) {
            System.out.print(marks[i] + ", ");
        }
        System.out.print("\nAverage: " + avg());
        System.out.print("\nGrade: " + grade(avg()));
    }
}

public class report {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Number of Students: ");
        int k = sc.nextInt();
        for(int i =0;i<k; i++){
        rc a = new rc();
        System.out.print("Enter Name: ");
        a.name = sc.next();
        System.out.print("Enter Rollno: ");
        a.rollno = sc.nextInt();
        for (int i1 = 0; i1 < 5; i1++) {
            System.out.print("Enter Marks of subject: ");
            a.marks[i1] = sc.nextInt();
        }
        a.reportcard();
    }
        sc.close();
    }
}
