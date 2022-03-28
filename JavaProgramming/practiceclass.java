class box {
    double height;
    double width;
    double length;
}

class practiceclass {
    public static void main(String[] args) {
        box b1 = new box();
        box b2 = new box();
        b1.height = 10.0;
        b1.length = 11.0;
        b1.width = 5.0;
        double volume;
        volume = b1.height * b1.length * b1.width;
        System.out.println("Volume of Box-1 is : " + volume);
        b2.height = 5.0;
        b2.length = 5.0;
        b2.width = 10.0;
        volume = b2.height * b2.length * b2.width;
        System.out.println("Volume of Box-2 is : " + volume);
    }
}
