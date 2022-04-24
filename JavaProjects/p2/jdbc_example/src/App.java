import java.sql.*;
import java.util.Scanner;
public class App {
    public static void main(String[] args){
        
        String url = "jdbc:mysql://localhost:3306/bookshop";
        String uname = "root";
        String password = "Rohit866*";
        String query = "select * from book";
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
            String query1 = "insert into book value(?,?,?,?)";
            PreparedStatement pstmt = con.prepareStatement(query1);
            System.out.println("Enter Name: ");
            pstmt.setString(2, sc.next());
            System.out.println("Enter ID: ");
            pstmt.setInt(1, sc.nextInt());
            System.out.println("Enter Cost: ");
            pstmt.setInt(3, sc.nextInt());
            System.out.println("Enter Date: ");
            pstmt.setString(4, sc.next());
            pstmt.executeUpdate();
            Statement statement = con.createStatement();
            ResultSet result = statement.executeQuery(query);
            while(result.next())
            {
                String Data = "";
                for(int i = 1;i<=4; i++)
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
