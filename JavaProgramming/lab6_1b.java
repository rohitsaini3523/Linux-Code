import java.util.Scanner;

class AgeNotWithinRangeException extends Exception {
    public AgeNotWithinRangeException(String str) {
        super(str);
    }
}

class NameNotValidException extends Exception {
    public NameNotValidException(String str) {
        super(str);
    }
}

public class lab6_1b {
    public static void valid(String name, int age) throws Exception {

        if (age < 25 || age > 60) {
            throw new AgeNotWithinRangeException("Age not Valid");
        }
        int temp = 0;
        for (int i = 0; i < name.length(); i++) {
            if ((name.charAt(i) >= 'a' && name.charAt(i) <= 'z') || (name.charAt(i) >= 'A' && name.charAt(i) <= 'Z')) {
                temp = 0;
            }
            else
            {
                temp =1;
            }
        }
        if (temp == 1)
            throw new NameNotValidException("Name is not Valid\n");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try {
            String n;
            int id;
            int a;
            String d;
            System.out.println("Enter Name: ");
            n = sc.next();
            System.out.println("Enter ID: ");
            id = sc.nextInt();
            System.out.println("Enter Age: ");
            a = sc.nextInt();
            System.out.println("Enter Department: ");
            d = sc.next();
            valid(n,a);
            employee e = new employee(id, n, a, d);
            e.display();
        } catch (Exception e) {
            System.out.println("Exception Occured! \n" + e);
        }
        sc.close();
    }
}

class employee {
    int empid;
    String name;
    int age;
    String department;

    employee() {
        empid = 0;
        name = "-";
        age = 0;
        department = "-";
    }

    employee(int id, String n, int a, String d) {
        empid = id;
        name = n;
        age = a;
        department = d;
    }

    void display() {
        System.out.println("Name: " + name);
        System.out.println("Empolyee Id: " + empid);
        System.out.println("Age: " + age);
        System.out.println("Department: " + department);

    }
}
