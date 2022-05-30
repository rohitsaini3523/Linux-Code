import java.util.Scanner;

public class labexam {

    public static void main(String[] args) {
        int a;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Number: ");
        a = sc.nextInt();
        System.out.print("Is it a prime product? " + check(a));
    }

    public static int verify(int[] s) {
        int count1 = 0;
        int i = 0;
        while (s[i] != 0) {
            if (isprime(s[i]) == 0) {
                count1++;
            }
            i++;
        }
        if ((count1 > 1)) {
            return 1;
        } else
            return 0;
    }

    public static int isprime(int k) {
        int falg = 0;
        for (int i = 2; i < k / 2; i++) {
            if (k % i == 0) {
                falg = 1;
            }
        }
        return falg;
    }

    public static boolean check(int a) {
        int j = a;
        int len = a / 2;
        int[] a1 = new int[len];
        int p = 0;
        for (int i = 2; i < a; i++) {
            if (a % i == 0) {
                a1[p] = i;
                p++;
                j /= i;
                System.out.print(j + " " + i + " \n");
                // s+=" ";
            }
            if (j < 1) {
                break;
            }
        }
        // if(flag == 1)
        // {
        // int i =0;
        // while(a1[i]!=0)
        // {
        // System.out.println(a1[i]);
        // i++;
        // }
        // }
        // System.out.println("hello");
        int m = verify(a1);
        // System.out.print(m);
        if (m == 1)
            return true;
        return false;
    }

}
