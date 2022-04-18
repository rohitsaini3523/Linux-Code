import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class lab5_1 {
    public static void main(String[]args) throws IOException
    {
        //InputStreamReader i = new InputStreamReader(new FileInputStream("sourcefile.txt"));
        BufferedReader b1 = new BufferedReader(new FileReader("sourcefile.txt"));
        //OutputStreamWriter o = new OutputStreamWriter(new FileOutputStream("destination.txt"));
        BufferedWriter b2 = new BufferedWriter(new FileWriter("destination.txt"));        
        int temp;
        while((temp = b1.read())!=-1)
        {
            b2.write((byte) temp);
            System.out.print((char) temp);
        }
        System.out.println("\nEnter Any Txt: ");
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String str = "\n" + s;
        b2.write(str);
        if(b1 !=null)
            b1.close();
        if(b2!=null)
            b2.close();
        sc.close();
    }    
}
