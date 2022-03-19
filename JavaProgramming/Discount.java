import java.util.Scanner;

public class Discount {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Quantity: ");
        int a = sc.nextInt();
        System.out.println("Enter Rate: ");
        int b = sc.nextInt();
        float Discount;
        int amount = a * b;
        if (amount < 5000) {
            Discount = 0.1f;
        } else if (amount >= 5000 && amount < 10000) {
            Discount = 0.15f;
        } else if (amount >= 10000 && amount < 20000) {
            Discount = 0.20f;
        } else {
            Discount = 0.5f;
        }
        float finalBill = amount - Discount * amount;
        System.out.println("Amount: " + (amount));
        System.out.println("Discount: " + (Discount) * 100 + "%");
        System.out.println("Final Bill: " + (finalBill));
        sc.close();
    }
}
