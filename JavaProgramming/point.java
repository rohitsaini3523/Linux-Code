import java.util.Scanner;
import java.lang.Math;

public class point {
    public static void main(String[] args) {
        int choice = 0;
        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("Menu\n1.Point\n2.Line\n3.Rectangle\n4.Exit\nChoice: ");
            choice = sc.nextInt();
            switch (choice) {
                case 1: {
                    System.out.println("Simple Point: ");
                    p P = new p();
                    P.accept();
                    P.display();
                    break;
                }
                case 2: {
                    line l1 = new line();
                    System.out.println("For Staright Line: ");
                    System.out.println("Point 1: ");
                    l1.accept();
                    System.out.println("Point 2: ");
                    line l2 = new line();
                    l2.accept();
                    line l = new line();
                    System.out.println("Distance between p1 and p2: " + l.calaculate(l1, l2));
                    break;
                }
                case 3: {
                    rect p1 = new rect();
                    System.out.println("For Rectangle: ");
                    System.out.println("Point 1: ");
                    p1.accept();
                    rect p2 = new rect();
                    System.out.println("Point 2: ");
                    p2.accept();
                    rect p3 = new rect();
                    System.out.println("Point 3: ");
                    p3.accept();
                    rect p4 = new rect();
                    System.out.println("Point 4: ");
                    p4.accept();
                    rect r = new rect();
                    r.calaculate(p1, p2, p3, p4);
                    break;
                }
            }
        } while (choice != 4);
    }
}

class p {
    double x1, y1;
    double distance;

    void accept() {
        Scanner sc = new Scanner(System.in);
        System.out.print("X: ");
        x1 = sc.nextDouble();
        System.out.print("Y: ");
        y1 = sc.nextDouble();
    }

    void display() {
        System.out.println("X: " + x1);
        System.out.println("Y: " + y1);
        distance = Math.sqrt(x1 * x1 + y1 * y1);
        System.out.println("Distance From (0,0): " + distance);
    }
}

class line extends p {
    double distance;

    double calaculate(p p1, p p2) {
        distance = Math.sqrt((p1.x1 - p2.x1) * (p1.x1 - p2.x1) + (p1.y1 - p2.y1) * (p1.y1 - p2.y1));
        return distance;
    }
}

class rect extends p {
    double area;

    void calaculate(p p1, p p2, p p3, p p4) {
        line l = new line();
        double k1 = l.calaculate(p1, p2);
        double k2 = l.calaculate(p2, p3);
        double k3 = l.calaculate(p3, p4);
        double k4 = l.calaculate(p4, p1);
        if (k1 == k3 && k2 == k4 && k1 > 0) {
            area = k1 * k2;
            System.out.println("Area of Rectangle: " + area);
        } else {
            System.out.println("Rectangle Not Possible! ");
        }
    }
}