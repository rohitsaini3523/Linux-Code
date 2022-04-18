import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class lab5_3 {
    public static String check(String l[],String longest )
    {   
        for(int i =0 ; i<l.length; i++)
        {
            if(longest.length() < l[i].length())
                longest = l[i];
        }
        return longest;
    }
    public static void main(String[]args) throws IOException
    {
        BufferedReader b1 = new BufferedReader(new FileReader("sourcefile.txt"));
        String str, longest_word = "";
        while((str = b1.readLine())!=null)
        {
            //System.out.println(str);
            String l[] = str.split(" ");
            longest_word = check(l,longest_word);
        }
        System.out.print("Longest Word: " + longest_word);
        System.out.print("\nLength : " + longest_word.length());
        b1.close();
    }    
}
