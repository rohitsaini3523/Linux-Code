import java.util.Scanner;

public class palindrome {
    
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter String: ");
        String s = sc.next();
        int k = s.length();
        int flag = 2;
        for (int i = 0; i < k; i++)
        {
            if (s.charAt(i) == s.charAt(k - i - 1)) {
                flag = 1;
            } else {
                flag = 0;
            }
        }
        if (flag == 1)
        {
            System.out.println("Palindrome");
        }
        else
        {
            System.out.println("Not Palindrome");   
        }
        sc.close();
    }
}
