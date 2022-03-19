import java.util.Scanner;

public class name {
    
    public static void main(String []agrs)
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Name: ");
        String s = sc.nextLine();
        int k = s.length();
        char a = s.charAt(0);
        if (s.charAt(0) > 96)
        {
            a -= 32;
        }
        char[] b = new char[k];
        b[0] = a;
        for (int i = 1; i < k; i+=2)
        {
            char temp =s.charAt(i);
            char temp1 = s.charAt(i+1);
            if( temp == ' ' && temp1 >96)
            {
                temp1 -= 32;
            }
            b[i] = temp;
            b[i + 1] = temp1;
        }
        System.out.print(b);
        sc.close();
    }
}
