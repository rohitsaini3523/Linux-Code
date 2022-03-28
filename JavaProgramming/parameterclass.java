class box {
    double height;
    double width;
    double length;
    double volume()
    {
        return (height * width * length);
    }

    void set(double w,double h,double l)
    {
        width = w;
        length = l;
        height = h;
    }
}
public class parameterclass {
    public static void main(String[] args) {
        box b1 = new box();
        box b2 = new box();
        b1.set(11, 5, 10);
        System.out.println("Volume is :" + b1.volume());
        b2.set(5, 5, 10);
        System.out.println("Volume is :" + b2.volume());    
    }
}
