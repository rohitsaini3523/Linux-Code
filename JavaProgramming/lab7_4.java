public class lab7_4 {

    public static void main(String[] args) {
        NewThread t = new NewThread();
        t.start();
    }   
}

class NewThread extends Thread
{
    NewThread()
    {
        super("Demo Thread");
        System.out.println("Child Thread " + this);
    }

    public void run()
    {
        try
        {
            for(int i =0 ;i< 5; i++)
            {
                System.out.println("Child Thread "+ i);
            }
            Thread.sleep(500);
        }
        catch(InterruptedException e)
        {
            System.out.println("Child Interrupted");
        }
        System.out.println("Exiting Child Thread");
    }
}

