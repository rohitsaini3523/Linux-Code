public class lab7_6 {
    public static void main(String[] args) {
        ThreadDemo t1 = new ThreadDemo();
        ThreadDemo t2 = new ThreadDemo();
        ThreadDemo t3 = new ThreadDemo();
        System.out.println("Thread 1 : " + t1.getPriority());
        System.out.println("Thread 2 : " + t2.getPriority());
        System.out.println("Thread 3 : " + t3.getPriority());
        t1.setPriority(3);
        t2.setPriority(8);
        t3.setPriority(9);
        System.out.println("\nAfter Setting Priority\n");
        System.out.println("Thread 1 : " + t1.getPriority());
        System.out.println("Thread 2 : " + t2.getPriority());
        System.out.println("Thread 3 : " + t3.getPriority());
        System.out.println("Now: " + Thread.currentThread().getName());
        System.out.println("Priority: "+ Thread.currentThread().getPriority());
        Thread.currentThread().setPriority(4);
        System.out.println("Priority After Changing: "+Thread.currentThread().getPriority());
        
        

    }
}

class ThreadDemo extends Thread
{
    public void run()
    {
        System.out.println("Inside Run Method");
    }
}
