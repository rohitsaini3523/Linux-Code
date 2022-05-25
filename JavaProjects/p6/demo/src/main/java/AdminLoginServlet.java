
import model.Admin;
import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(name="AdminLoginServlet", urlPatterns="/adminlogin")
public class AdminLoginServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public AdminLoginServlet() {
        super();
    }


	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		getServletContext().getRequestDispatcher("/admLogin.jsp").forward(request, response);
	}


	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String username=request.getParameter("username");
		String password=request.getParameter("password");
		Admin obj = new Admin();
		
		if(username=="" || password=="") {
			request.setAttribute("error", "You are missing one of the input");
			RequestDispatcher rd = request.getRequestDispatcher("admLogin.jsp");
			rd.include(request, response);
		}
		else if(obj.check(username,password)) {
			response.sendRedirect("/adminoptions");
		}
		else {
			request.setAttribute("error", "Incorrect Username or Password");
			RequestDispatcher rd = request.getRequestDispatcher("admLogin.jsp");
			rd.include(request, response);
		}
		
	}

}
