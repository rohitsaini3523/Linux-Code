import java.util.InputMismatchException;
import java.util.Scanner;

public class lab6_1a {
    public static void main(String []args)
    {
        Scanner sc  = new Scanner(System.in);
        try
        {
            try
            {
                int arr[] = new int[2];
                arr[0] = 1;
                arr[1] = 6;
                arr[2] = 5; // Index Out of Bound
            } 
            catch(ArrayIndexOutOfBoundsException e)
            {
                System.out.println("Index out of Bound");
            }
            finally
            {
                System.out.println("Exception 1");
            }
            System.out.println("Enter Number 1: ");
            int n1, n2;
            n1 = sc.nextInt();
            System.out.println("Enter Number 2: ");
            n2  = sc.nextInt();
            int ans = n1 / n2;
            System.out.println("Answer : " + ans);

        }
        catch(InputMismatchException e)
        {
            System.out.println("Entered Data is not Integers");
        }
        catch(ArithmeticException e)
        {
            System.out.println("Divide by Zero Occured");
        }
        finally
        {
            System.out.println("Exception 2");
        }
        
       sc.close();
    }
}
