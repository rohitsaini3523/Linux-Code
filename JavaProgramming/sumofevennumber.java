import java.util.Scanner;

public class sumofevennumber {
    
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number: ");
        int a = sc.nextInt();
        int sum = 0;
        for (int i = 1; i <= a; i++)
        {
            
            sum += 2*i;
        }
        System.out.println("Sum is: "+ (sum)); 
        sc.close();
    }
}
