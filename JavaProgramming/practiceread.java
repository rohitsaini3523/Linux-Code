import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class practiceread {
    public static void main(String []args) throws IOException
    {
        //char c;
        String str;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter 'q' to Quit! ");
        do
        {
            //c = (char) br.read();
            //System.out.print(c);
            str = br.readLine();
            System.out.println(str);
        } //while (c != 'q');
        while(!str.equals("Stop"));
    }
}
