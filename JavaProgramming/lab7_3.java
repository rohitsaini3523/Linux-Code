public class lab7_3 {
    // to return the answer array
    public static int[] product(int[] a, int c) {
        int k = a.length;
        Thread[] t = new Thread[k];

        for (int i = 0; i < k; i++) {
            t[i] = new Thread(new multiply(a, c, i));
            t[i].start();
        }

        for (int i = 0; i < k; i++) {
            try {
                t[i].join();
            } catch (InterruptedException e) {
                System.out.println("Exception: " + e);
            }
        }
        return a;
    }

    public static void main(String[] args) {
        int n = 10;
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = 0;
            a[i] = i + 1;
            System.out.print(a[i] + ",");
        }
        int c = 10;
        a = product(a, c);
        System.out.println("\n");
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + ",");
        }

    }
}

class multiply extends Thread {
    private int[] a;
    private int c;
    private int index;

    public multiply(int[] a, int c, int index) {
        this.a = a;
        this.c = c;
        this.index = index;
    }

    public void run() {
        a[index] = a[index] * c;
    }
}