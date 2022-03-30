import java.util.Scanner;

interface motorbike 
{
    void totaldistance();
}
 
interface cycle {
    void speed();
}
class FourWheeler implements motorbike,cycle
{
     double speed, distance;
    public void totaldistance()
    {
        distance = getdistance();
        System.out.println("Distance: "+distance);
    }
    double getdistance()
    {
        System.out.println("Enter Distance: ");
        Scanner sc = new Scanner(System.in);
        double d = sc.nextDouble();
        return d;
    }

    double givedis()
    {
        return distance;
    }

    double givespe()
    {
        return speed;
    }
    double getspeed()
    {
        System.out.println("Enter Speed: ");
        Scanner sc = new Scanner(System.in);
        double s = sc.nextDouble();
        return s;
    }
    public void speed()
    {
        speed = getspeed();
        System.out.println("Speed: " + speed);
    }

    public void calaculate(double d1,double d2,double s1,double s2)
    {
        double d3 = d1 + d2;
        System.out.println("Total Distance is : " + (d3));
        double t = (d1 / s1) + (d2 / s2);
        double s3 = d3 / t;
        System.out.println("Average Speed is : " + (s3));
    }
}
class TwoWheeler implements motorbike, cycle
{
    double speed, distance;
    public void totaldistance()
    {
        distance = getdistance();
        System.out.println("Distance: "+distance);
    }

    double getdistance()
    {
        System.out.println("Enter Distance: ");
        Scanner sc = new Scanner(System.in);
        double d = sc.nextDouble();
        return d;
    }

    double givedis()
    {
        return distance;
    }

    double givespe()
    {
        return speed;
    }
    double getspeed()
    {
        System.out.println("Enter Speed: ");
        Scanner sc = new Scanner(System.in);
        double s = sc.nextDouble();
        return s;
    }
    public void speed()
    {
        speed = getspeed();
        System.out.println("Speed: " + speed);
    }

    public void calaculate(double d1,double d2,double s1,double s2)
    {
        double d3 = d1 + d2;
        System.out.println("Total Distance is : " + (d3));
        double t = (d1 / s1) + (d2 / s2);
        double s3 = d3 / t;
        System.out.println("Average Speed is : " + (s3));
    }
}

public class vechile {
    
    public static void main(String[]args)
    {
        int ch = 0;
        Scanner sc = new Scanner(System.in);
        do
        {
            System.out.println("1.Two wheeler \n2.Four Wheeler\nEnter Choice: ");
            ch = sc.nextInt();
            switch(ch){
                case 1: {
                    TwoWheeler v1 = new TwoWheeler();
                    System.out.println("Enter Data for Bike: ");
                    v1.totaldistance();
                    v1.speed();
                    System.out.println("Enter Data for cycle: ");
                    TwoWheeler v2 = new TwoWheeler();
                    v2.totaldistance();
                    v2.speed();
                    TwoWheeler v3 = new TwoWheeler();
                    v3.calaculate(v1.givedis(), v2.givedis(), v1.givespe(), v2.givespe());
                    break;
                }
                case 2:
                    FourWheeler f1 = new FourWheeler();
                    System.out.println("Enter Data for Car1: ");
                    f1.totaldistance();
                    f1.speed();
                    System.out.println("Enter Data for Car2: ");
                    FourWheeler f2 = new FourWheeler();
                    f2.totaldistance();
                    f2.speed();
                    FourWheeler f3 = new FourWheeler();
                    f3.calaculate(f1.givedis(), f2.givedis(), f1.givespe(), f2.givespe());
                    break;
            }
        } while (ch != 3);
        sc.close();
    }
}
