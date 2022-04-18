public class lab6_prac {
    public static void main(String[] args) {
        try {
            System.out.print("Hello\n");
            int a = 45 / 0;
            System.out.println("Divide by zero Occured");
        } catch (ArithmeticException e) {
            System.out.println("Divide by 0");
        } catch (Exception e) {
            System.out.println("Inside Exception");
        }

    }
}
