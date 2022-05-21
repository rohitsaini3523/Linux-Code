package model;


import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class Employee {
	
	public static boolean check(String us,String pass) throws ClassNotFoundException, SQLException {
		Class.forName("com.mysql.cj.jdbc.Driver");
		String jdbcurl = "jdbc:mysql://localhost:3306/Miniproject"; //3306 is port id of mysql
        Connection con = DriverManager.getConnection(jdbcurl,"root","Rohit866*");
        
        
        String query="select * from employee";
        Statement stmt = con.createStatement();
        ResultSet rs = stmt.executeQuery(query);
        boolean val=false;
        while(rs.next()) {
        	if((rs.getString(1)).compareToIgnoreCase(us)==0 && (rs.getString(5)).compareTo(pass)==0) {
        		val=true;
        	}
        }
		return val;
	}
	
	public static void main(String[] args) throws ClassNotFoundException, SQLException {
		System.out.println(check("rohit","Password"));
	}
}
