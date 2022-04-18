public class constbox {
    public static void main(String[]args)
    {
        box b1 = new box();
        box b2 = new box(10,5,6);
        box b3 = new box(8);
        System.out.println("Volume of b1 is :"+b1.volume());
        System.out.println("Volume of b2 is :"+b2.volume());
        System.out.println("Volume of b3 is :"+b3.volume());
    }
}

class box
{
    double length;
    double width;
    double height;
    box()
    {
        length = -1;
        width = -1;
        height = -1;
    }

    box(double l,double w, double h)
    {
        length = l;
        width = w;
        height = h;
    }

    box(double a)
    {
        length = width = height = a;
    }
    double volume()
    {
        return length * width * height;
    }
}