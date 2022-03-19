import java.util.Scanner;

public class primeornot {
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number: ");
        int a = sc.nextInt();
        int flag = 1;
        for (int i = 2; i <= a/2; i++)
        {
            if (a % i == 0) {
                flag = 0;
            }
        }
        if (flag == 0)
        {
            System.out.println("Not Prime");
        }
        else
        {
            System.out.println("Prime");
        }
        sc.close();
    }
}
