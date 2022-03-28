import java.util.Scanner;

class s
{
    String s;

    int check(String s)
    {
        int flag = 2;
        int count = 0;
        int count1 = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s.charAt(i) >= 65 && s.charAt(i) <= 90) {
                count++;
            } else if (s.charAt(i) >= 97 && s.charAt(i) <= 122) {
                count++;
            } else if (s.charAt(i) >= 48 && s.charAt(i) <= 57) {
                count1++;
            }
        }
        if ((s.length() >= 10) && (count + count1 == s.length()) && (count1 >= 2) )
        {
            flag = 1;
            return flag;
        }
        return flag;
    }
}
public class password {
    public static void main(String[]args)
    {
        Scanner sc = new Scanner(System.in);
        s t = new s();
        System.out.print("Enter Password: ");
        t.s = sc.next();
        if (t.check(t.s) == 1)
        {
            System.out.println("Good Password");
        }
        else
        {
            System.out.println("Bad Password");
        }
        sc.close();
    }
}
