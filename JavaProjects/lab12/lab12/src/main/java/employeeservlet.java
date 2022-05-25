
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import model.employee;

@WebServlet(name = "employeeservlet", urlPatterns = "/register")
public class employeeservlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    String firstname, lastname, username, password, address, contact;

    public int registerEmployee(employee emp) throws ClassNotFoundException {
        int result = 0;
        int id = 1;
        Class.forName("com.mysql.cj.jdbc.Driver");
        try {
            Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/employeedata", "root",
                    "Rohit866*");
            String query1 = "INSERT INTO employee VALUES (" + id + "," + emp.getFirstname() + "," + emp.getLastname()
                    + "," + emp.getUsername()
                    + "," + emp.getPassword() + "," + emp.getAddress() + "," + emp.getContact()
                    + ");";
            PreparedStatement pstmt = connection.prepareStatement(query1);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            printSQLExeception(e);
        }

        return result;
    }

    private void printSQLExeception(SQLException ex) {
        for (Throwable e : ex) {
            if (e instanceof SQLException) {
                e.printStackTrace(System.err);
                System.err.println("SQLState: " + ((SQLException) e).getSQLState());
                System.err.println("Error Code: " + ((SQLException) e).getErrorCode());
                System.err.println("Message: " + (e.getMessage()));
                Throwable t = ex.getCause();
                while (t != null) {
                    System.out.println("Cause " + t);
                    t = t.getCause();
                }
            }
        }
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        firstname = request.getParameter("firstname");
        lastname = request.getParameter("lastname");
        username = request.getParameter("username");
        password = request.getParameter("password");
        address = request.getParameter("address");
        contact = request.getParameter("contact");
        int flag = 2;
        employee emp = new employee();
        emp.setFirstname(firstname);
        emp.setLastName(lastname);
        emp.setUserName(username);
        emp.setpassword(password);
        emp.setContact(contact);
        emp.setAddress(address);
        try {
            flag = registerEmployee(emp);

        } catch (Exception e) {
            e.printStackTrace();
        }
        if (flag != 0) {
            response.sendRedirect("employeedetails.jsp");
        }
    }

}
