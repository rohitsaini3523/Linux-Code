public class figure {
    public static void main(String []args)
    {
        System.out.println("Figure: ");
        f f1 = new f(10, 10);
        rectangle r = new rectangle(15, 10);
        triangle t = new triangle(10, 9);
        f q;
        q = r;
        System.out.println("Rectangle Area: " + q.area());
        q = t;
        System.out.println("Triangle Area: " + q.area());
        q = f1;
        System.out.println("Figure Area: " + q.area());
    }
}

class f
{
    double a;
    double b;
    double area()
    {
        System.out.println("Undifined Shape: ");
        return 0;
    }

    f(double q, double w)
    {
        a = q;
        b = w;
    }
}

class rectangle extends f
{
    rectangle(double x,double y)
    {
        super(x, y);
    }
    double area()
    {
        return a*b;
    }
}
class triangle extends f
{
    triangle(double x,double y)
    {
        super(x, y);
    }
    double area()
    {
        return (a*b)/2;
    }
}