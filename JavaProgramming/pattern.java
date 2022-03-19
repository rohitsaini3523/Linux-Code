import java.util.Scanner;


public class pattern {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number of lines of pattern: ");
        int a = sc.nextInt();
        String s = " ";
        String P = "*";
        for (int i = 1; i <= a; i++)
        {
            for (int j = 0; j < a - i; j++) {
                System.out.print(s);
            }
            for (int k = 0; k < i; k++) {
                System.out.print(P);
            }
            for (int j = 0; j < i-1; j++) {
                System.out.print(P);
            }
            System.out.println();
        }
        sc.close();
    }

}
