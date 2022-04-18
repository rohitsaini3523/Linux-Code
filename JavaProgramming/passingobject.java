public class passingobject
{
    public static void main(String[]args)
    {
        t t1 = new t();
        t t2 = new t(8, 9);
        t t3 = new t(8, 9);
        t t4 = new t(1, 1);
        System.out.println("T1 == T2 " + t1.test(t2));
        System.out.println("T2 == T3 " + t2.test(t3));
        System.out.println("T3 == T4 " + t3.test(t4));
        System.out.println("T1 == T4 " + t1.test(t4));

    }
}

class t
{
    int a;
    int b;

    t()
    {
        a = 1;
        b = 1;
    }
    
    t(int x, int y)
    {
        a = x;
        b = y;
    }
    boolean test(t t1)
    {
        if((t1.a == a) && (t1.b == b))
            return true;
        return false;
    }
}