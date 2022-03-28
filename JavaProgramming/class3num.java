import java.util.Scanner;

class num
{
    int a;
    int b;
    int c;

    int minimum(int a,int b,int c)
    {
        int min = 0;
        if (a < b && a < c) {
            min = a;
        } else if (b < a && b < c) {
            min = b;
        } else {
            min = c;
        }
        return min;
    }

    int average(int a,int b,int c)
    {
        return ((a + b + c) / 3);
    }
}
class class3num {
    public static void main(String[]agrs)
    {
        Scanner sc = new Scanner(System.in);
        num n = new num();
        System.out.println("Enter a: ");
        n.a  = sc.nextInt();
        System.out.println("Enter b: ");
        n.b  = sc.nextInt();
        System.out.println("Enter c: ");
        n.c  = sc.nextInt();
        System.out.println("Minimum is : "+ n.minimum(n.a,n.b,n.c));
        System.out.println("Average is: " + n.average(n.a,n.b,n.c));
        sc.close();
    }
}
