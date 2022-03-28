import java.util.Scanner;

class st
{
    String s;

    char middle(String s,int k)
    {
        char mid = s.charAt(k);
        if (k % 2 == 0)
        {
            mid = s.charAt(k);
        }
        return mid;   
    }
}

public class middlecharater {
    public static void main(String[]args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter String: ");
        st t = new st();
        t.s = sc.next();
        System.out.print("Middle char is: ");
        int k = t.s.length();
        if (k % 2 == 0)
        {
            System.out.print(t.middle(t.s, k / 2 -1) +" " + t.middle(t.s, k / 2));
        }
        else
        {
            System.out.print(t.middle(t.s, k / 2));
        }
        sc.close();
    }
    
}
