import java.util.Scanner;

public class lab7_p2 {
    public static void main(String[] args) {
        // int g;
        int q, w;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Value 1: ");
        q = sc.nextInt();
        System.out.print("Enter Value 2: ");
        w = sc.nextInt();
        
        calculator t1 = new calculator(q, w, 1);
        calculator t2 = new calculator(q, w, 2);
        calculator t3 = new calculator(q, w, 3);
        calculator t4 = new calculator(q, w, 4);

        t1.start();
        try {
            t1.join();
        } catch (Exception e) {
            System.out.println("Breaking add");
        }
        t2.start();
        try {
            t2.join();
        } catch (Exception e) {
            System.out.println("Breaking sub");
        }
        t3.start();
        try {
            t3.join();
        } catch (Exception e) {
            System.out.println("Breaking mul");
        }
        t4.start();
        sc.close();
    }
}

class calculator extends Thread {
    int k;
    int a;
    int b;
    int ans;

    calculator(int q, int w, int j) {
        this.ans = 0;
        this.a = q;
        this.b = w;
        this.k = j;
    }

    public void run() {

        try {
            switch (k) {
                case 1: {
                    ans = a + b;
                    System.out.println("Add Answer : " + ans);
                    break;
                }
                case 2: {
                    ans = a - b;
                    System.out.println("Sub Answer : " + ans);
                    break;
                }
                case 3: {
                    ans = a * b;
                    System.out.println("Mul Answer : " + ans);
                    break;
                }
                case 4: {
                    try {
                        ans = a / b;
                        System.out.println("Div Answer : " + ans);
                    } catch (ArithmeticException e) {
                        System.out.println("Division by Zero");
                    }
                    break;
                }
            }
        } catch (Exception e) {
            System.out.println("Exception Occurred!");
        }
    }
}