public class lab3b {
    public static void main(String[] args) {
        hillstations h = new hillstations();
        hillstations h1;
        Manali m = new Manali();
        Kashmir k = new Kashmir();
        Shimla s = new Shimla();
        h1 = m;
        System.out.println(h1.location());
        System.out.println(h1.famousfor());
        System.out.print("\n");
        h1 = k;
        System.out.println(h1.location());
        System.out.println(h1.famousfor());
        System.out.print("\n");
        h1 = s;
        System.out.println(h1.location());
        System.out.println(h1.famousfor());
        System.out.print("\n");
        System.out.println(h.location());
        System.out.println(h.famousfor());

    }

}

class hillstations {
    String location() {
        System.out.print("Location: ");
        return "Empty Place!";
    }

    String famousfor() {
        System.out.print("Shimla is Famous For: ");
        return "Empty Food!";
    }
}

class Manali extends hillstations {
    String location() {
        System.out.print("Location: ");
        return "Manali";
    }

    String famousfor() {
        System.out.print("Manali is Famous For: ");
        return "SNOW VIEW";
    }
}

class Shimla extends hillstations {
    String location() {
        System.out.print("Location: ");
        return "Shimla";
    }

    String famousfor() {
        System.out.print("Shimla is Famous For: ");
        return "Ice Mountain";
    }
}

class Kashmir extends hillstations {
    String location() {
        System.out.print("Location: ");
        return "Kashmir";
    }

    String famousfor() {
        System.out.print("Kashmir is Famous For: ");
        return "Cold Weather";
    }
}