#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/* ---------- STRUCTURES ---------- */

struct Date
{
    int day;
    int month;
    int year;
};

struct Vehicle
{
    string plate_number;
    string brand_or_model;
    string vehicle_type;
    string manufactured_year;
    bool available;
};

struct Booking
{
    string F_name, L_name;
    string license_number;
    string phone_number;
    string plate_number;
    string address;
    string calculate_bill;
   
    Date rented_date;
    Date return_date;
    
};

void welcome()
{
    cout<<"      ___________________________        "<<endl;
    cout<<"------- Welcome To Our Cab Rental -------"<<endl;
    cout<<"      ---------------------------        "<<endl;
    cout<<"              _____         " << endl;
    cout<<"           __/_____\\__     " << endl;
    cout<<"          |  _     _  |     " << endl;
    cout<<"          '-(o)---(o)-'     " << endl<<endl;
}



/* ---------- CLASS ---------- */

class Cab_rental_system
{
public:
    vector<Vehicle> vehicles;
    vector<Booking> bookings;

    /* VEHICLE FUNCTIONS */

   void add_vehicle (string plate_number,string brand_or_model,string vehicle_type,bool available,string manufactured_year)
  
    {
       
        Vehicle vehicle;
        vehicle.plate_number=plate_number;
        vehicle.brand_or_model=brand_or_model;
        vehicle.vehicle_type=vehicle_type;
        vehicle.manufactured_year=manufactured_year;
        vehicle.available=available;
        vehicles.push_back(vehicle);
    }


    void display_vehicle()
    {
        
        cout <<"--All the vehicles you have--"<<endl;
        cout <<"plate_number"<<"\t"<<"|"<<"brand_or_model"<<"\t"<<"|"<<"vehicle_type"<<"\t"<<"|"<<"availability"<<endl;
        for(int i=0;i<vehicles.size();i++)
        {
            cout<<vehicles[i].plate_number<<"\t"<<"\t"<<"\t"<<"|"<<vehicles[i].brand_or_model<<"\t"<<"\t"<<"|"<<vehicles[i].vehicle_type<<"\t"<<"\t"<<"\t"<<"|"<<(vehicles[i].available ? "Available" : "Booked")
            <<endl;
        }
    }
    
    void display_bookings()
    {
        cout <<"--- ALL BOOKED CARS---"<<endl;
        for (int i=0; i<bookings.size();i++)
        {
            cout<<"first name :"<<bookings[i].F_name<<endl;
            cout<<"plate number :"<<bookings[i].plate_number<<endl;
            
        }
    }

  void update_vehicle(string plate_number)
    {
        int i = search_vehicle(plate_number);
        if (i == -1) return void(cout << "Vehicle not found!\n");

        cout << "New Brand/Model: "<<endl;
      cout << "--> ";
        cin >> vehicles[i].brand_or_model;
        cout << "New Type: "<<endl;
      cout << "--> ";
        cin >> vehicles[i].vehicle_type;
        cout << "New Year: "<<endl;
      cout << "--> ";
        cin >> vehicles[i].manufactured_year;

        cout << "Vehicle updated successfully!\n";
    }

    int search_vehicle(string plate_number)
    {
        for (int i = 0; i < vehicles.size(); i++)
            if (vehicles[i].plate_number == plate_number)
                return i;
        return -1;
    }

    void sort_vehicles(bool ascending)
    {
        for (int i = 0; i < vehicles.size() - 1; i++)
            for (int j = i + 1; j < vehicles.size(); j++)
                if ((ascending && vehicles[i].plate_number > vehicles[j].plate_number) ||
                   (!ascending && vehicles[i].plate_number < vehicles[j].plate_number))
                    swap(vehicles[i], vehicles[j]);
    }

    /* BOOKING FUNCTIONS */

    void book_vehicle(Booking book)
    {
        int vehicle_index=search_vehicle(book.plate_number);
        if (vehicle_index==-1)
        {
            cout <<"plate number doesnot exist!!!";
            return ;
        }
        if (vehicles[vehicle_index].available)
        {
            vehicles[vehicle_index].available=false;
        }
        else
        {
            cout <<"not available";
            return;
        }
        
        bookings.push_back(book);
    }

    void update_booking(string plate_number)
    {
        int i = search_booking(plate_number);
        if (i == -1)
            
            return void(cout << "Booking not found!\n");

        cout << "New Phone: "<<endl;
        cout << "--> ";
        cin >> bookings[i].phone_number;
        cout << "New Return Date (dd mm yyyy): "<<endl;
        cout << "--> ";
        cin >> bookings[i].return_date.day
            >> bookings[i].return_date.month
            >> bookings[i].return_date.year;

        cout << "Booking updated successfully!\n";
    }

   void return_vehicle(string plate_number)
    {
        int vehicle = search_vehicle(plate_number);
        int booking = search_booking(plate_number);

        if (vehicle != -1) vehicles[vehicle].available = true;
        if (booking != -1) bookings.erase(bookings.begin() + booking);

        cout << "Vehicle returned successfully!\n";
    }

   int search_booking(string plate_number)
    {
        for (int i = 0; i < bookings.size(); i++)
            if (bookings[i].plate_number == plate_number)
                return i;
        return -1;
    }

  void sort_bookings(bool ascending)
    {
        for (int i = 0; i < bookings.size() - 1; i++)
            for (int j = i + 1; j < bookings.size(); j++)
                if ((ascending && bookings[i].F_name > bookings[j].F_name) ||
                   (!ascending && bookings[i].F_name < bookings[j].F_name))
                    swap(bookings[i], bookings[j]);
    }

    /* FILE HANDLING */

    void save_data()
    {
        ofstream vehicle("vehicles.txt"), booking("bookings.txt");

        for (auto x : vehicles)
            vehicle << x.plate_number << " " << x.brand_or_model << " "
              << x.vehicle_type << " " << x.manufactured_year << " "
              << x.available << endl;

        for (auto x : bookings)
            booking << x.F_name << " " << x.L_name << " "
              << x.plate_number << " " << x.phone_number << endl;

        vehicle.close(); booking.close();
        cout << "Data saved successfully!\n";
    }

   void load_data()
    {
        vehicles.clear(); bookings.clear();
        Vehicle vehicle; Booking booking;

        ifstream vehicle_file("vehicles.txt");
        while (vehicle_file >> vehicle.plate_number >> vehicle.brand_or_model
                  >> vehicle.vehicle_type >> vehicle.manufactured_year >> vehicle.available)
            vehicles.push_back(vehicle);
        vehicle_file.close();

        ifstream booking_file("bookings.txt");
        while (booking_file >> booking.F_name >> booking.L_name >> booking.plate_number >> booking.phone_number)
            bookings.push_back(booking);
        booking_file.close();

        cout << "Data loaded successfully!\n";
    }
};

/* ---------- BILLING ---------- */
int days_from_0(Date d)
{
    return d.year * 365 + d.month * 30 + d.day;
}

int rental_days(Date start, Date end)
{
    int start_days = days_from_0(start);
    int end_days   = days_from_0(end);

    return (end_days - start_days) + 1;
}


float calculate_bill(Booking booking)
{
    float pricePerDay = 2000;   // ETB per day

    int days = rental_days(booking.rented_date,
                           booking.return_date);

    if (days <= 0)
    {
        cout << "Invalid rental dates!" << endl;
        return 0;
    }

    return days * pricePerDay;
}

/* ---------- MENU & MAIN ---------- */

void menu()
{
    cout << "\n1 Add Vehicle\n2 Update Vehicle\n3 Book Vehicle\n4 Return Vehicle\n"
         << "5 Update Booking\n6 Sort Vehicles\n7 Sort Bookings\n"
         << "8 Display Vehicles\n9 Display Bookings\n"
         << "10 Calculate Bill\n11 Save Data\n12 Load Data\n0 Exit\n ";
}

int main()
{
    welcome();
    Cab_rental_system cab_rental_system;
    int menu_number;
    int vehicle_size;

    while (true)
    {
        menu();
        cout<<"enter your choice"<<endl;
        cout << "--> ";
        cin >> menu_number;

        if (menu_number == 0) break;

        if (menu_number == 1)
        
            {
               
                cout << "How many vehicles you want to add: "<<endl;
                cout << "--> ";
                cin >> vehicle_size;

                for (int i = 0; i < vehicle_size; i++)
                {
                    string plate, brand, type, year;

                    cout << "\nVehicle " << i + 1 << endl;

                    cout << "Plate number: "<<endl;
                    cout << "--> ";
                    cin >> plate;

                    cout << "Brand or model: "<<endl;
                    cout << "--> ";
                    cin >> brand;

                    cout << "Vehicle type: "<<endl;
                    cout << "--> ";
                    cin >> type;

                    cout << "Manufactured year: "<<endl;
                    cout << "--> ";
                    cin >> year;

                    cab_rental_system.add_vehicle(plate, brand, type, true, year);
                }

                cout << " ===Vehicle added successfully===\n";
            }

        else if (menu_number == 2)
        {
            string plate; cout << "Plate_number: "<<endl;
            cout << "--> ";
            cin >> plate;
            cab_rental_system.update_vehicle(plate);
        }
        else if (menu_number == 3)
        {
            Booking booking;
            cout << "First_Name: "<<endl;
            cout << "--> ";
            cin >> booking.F_name;
            cout << "Last_Name: "<<endl;
            cout << "--> ";
            cin >> booking.L_name;
            cout<< "License_number: "<<endl;
            cout << "--> ";
            cin>>booking.license_number;
            cout << "Phone_number: "<<endl;
            cout << "--> ";
            cin >> booking.phone_number;
            cout << "Plate_number: "<<endl;
            cout << "--> ";
            cin >> booking.plate_number;
            cout << "Address: "<<endl;
            cout << "--> ";
            cin >> booking.address;
            cout << "Start_date (dd mm yyyy): "<<endl;
            cout << "--> ";
            cin >> booking.rented_date.day >> booking.rented_date.month >> booking.rented_date.year;
           
            cout << "Return_date (dd mm yyyy): "<<endl;
            cout << "--> ";
                        cin >> booking.return_date.day >> booking.return_date.month >> booking.return_date.year;
                        
            cab_rental_system.book_vehicle(booking);
        }
        else if (menu_number == 4)
        {
            string plate; cout << "Plate_number: "<<endl;
            cout << "--> ";
            cin >> plate;
            cab_rental_system.return_vehicle(plate);
        }
        else if (menu_number == 5)
        {
            string plate; cout << "Plate_number: "<<endl;
            cout << "--> ";
            cin >> plate;
            cab_rental_system.update_booking(plate);
        }
        else if (menu_number == 6)
        {
            int sort; cout << "1 Asc 2 Desc: "<<endl;
            cout << "--> ";
            cin >> sort;
            cab_rental_system.sort_vehicles(sort == 1);
        }
        else if (menu_number == 7)
        {
            int sort; cout << "1 Asc 2 Desc: "<<endl;
            cout << "--> ";
            cin >> sort;
            cab_rental_system.sort_bookings(sort == 1);
        }
        else if (menu_number == 8 ) cab_rental_system.display_vehicle();
        else if (menu_number == 9) cab_rental_system.display_bookings();
        else if (menu_number == 10)
        {
            string plate; cout << "Plate_number: "<<endl;
            cout << "--> ";
            cin >> plate;
            int i = cab_rental_system.search_booking(plate);
            if (i != -1)
                cout << "Total Bill: " << calculate_bill(cab_rental_system.bookings[i]) << " ETB\n";
            else cout << "Booking not found!\n";
        }
        else if (menu_number == 11) cab_rental_system.save_data();
        else if (menu_number == 12) cab_rental_system.load_data();
    }
    return 0;
}

