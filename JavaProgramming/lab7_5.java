public class lab7_5 {
    public static void main(String[]args)
    {
        for (int i = 0; i < 5; i++) 
        {
        Thread t = new Thread(new Multithreading());
        t.start();
    }
    }    

}

class Multithreading implements Runnable
{
    public void run()
    {
        try
        {
            System.out.println("Thread "+ Thread.currentThread()+" is running" );
        }
        catch(Exception e)
        {
            System.out.println("Exception is occurred");
        }
    }
}