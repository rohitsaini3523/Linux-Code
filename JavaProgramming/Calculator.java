import java.util.Scanner;

public class Calculator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number 1: ");
        int a = sc.nextInt();
        System.out.println("Enter Number 2: ");
        int b = sc.nextInt();
        int choice = 1;
        while (choice != 6) {
            System.out.println("\nMENU\n1.ADD\n2.MUL\n3.SUB\n4.DIV\n5.Fact\n6.Exit\nChoice: ");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.println("Addition: " + (a + b));
                    break;

                case 2:
                    System.out.println("Multiplication: " + (a * b));
                    break;

                case 3:
                    System.out.println("Subtraciton: " + (a - b));
                    break;

                case 4:
                    System.out.println("Division: " + (a / b));
                    break;
                case 5:
                    System.out.println("Enter Number: ");
                    int num = sc.nextInt();
                    int fact =1;
                    while(num > 0)
                    {
                        fact *= num;
                        num--;
                    }
                    System.out.println("Factorial is: " + (fact));
            }
        }
        sc.close();
    }

}
