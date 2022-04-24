public class lab7_7 {
    public static void main(String[] args) {
        JavisAlive j = new JavisAlive();
        System.out.println("Before Starting thread isAlive : " + j.isAlive());
        j.start();
        System.out.println("After Starting thread isAlive : " + j.isAlive());

    }
}
class JavisAlive extends Thread
{
    public void run()
    {
        try
        {
            Thread.sleep(500);
            System.out.println("is run() method isAlive " + Thread.currentThread().isAlive());
        }
        catch(InterruptedException e)
        {
        }
    }
}
