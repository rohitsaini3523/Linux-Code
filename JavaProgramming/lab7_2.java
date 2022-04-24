public class lab7_2 {
    public static void main(String[] args) {
        int n = 4;
        for (int i = 0; i < n; i++) {
            try {
                hi t1 = new hi();
                t1.start();
                //t1.sleep(3);
                hello t2 = new hello();
                t2.start();
                t2.sleep(3);
            } catch (Exception e) {
                System.out.println("Exception Occured" + e);
            }
        }
    }
}

class hi extends Thread {
    public void run() {
        System.out.println("Hii");
    }
}

class hello extends Thread {
    public void run() {
        System.out.println("Hello");
    }
}