public class rooms {
    public static void main(String[] args) {
        System.out.println("Hello ");
    }
}

//This class contain all the info about Room
class inside_room_details {
    int bed_id;
    int nurse_assigned_id;
    int number_of_patient;
    String nurse_assigned;

    inside_room_details()
    {
        bed_id = 0;
        number_of_patient = 0;
        nurse_assigned_id = 0;
        nurse_assigned = "NULL";
    }
}
//Whole building info
class get_details_buildings extends inside_room_details
{
    int floor_no;
    int total_room_on_floor;
    int Genreal_wards_on_floor;
    int icu_rooms_on_floor;

    get_details_buildings()
    {
        floor_no = 0;
        total_room_on_floor = 0;
        Genreal_wards_on_floor = 0;
        icu_rooms_on_floor = 0;
    }
}
