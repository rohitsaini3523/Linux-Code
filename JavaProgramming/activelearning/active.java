package activelearning;

import java.util.Iterator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class active {

    public static void main(String[] args) {
        int choice = 0;
        Scanner sc = new Scanner(System.in);
        PriorityQueue<String> p = new PriorityQueue<String>();
        while (choice != 6) {
            System.out.print(
                    "\nMenu\n1.Add\n2.Display Using Iterator\n3.Copy into New PriorityQueue\n4.Size of PriorityQueue\n5.Removing first Element\n6.Exit\nChoice:  ");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    add(p);
                    break;

                case 2:
                    display(p);
                    break;

                case 3:
                    copy(p);
                    break;

                case 4:
                    count(p);
                    break;

                case 5:
                    p = removefirst(p);
                    display(p);
                    break;
            }
        }
            sc.close();
    }

    public static void add(PriorityQueue<String> p) 
    {
        Scanner sc = new Scanner(System.in);
        int k, n;
        System.out.print("\nEnter Size of Pqueue: ");
        k = sc.nextInt();
        n = k;
        String s;
        while (k > 0) 
        {
            System.out.print("Enter element " + (n - k + 1) + ": ");
            s = sc.next();
            p.add(s);
            k--;
        }

        System.out.print("Data in PriorityQueue: ");
        System.out.print(p + "\n");
    }

    public static void display(PriorityQueue<String> p) 
    {
        Iterator a = p.iterator();
        System.out.print("Using Iterator: ");
        while (a.hasNext()) {
            System.out.print(a.next() + " ");
        }
    }

    public static void copy(PriorityQueue<String> p) {
        PriorityQueue<String> p1 = p;
        System.out.print("\nCopied PriorityQueue: ");
        System.out.print(p1 + "\n");
    }

    public static void count(PriorityQueue<String> p) {
        System.out.print("Size of PriorityQueue: " + p.size());
    }

    public static PriorityQueue<String> removefirst(PriorityQueue<String> p) {
        System.out.print("\nElement to be removed: ");
        System.out.print(p.poll() + "\n");
        return p;
    }
}
