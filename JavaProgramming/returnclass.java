class box {
    double height;
    double width;
    double length;

    double volume()
    {
        return (height * width * length);
    }
}
public class returnclass {
    public static void main(String[] args) {
        box b1 = new box();
        box b2 = new box();
        b1.height = 10.0;
        b1.length = 11.0;
        b1.width = 5.0;
        System.out.println("Volume is :" + b1.volume());
        b2.height = 5.0;
        b2.length = 5.0;
        b2.width = 10.0;
        System.out.println("Volume is :" + b2.volume());
    }
}
