import java.util.Scanner;

abstract class instru {
    instru() {
        System.out.println("Instrument is created!");
    }

    public abstract void play();

}

class piano extends instru {
    piano() {
        super();
        System.out.print("Piano Created Successfully\n");
    }

    public void play() {
        System.out.println("Piano is playing tan tan tan");
    }
}

class Flute extends instru {
    Flute() {
        super();
        System.out.print("Flute Created Successfully\n");
    }

    public void play() {
        System.out.println("Flute is playing toot toot toot");
    }
}
class Guitar extends instru
{
    Guitar()
    {
        super();
        System.out.print("Guitar Created Successfully\n");
    }
    public void play()
    {
        System.out.println("Guitar is playing tin tin tin");
    }
}

public class instrument {
    public static void main(String [] args)
    {
        Scanner sc = new Scanner(System.in);
        int choice = 0;
        do
        {
            System.out.println("Menu\n1.Piano\n2.Flute\n3.Guitar\n4.Exit\nChoice: ");
            choice = sc.nextInt();
            switch(choice)
            {
                case 1:
                    piano p = new piano();
                    p.play();
                    break;
                case 2:
                    Flute f = new Flute();
                    f.play();
                    break;
                case 3:
                    Guitar g = new Guitar();
                    g.play();
                    break;
                
            }
        } while (choice != 4);
    }
    
}
