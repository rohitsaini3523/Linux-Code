import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class readingfile {
    public static void main(String[]args) throws IOException
    {
        FileInputStream F1 = null;
        FileOutputStream F2 = null;
        F1 = new FileInputStream("sourcefile.txt");
        F2 = new FileOutputStream("destinationfile.txt");
        int temp;
        while((temp = F1.read())!=-1)
            F2.write((byte)temp);
        if(F1 !=null)
            F1.close();
        if(F2!=null)
            F2.close();

    }
}
