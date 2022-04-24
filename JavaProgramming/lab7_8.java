public class lab7_8 {
    public static void main(String[]args)
    {
        mythread t1 = new mythread();
        mythread t2 = new mythread();
        t1.start();
        /* try
        {
            t1.join();
        }
        catch(InterruptedException e){} */
        t2.start();
    }
}

class mythread extends Thread
{
    public void run()
    {
        System.out.println("r1");
        try 
        {
            Thread.sleep(500);
        }
        catch(InterruptedException e)
        {
        }
        System.out.println("r2");
    }
}