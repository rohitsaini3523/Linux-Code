import java.util.Scanner;

public class lab7_p1 {
    public static void main(String[] args) {
        int k;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Number till you want to print: ");
        k = sc.nextInt();
        System.out.println("Even numbers till " + k);
        evenno t = new evenno(k);
        t.start();
        try
        {
            t.join();
        }
        catch(Exception e)
        {
            System.out.print("Not Able to Use Join\n");
        }
        Thread t1 = new Thread(new oddno(k));
        System.out.println("Odd numbers till k : ");
        t1.start();
    }
}

class evenno extends Thread {
    int n;

    evenno(int k) {
        this.n = k;
    }

    public void run() {
        try {
            if (n % 2 != 0)
                n = n - 1;
            for (int i = 2; i <= n; i += 2) {
                System.out.print(i + " ");
            }
            System.out.println("\n");
        } catch (Exception e) {
            System.out.print("Exception Occured!\n");
        }
    }

}

class oddno implements Runnable {
    int n;

    oddno(int k) {
        this.n = k;
    }

    public void run() {
        try {
            if (n % 2 == 0)
                n = n - 1;
            for (int i = 1; i <= n; i += 2) {
                System.out.print(i + " ");
            }
            System.out.println("\n");
        } catch (Exception e) {
            System.out.print("Exception Occured!\n");
        }
    }
}