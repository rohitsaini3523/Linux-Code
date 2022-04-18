import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class lab5_2 {

    public static void main(String[] args) throws IOException {
        InputStreamReader i = new InputStreamReader(System.in);
        BufferedReader b1 = new BufferedReader(i);
        BufferedWriter b2 = new BufferedWriter(new FileWriter("destination.txt"));
        String name;
        String rollno;
        String Grade;
        String s;
        int temp;
        System.out.print("Enter Number of Student: ");
        Scanner sc = new Scanner(System.in);
        temp = sc.nextInt();
        while(temp >0){
        System.out.print("Name: ");
        name = b1.readLine();
        System.out.print("Rollno: ");
        rollno = b1.readLine();
        System.out.print("Grade: ");
        Grade = b1.readLine();
        s = name + " " + rollno + " " + Grade + "\n";
        System.out.print(s);
        b2.write(s);
        temp -= 1;}
        if (b2 != null)
            b2.close();
        sc.close();
    }
}