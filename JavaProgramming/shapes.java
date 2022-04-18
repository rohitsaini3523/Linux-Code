import java.util.Scanner;
import java.lang.Math;

public class shapes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a;
        do{
        System.out.print("\nMenu\n1.Circle\n2.Square\n3.Rectangle\n4.Exit\nChoice: ");
        a = sc.nextInt();
        switch (a) {
            case 1:
                circle c = new circle();
                circle c1 = new circle(Math.abs(5));
                System.out.println("Area for C: " + c.area());
                System.out.println("Area for any radius: " + c.area(Math.abs(6)));
                System.out.println("Area for C1: " + c1.area());
                shape q = new shape(c1);
                break;
            case 2:
                square s = new square();
                square s1 = new square(Math.abs(5));
                System.out.println("Area for S: " + s.area());
                System.out.println("Area for any Side: " + s.area(Math.abs(6)));
                System.out.println("Area for S1: " + s1.area());
                shape q1 = new shape(s1);
                break;
            case 3:

                rectangle r = new rectangle();
                rectangle r1 = new rectangle(Math.abs(5), Math.abs(10));
                System.out.println("Area for R: " + r.area());
                System.out.println("Area for any Sides : " + r.area(Math.abs(6), Math.abs(7)));
                System.out.println("Area for C1: " + r1.area());
                shape q2 = new shape(r1);

        }
    } while (a != 4);
    sc.close();
    }
}

class shape
{
    shape(circle r)
    {
        System.out.println("It's a Circle");
    }
    //Object Overloading
    shape(square r)
    {
        System.out.println("It's a Square");
    }
    
    shape(rectangle r)
    {
        System.out.println("It's a Rectangle");
    }
}

class circle
{
    double r;

    circle()
    {
        r = 0.0;
    }
    //Constructor Overloading
    circle(double x)
    {
        r = x;
    }
    double area()
    {
        return (3.14 * r * r);
    }
    double area(double x)
    {
        return (3.14 * x * x);
    }
}

class square
{
    double x;

    square()
    {
        x = 0;
    }
    
    //Constructor Overloading
    square(double z)
    {
        x = z;
    }

    double area()
    {
        return x * x;
    }
    //Method Overloading
    double area(double r)
    {
        return r * r;
    }
}

class rectangle
{
    double x, y;

    rectangle()
    {
        x =y =0;
    }
    //Constructor Overloading
    rectangle(double a,double b)
    {
        x = a;
        y = b;
    }
    double area()
    {
        return x * y;
    }
    //Method Overloading
    double area(double a, double b)
    {
        return a*b;
    }
}