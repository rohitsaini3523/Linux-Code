import java.util.Scanner;
class EMP
{
	String name;
	int id;
	double salary;
	EMP()
	{
		System.out.println("DEFAULT CONSTRUCTOR!");
		name = "-";
		id = 0;
		salary =0;
	}
	EMP(String s,int k,double b)
	{
		System.out.println("Parametrize CONSTRUCTOR!");
		name = s;
		id = k;
		salary =b;
	}
	
	public void accept()
	{
		System.out.print("Enter Name: ");
		Scanner sc =new Scanner(System.in);
		name = sc.next();
		System.out.print("Enter EMP ID: ");
		id = sc.nextInt();
		System.out.print("Enter Salary: ");
		salary = sc.nextDouble();
	}
	public void display()
	{
		System.out.println("NAME: "+name);
		System.out.println("ID: "+id);
		System.out.println("(Beforer Increment)Salary: "+ salary);
	}
	
}
class fullEMP extends EMP
{
	public void calculatesalary()
	{
		double newsalary = 1.5 * super.salary;
		System.out.println("(After Increment)Salary: "+newsalary);
	}
	public void display()
	{	
		super.display();
		calculatesalary();
	}
}
class internEMP extends EMP
{
	public void calculatesalary()
	{
		double newsalary = 1.25 * salary;
		System.out.println("(After Increment)Salary: "+newsalary);
	}
	public void display()
	{	
		super.display();
		calculatesalary();
	}
}
public class Employee {

	public static void main(String[]args)
	{
		Scanner sc1 =new Scanner(System.in);
		int choice=0;
		do
		{
			System.out.print("1.Fulltime\n2.Intern\n3.Exit\nEmployee Choice: ");
			choice  = sc1.nextInt();
				switch(choice)
				{
					case 1:
					{
						fullEMP E1= new fullEMP();
						E1.accept();
						E1.display();
						//E1.calculatesalary();
					break;
					}
					case 2:
					{
						internEMP E2= new internEMP();
						E2.accept();
						E2.display();
						//E2.calculatesalary();
						EMP e  =new EMP("ROHIT",1,10000);
						e.display();
						
					break;
					}
					case 3:
						System.out.println(" Exitting\n");
						break;
						
					default :
						System.out.println("Wrong Choice\n");
						break;	
						
			}
				
		}while(choice != 3);
		sc1.close();
	}
	
}
