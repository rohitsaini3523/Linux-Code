class cn
{
    double real;
    double img;

    cn(double r,double i)
    {
       real = r;
       img = i;
    }
    cn add(cn c)
    {
        cn ans = new cn(0, 0);
        ans.real = real + c.real;
        ans.img = img + c.img;
        return ans;
    }
    cn sub(cn c)
    {
        cn ans = new cn(0, 0);
        ans.real = real - c.real;
        ans.img = img - c.img;
        return ans;
    }
}

public class complex {
 
    public static void main(String[]args)
    {
        cn a = new cn(2, 4);
        cn b = new cn(14, 16);
        System.out.println("Z1: " + a.real + "+ " + a.img + "i");
        System.out.println("Z2: " + b.real + "+ " + b.img + "i");
        cn ans = new cn(0, 0);
        ans  = a.add(b);
        System.out.println("Add: " + ans.real + "+ " + ans.img + "i");
        ans = new cn(0, 0);
        ans = b.sub(a);
        System.out.println("Sub: " + ans.real + "+ " + ans.img + "i");  
    }
}
