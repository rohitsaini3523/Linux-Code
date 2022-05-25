


import java.io.IOException;
import java.sql.SQLException;


import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import model.Employee;

@WebServlet(name="EmployeeLoginServlet", urlPatterns="/emplogin")
public class EmployeeLoginServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public EmployeeLoginServlet() {
        super();
    }


	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		getServletContext().getRequestDispatcher("/empLogin.jsp").forward(request, response);
	}


	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String username=request.getParameter("username");
		String password=request.getParameter("password");
		
		
		if(username=="" || password=="") {
			request.setAttribute("error", "You are missing one of the input");
			RequestDispatcher rd = request.getRequestDispatcher("empLogin.jsp");
			rd.include(request, response);
		} else
			try {
				if(Employee.check(username,password)) {
					response.sendRedirect("/empoptions");
				}
				else {
					request.setAttribute("error", "Incorrect Username or Password");
					RequestDispatcher rd = request.getRequestDispatcher("empLogin.jsp");
					rd.include(request, response);
				}
			} catch (ClassNotFoundException | SQLException | IOException | ServletException e) {
				request.setAttribute("error", e.toString());
				doGet(request, response);
			}
		
	}

}
