import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


class NameNotValidException extends Exception {
    public NameNotValidException(String str) {
        super(str);
    }
}

class bank {
    int cid;
    String cname;
    int amount;

    bank() {
        cid = 0;
        cname = "-";
        amount = 0;
    }

    bank(int i, String n, int d) {
        cid = i;
        cname = n;
        amount = d;
    }

    void display() {
        System.out.println("Name: " + cname);
        System.out.println("Customer Id: " + cid);
        System.out.println("Amount: " + amount);

    }

}

public class lab6_1c {
    public static void valid(String name, int cid, int b) throws Exception {
        int temp = 0;
        for (int i = 0; i < name.length(); i++) {
            if ((name.charAt(i) >= 'a' && name.charAt(i) <= 'z') || (name.charAt(i) >= 'A' && name.charAt(i) <= 'Z')) {
                temp = 0;
            } else {
                temp = 1;
            }
        }
        if (temp == 1)
            throw new NameNotValidException("Name is not Valid\n");
        if (cid < 0)
            throw new PositiveValue("\nCid is -ve");
        if (b < 0)
            throw new PositiveValue("\nAmount is Negative!");
        if (cid < 1 || cid > 20)
            throw new CidRange("\nCid Should be in range 1 to 20!");
        if (b < 1000)
            throw new MinimumBalance("\nDeposited Amount should be more than 1000!");

    }

    public static void valid1(int b, int k) throws Exception {
        if (k > b)
            throw new WithdrawAmount("\nWithdrawal Amount should be less than (Account Balance) ");
    }

    // public static void writetoFile(bank g, BufferedWriter b2) throws Exception {
    //     String temp = g.cid + "," + g.cname + "," + g.amount + "\n";
    //     b2.append(temp);
    // }

    public static void main(String[] args) throws IOException {
        // BufferedWriter b2 = new BufferedWriter(new FileWriter("bankDetails.txt"));
        Scanner sc = new Scanner(System.in);
        int id;
        String name;
        int b;
        int k;
        int choice;
        bank dd[] = new bank[20];
        do {
            System.out.print("\nMenu\n1.Create Account\n2.Withdraw Money\n3.Exit\nChoice: ");
            choice = sc.nextInt();
            switch (choice) {
                case 1: {
                    try {
                        System.out.print("Enter Name: ");
                        name = sc.next();
                        System.out.print("Enter Cid: ");
                        id = sc.nextInt();
                        System.out.print("Enter Amount to deposited: ");
                        b = sc.nextInt();
                        valid(name,id, b);
                        bank g = new bank(id, name, b);
                        dd[id - 1] = g;
                        System.out.println("\n");
                        g.display();
                        // writetoFile(g, b2);

                    } catch (Exception e) {
                        System.out.println("Exception Occured! " + e);
                    }
                    break;
                }
                case 2:
                   { try {
                        System.out.print("Enter Cid: ");
                        id = sc.nextInt();
                        System.out.print("Enter Withdraw Amount: ");
                        k = sc.nextInt();
                        bank temp;
                        temp = dd[id - 1];
                        valid("NULL",id, temp.amount);
                        valid1(temp.amount, k);
                        temp.amount -= k;
                        System.out.println("\n");
                        temp.display();

                    } catch (Exception e) {
                        System.out.println("Exception Occured! " + e);
                    }
                    break;
                }
            }
        } while (choice != 3);
        sc.close();
        b2.close();
    }
}

class MinimumBalance extends Exception {
    MinimumBalance(String str) {
        super(str);
    }
}

class WithdrawAmount extends Exception {
    WithdrawAmount(String str) {
        super(str);
    }
}

class CidRange extends Exception {
    CidRange(String str) {
        super(str);
    }
}

class PositiveValue extends Exception {
    PositiveValue(String str) {
        super(str);
    }
}
