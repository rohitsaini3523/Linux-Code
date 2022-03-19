import java.util.Scanner;

public class multiply {
    
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number 1: ");
        int a = sc.nextInt();
        System.out.println("Enter Number 2: ");
        int b = sc.nextInt();
        int ans = 0;
        for (int i = 1; i <= a; i++)
        {
            ans += b;
        }
        System.out.println("Ans: " + ans);
        sc.close();
    }
}
