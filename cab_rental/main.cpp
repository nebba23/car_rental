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
    string manufactured_year;
   
    Date rented_date;
    Date return_date;
    
};

void welcome()
{
    cout<<"       ___________________________        "<<endl;
    cout<<"------- Welcome To Our Cab1 Rental -------"<<endl;
    cout<<"       ---------------------------        "<<endl;
    cout<<"             _____         " << endl;
    cout<<"          __/_____\\__     " << endl;
    cout<<"         |  _     _  |     " << endl;
    cout<<"         '-(o)---(o)-'     " << endl<<endl;
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
     cout <<"--- ALL VEHICLES ---"<<endl;
     for (int i=0; i<vehicles.size();i++)
     {
         cout<<" vehicle"<<i+1<<endl;
         cout<<"vehicle model :"<<vehicles[i].brand_or_model<<endl;
         cout<<"plate number :"<<vehicles[i].plate_number<<endl;
         cout<<"Status: "<<(vehicles[i].available ? "Available" : "Booked")<<endl;
                 cout<<"----------------------"<<endl;     }
        
        
    }
    
    void delete_vehicle(string plate)
        {
            int v = search_vehicle(plate);
            if (v == -1)
            {
                cout << "Vehicle not found!\n";
                return;
            }

            // Remove booking if exists
            for (int i = 0; i < bookings.size(); i++)
            {
                if (bookings[i].plate_number == plate)
                {
                    bookings.erase(bookings.begin() + i);
                    break;
                }
            }

            vehicles.erase(vehicles.begin() + v);
            cout << "Vehicle deleted successfully!\n";
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
    
    
    void return_vehicle(string plate_number)
     {
         int vehicle = search_vehicle(plate_number);
         int booking = search_booking(plate_number);

         if (vehicle != -1) vehicles[vehicle].available = true;
         if (booking != -1) bookings.erase(bookings.begin() + booking);

         cout << "Vehicle returned successfully!\n";
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

    void display_bookings()
       {
        cout <<"--- ALL BOOKED CARS---"<<endl;
        for (int i=0; i<bookings.size();i++)
        {
            cout<<" booking"<<i+1<<endl;
            cout<<"first name :"<<bookings[i].F_name<<endl;
            cout<<"plate number :"<<bookings[i].plate_number<<endl;
            cout<<"-----------------------------"<<endl;

        }
        }
    
    void delete_booking(string plate)
        {
            int b = search_booking(plate);
            if (b == -1)
            {
                cout << "Booking not found!\n";
                return;
            }

            int v = search_vehicle(plate);
            if (v != -1)
                vehicles[v].available = true;

            bookings.erase(bookings.begin() + b);
            cout << "Booking deleted successfully!\n";
        cout<<"-----------------------------"<<endl;
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
        ofstream vehicle("/Users/" + string(getenv("USER")) + "/Desktop/vehicles.txt");
        ofstream booking("/Users/" + string(getenv("USER")) + "/Desktop/bookings.txt");

        if (!vehicle || !booking)
        {
            cout << "Error opening file!\n";
            return;
        }

        for (auto x : vehicles)
            vehicle << x.plate_number << " " << x.brand_or_model << " "
                    << x.vehicle_type << " " << x.manufactured_year << " "
                    << x.available << endl;

        for (auto x : bookings)
            booking << x.F_name << " " << x.L_name << " "
                    << x.plate_number << " " << x.phone_number << endl;

        vehicle.close();
        booking.close();

        cout << "Data saved to Desktop successfully!\n";
    

            cout<<"-----------------------------"<<endl;
        }


    };
bool valid_phone(const string& phone)
{
    if (phone.length() != 10) return false;
    for (char c : phone)
        if (!isdigit(c)) return false;
    return true;
}

// Validate date (no leap year)
bool valid_date(const Date& date)
{
    if (date.month < 1 || date.month > 12) return false;
    int days_in_months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (date.day < 1 || date.day > days_in_months[date.month - 1]) return false;
    return true;
}

    /* ---------- BILLING ---------- */
int days_in_month(int month)
{
    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    return days[month - 1];
}

int date_to_days(Date date)
{
    int total = 0;

    // years → assume every year = 365 days
    total += (date.year - 1) * 365;

    // months
    for (int month = 1; month < date.month; month++)
        total += days_in_month(month);

    // days
    total += date.day;

    return total;
}


float calculate_bill(const Booking &booking)
{
    int start_days = date_to_days(booking.rented_date);
    int end_days   = date_to_days(booking.return_date);

    int days = end_days - start_days +1 ;

    if (days <= 0)
    {
        cout << "Invalid rental period!\n";
        return 0;
    }

    float pricePerDay = 2000.0f;
    float totalBill = days * pricePerDay;

    cout << "Rental Days: " << days << endl;
    cout << "Total Bill: " << totalBill << " ETB" << endl;

    return totalBill;
   
}



    /* ---------- MENU & MAIN ---------- */

    void menu(Cab_rental_system &cab_rental_system)
{
        int menu_number;
        cout<<"====MENU===="<<endl;
        cout<<"1, Add A Vehicle "<<endl;
        cout<<"2, Update Vehicle Information"<<endl;
        cout<<"3, Cab Booking "<<endl;
        cout<<"4, Return Booked Vehicle "<<endl;
        cout<<"5, Update Booking"<<endl;
        cout<<"6, Delete a Registered Vehicle"<<endl;
        cout<<"7, Delete Booking"<<endl;
        cout<<"8, DISPLAY ALL BOOKINGS"<<endl;
        cout<<"9, DISPLAY ALL VEHICLES"<<endl;
        cout<<"10, Search Booking"<<endl;
        cout<<"11, Search Vehicle"<<endl;
        cout<<"12, Sort Vehicles"<<endl;
        cout<<"13, Sort Bookings"<<endl;
        cout<<"14, Calculate Bill"<<endl;
        cout<<"15, Save Data"<<endl;
        cout<<"0, EXIT..."<<endl;
        cout<<"-->";
        
        cout<<"enter your choice"<<endl;
        cout << "--> ";
        cin >> menu_number;
        
        
        
        if (menu_number == 1)
            
            {
            {
                int vehicle_size;
                cout<<"--ADDING VEHICLE-- "<<endl;
                cout<<"how many vehicles you want to add"<<endl;
                cout<<"-->";
                cin>>vehicle_size;
                
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
                cout<<"-----------------------------"<<endl;
                }
                }
        else if (menu_number == 2)
        {
            string plate; cout << "Plate_number: "<<endl;
            cout << "--> ";
            cin >> plate;
            cab_rental_system.update_vehicle(plate);
            cout<<"-----------------------------"<<endl;
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
            // Phone number input
            cout << "Phone_number (10 digits): " << endl;
            cout << "--> ";
            cin >> booking.phone_number;
            while (!valid_phone(booking.phone_number))
            {
                cout << "Invalid phone number! Enter exactly 10 digits." << endl;
                cout << "--> ";
                cin >> booking.phone_number;
                
            }

            // Start date input
            cout<<"Plate number: "; cin>>booking.plate_number;
                    cout<<"Address: "; cin>>booking.address;
            cout << "Start_date (dd mm yyyy): " << endl;
            cout << "--> ";
            cin >> booking.rented_date.day >> booking.rented_date.month >> booking.rented_date.year;
            while (!valid_date(booking.rented_date))
            {
                cout << "Invalid date! Enter again (dd mm yyyy): " << endl;
                cout << "--> ";
                cin >> booking.rented_date.day >> booking.rented_date.month >> booking.rented_date.year;
            }

            // Return date input
            cout << "Return_date (dd mm yyyy): " << endl;
            cout << "--> ";
            cin >> booking.return_date.day >> booking.return_date.month >> booking.return_date.year;
            while (!valid_date(booking.return_date))
            {
                cout << "Invalid date! Enter again (dd mm yyyy): " << endl;
                cout << "--> ";
                cin >> booking.return_date.day >> booking.return_date.month >> booking.return_date.year;
            }

            
            cab_rental_system.book_vehicle(booking);
            cout<<"-----------------------------"<<endl;
        }
        else if (menu_number == 4)
        {
            string plate; cout << "Plate_number: "<<endl;
            cout << "--> ";
            cin >> plate;
            cab_rental_system.return_vehicle(plate);
            cout<<"-----------------------------"<<endl;
        }
        
        else if (menu_number == 5)
        {
            string plate; cout << "Plate_number: "<<endl;
            cout << "--> ";
            cin >> plate;
            cab_rental_system.update_booking(plate);
            cout<<"-----------------------------"<<endl;
        }else if (menu_number == 6)
        {
            string plate; cout << "Plate: ";
            cin >> plate;
            cab_rental_system.delete_vehicle(plate);
            cout<<"-----------------------------"<<endl;
        }
        else if (menu_number == 7)
        {
            string plate; cout << "Plate: ";
            cin >> plate;
            cab_rental_system.delete_booking(plate);
            cout<<"-----------------------------"<<endl;
        }
        else if (menu_number == 8){
            cab_rental_system.display_bookings();
            cout<<"-----------------------------"<<endl;
        }
        else if (menu_number == 9){
            cab_rental_system.display_vehicle();
        
            cout<<"-----------------------------"<<endl;
        }
        else if (menu_number == 10)
        {
            string plate;
            cout << "Plate number: ";
            cin >> plate;

            int i = cab_rental_system.search_booking(plate);
            if (i != -1)
            {
                Booking booking = cab_rental_system.bookings[i];
                int v = cab_rental_system.search_vehicle(booking.plate_number);
                string model;
                if (v != -1) {
                    model = cab_rental_system.vehicles[v].brand_or_model;
                } else {
                    model = "Unknown";
                }


                cout << "Plate Number: " << booking.plate_number << endl;
                cout << "Vehicle Model: " << model << endl;
                cout << "Total Bill: " << calculate_bill(booking) << " ETB" << endl;
            }
            else
            {
                cout << "Booking not found!" << endl;
            }
            cout<<"-----------------------------"<<endl;
        }

        else if (menu_number == 11)
        {
            string plate; cout << "Plate_number: "<<endl;
            cout << "--> ";
            cin >> plate;
            int i = cab_rental_system.search_vehicle(plate);
            if (i != -1)
            {
                cout << "Vehicle FOUND:\n";
                cout << "plate :"<<cab_rental_system.vehicles[i].plate_number <<endl;
                cout <<"model :" <<cab_rental_system.vehicles[i].brand_or_model << endl;
            }
            else
            {
                cout << "Vehicle NOT found!\n";
            }
            cout<<"-----------------------------"<<endl;
            
        }
        
        else if (menu_number == 12)
        {
            int sort;
            cout << "1 Ascending  2 Descending: ";
            cin >> sort;
            cab_rental_system.sort_vehicles(sort == 1);
            cout << "Vehicles sorted successfully!\n";
            cout<<"-----------------------------"<<endl;
        }

        else if (menu_number == 13)
        {
            int sort;
            cout << "1 Ascending  2 Descending: ";
            cin >> sort;
            cab_rental_system.sort_bookings(sort == 1);
            cout << "Bookings sorted successfully!\n";
            cout<<"-----------------------------"<<endl;
        }

        else if (menu_number == 14)
        {
            string plate;
            cout << "Plate_number: " << endl;
            cout << "--> ";
            cin >> plate;

            int i = cab_rental_system.search_booking(plate);
            if (i != -1)
            {
                calculate_bill(cab_rental_system.bookings[i]); // prints days + total
            }
            else
                cout << "Booking not found!\n";
            cout<<"-----------------------------"<<endl;
        }


        else if (menu_number == 15)
            cab_rental_system.save_data();
        else if (menu_number == 0)
        {
            cout << "Exiting program..." << endl;
            exit(0);
        }
        else
        {
            cout << "Invalid choice! Try again.\n";
            cout<<"-----------------------------"<<endl;
        }
        }
        
        
        int main()
        {
            welcome();
            Cab_rental_system cab_rental_system;
            
            
            while (true)
            {
                menu(cab_rental_system);
            }
        }
    
