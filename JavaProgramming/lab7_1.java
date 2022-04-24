public class lab7_1 {
    public static void main(String[] args) {
        int n = 8;
        for (int i = 0; i < n; i++) {
            MThread t = new MThread();
            t.start();
        }
    }
}

class MThread extends Thread
{
    public void run()
    {
        try {
            System.out.println("Thread " + Thread.currentThread() + " is running! ");
        } catch (Exception e) {
            System.out.println("Exception is caught!");
        }
    }
}
