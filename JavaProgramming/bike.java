import java.util.Scanner;
class bicycle
{
	double speed;
	int gear;
	bicycle()
	{
		speed =0.0;
		gear = 0;
	}
	void setgear(double k)
	{
		if(k<49)
		gear = (int)k /7;
		else 
			gear =7;
	}
	void accept()
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Speed: ");
		speed = sc.nextDouble();
		setgear(speed);
	}
	void display()
	{
		System.out.println("Speed: "+speed);
		System.out.println("Gear: "+gear);
	}
}
class bik extends bicycle{
	void speedup()
	{
		if(gear<7){
		gear+=1;
		speed+=7;}
	}
	void breaked()
	{
if(speed>7){
		gear-=1;
		speed-=7;
	}}
}
public class bike {

	public static void main(String[]args)
	{
		bik b = new bik();
		b.accept();
		b.display();
		Scanner sc  =new Scanner(System.in);
		int ch =0;
		do
		{
			System.out.println("1.SpeedUp\n2.Break\n3.Exit\nCHoice: ");
			ch = sc.nextInt();
			switch(ch)
			{
				case 1: {b.speedup();
					b.display();
					break;}
				case 2:{ b.breaked();
					b.display();
					break;}
				default:System.out.println("Wrong Choice");break;
				
			}							
			
		}while(ch!=3);
		sc.close();
	}
	
}

