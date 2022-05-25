import java.sql.*;
import java.util.Scanner;
public class App {
    public static void main(String[] args){
        
        String url = "jdbc:mysql://localhost:3306/subject";
        String uname = "root";
        String password = "Rohit866*";
        String query = "select * from subjectinfo";
        Scanner sc = new Scanner(System.in);
        try
        {
            Class.forName("com.mysql.cj.jdbc.Driver");
        }
        catch(ClassNotFoundException e)
        {
            e.printStackTrace();
        }
        try
        {
            Connection con = DriverManager.getConnection(url, uname, password);
            String query1 = "insert into subjectinfo value(?,?,?)";
            PreparedStatement pstmt = con.prepareStatement(query1);
            System.out.println("Enter ID: ");
            pstmt.setInt(1, sc.nextInt());
            System.out.println("Enter BOOKNAME: ");
            pstmt.setString(2, sc.next());
            System.out.println("Enter TYPE: ");
            pstmt.setString(3, sc.next());
            pstmt.executeUpdate();
            Statement statement = con.createStatement();
            ResultSet result = statement.executeQuery(query);
            while(result.next())
            {
                String Data = "";
                for(int i = 1;i<=3; i++)
                {
                    Data += result.getString(i) + "  ";
                }
                System.out.println(Data);
            }
        }catch(SQLException e)
        {
            e.printStackTrace();
        }
    
    }
}
