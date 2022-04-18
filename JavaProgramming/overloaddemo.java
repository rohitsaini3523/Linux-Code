public class overloaddemo {
    public static void main(String []args)
    {
        overload o = new overload();
        o.test();
        o.test(19);
        o.test(5,6);
        double result = o.test(123.4);
        System.out.println("Result: " +result);
    }
}

class overload
{
    void test()
    {
        System.out.println("No Parameters");
    }

    void test(int a)
    {
        System.out.println("A: " + a);
    }

    void test(int a, int b)
    {
        System.out.print("A: " + a);
        System.out.print("\tB: " + b);
    }

    double test(double a)
    {
        System.out.println("\nA: "+a);
        return a * a;
    }
}