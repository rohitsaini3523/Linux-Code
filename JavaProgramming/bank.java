import java.util.Scanner;

abstract class b {
    protected String name;
    protected int ID;
    protected double FDamount;
    protected double FDamountUpdated;
    public abstract double rateofinterest();

    b()
    {
        name = "-";
        ID = 0;
        FDamount = 0.0;
        FDamountUpdated = 0.0;
    }
    void accept()
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Name:  ");
        name = sc.next();
        System.out.print("Enter ID:  ");
        ID = sc.nextInt();
        System.out.print("Enter FDamount:  ");
        FDamount = sc.nextDouble();
    }

    public abstract void display(); 
}

class sbi extends b {
    public double rateofinterest() {
        double k = 0.07;
        return k;
    }

    sbi()
    {
        super();
    }

    public void display()
    {
        System.out.println("Bank : SBI");
        System.out.println("Name: " + name);
        System.out.println("ID: " + ID);
        System.out.println("FDamount (Initial): " + FDamount);
        System.out.println("{SBI}FDamount (After 5 Years): " + calculateFD(FDamount));
        pnb p = new pnb();
        System.out.println("{PNB}FDamount (After 5 Years): " + p.calculateFD(FDamount));
    }

    public double calculateFD(double FDamount)
    {
        FDamountUpdated = 0;
        for (int i = 0; i < 60; i++)
        {
            FDamountUpdated += (FDamount * rateofinterest());
        }
        return FDamountUpdated;
    }

}

class pnb extends b
{
    pnb()
    {
        super();
    }
    public double rateofinterest()
    {
        double k = 0.08;
        return k;
    }
    public void display()
    {
        System.out.println("Bank : PNB");
        System.out.println("Name: " + name);
        System.out.println("ID: " + ID);
        System.out.println("FDamount (Initial): " + FDamount);
        System.out.println("{PNB}FDamount (After 5 Years): " + calculateFD(FDamount));
        sbi s = new sbi();
        System.out.println("{SBI}FDamount (After 5 Years): " + s.calculateFD(FDamount));
    }
    public double calculateFD(double FDamount)
    {
        FDamountUpdated = 0;
        for (int i = 0; i < 60; i++)
        {
            FDamountUpdated += (FDamount * rateofinterest());
        }
        return FDamountUpdated;
    }
}

public class bank {
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);
        int choice = 0;
        do
        {
            System.out.println("Menu\n1.SBI\n2.PNB\n3.Exit\nChoice: ");
            choice = sc.nextInt();
            switch(choice)
            {
                case 1:
                    sbi s = new sbi();
                    pnb p = new pnb();
                    s.accept();
                    s.display();
                    s.calculateFD(s.FDamount);
                    break;
                case 2:
                    sbi s1 = new sbi();
                    pnb p1 = new pnb();
                    p1.accept();
                    p1.display();
                    p1.calculateFD(p1.FDamount);
                    break;
            }
        } while (choice != 3);
    }
    
}
