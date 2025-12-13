#include <iostream>
#include <vector>
using namespace std;


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
    string F_name;
    string L_name;
    string license_number;
    string phone_number;
    string plate_number;
    string address;
    string rented_date,return_date;
};

class Cab_rental_system
{
    vector<Vehicle> vehicles;
    vector<Booking> bookings;
    
    public:void add_vehicle (string plate_number,string brand_or_model,string vehicle_type,bool available,string manufactured_year)
    {
        Vehicle vehicle;
        vehicle.plate_number=plate_number;
        vehicle.brand_or_model=brand_or_model;
        vehicle.vehicle_type=vehicle_type;
        vehicle.manufactured_year=manufactured_year;
        vehicle.available=available;
        vehicles.push_back(vehicle);
    }
    
    public:void display_vehicle()
    {
        
        cout <<"--All the vehicles you have--"<<endl;
        cout <<"|"<<"plate_number"<<"\t"<<"|"<<"brand_or_model"<<"\t"<<"|"<<"vehicle_type"<<"\t"<<"|"<<"plate_number"<<"\t"<<"availability"<<endl;
        for(int i=0;i<vehicles.size();i++)
        {
            cout<<"|"<<vehicles[i].plate_number<<"\t"<<"\t"<<"\t"<<"\t"<<"|"<<vehicles[i].brand_or_model<<"\t"<<"\t"<<"\t"<<"\t"<<"|"<<vehicles[i].vehicle_type<<"\t"<<"\t"<<"\t"<<"\t"<<"|"
            <<endl;
        }
    }
    
    public:void display_bookings()
    {
        cout <<"--- ALL BOOKED CARS---"<<endl;
        for (int i=0; i<bookings.size();i++)
        {
            cout<<"first name :"<<bookings[i].F_name<<endl;
            cout<<"plate number :"<<bookings[i].plate_number<<endl;
            
        }
    }
    
    
    public:void book_vehicle(string F_name,string L_name,string license_number,string plate_number,string address,string phone_number)
    {
        int vehicle_index=search_vehicle(plate_number);
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
        Booking book;
        book.F_name=F_name;
        book.L_name=L_name;
        book.license_number=license_number;
        book.plate_number=plate_number;
        book.address=address;
        book.phone_number=phone_number;
        bookings.push_back(book);
    }
    
    public:void return_vehicle (string plate_number )
    {
        int vehicle_index=search_vehicle(plate_number);
        if (vehicle_index==-1)
        {
            cout <<"plate number doesnot exist!!!"<<endl;
            return ;
        }
        vehicles[vehicle_index].available=true;
        
        int booking_index=search_booking( plate_number);
        if (booking_index==-1)
        {
            cout <<"booking doesnot exist!!!";
            return ;
        }
        else
        {
            bookings.erase(bookings.begin() + booking_index);
        }
    }
    
    int search_vehicle(string plate_number)
    {
        for (int i=0;i<vehicles.size();i++)
        {
            if (vehicles[i].plate_number==plate_number)
            {
                return i;
            }
        }
        return -1;
    }
    
    int search_booking (string plate_number)
    {
        for (int i=0;i<bookings.size();i++)
        {
            if (bookings[i].plate_number==plate_number)
            {
                return i;
            }
        }
        return -1;
    }
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

void add_vehicle(int vehicle_size,Cab_rental_system cab_rental_system)
{
    for(int i=0;i<vehicle_size;i++)
    {
        string plate_number ,brand_or_model ,manufactured_year,vehicle_type;
        cout<<" * Add plate number \n";
        cout<<"-->";
        cin>>plate_number;
        cout<<" *Enter a brand or a model of the car \n";
        cout<<"-->";
        cin>>brand_or_model;
        cout<<" * Enter a vehicle type\n";
        cout<<"-->";
        cin>>vehicle_type;
        cout<<" * Enter the manufactured year\n";
        cout<<"-->";
        cin>>manufactured_year;
        cab_rental_system.add_vehicle( plate_number,  brand_or_model,  vehicle_type, true ,  manufactured_year);
    }
    cout<<"---Vechile Added Successfully---\n";
}
    
    void booking_cab(Cab_rental_system cab_rental_system)
    {
        cout <<"  ";
            Booking customer;
            cout <<" *Enter First Name \n";
            cout<<"-->";
            cin>>customer.F_name;
            cout <<" *Enter Last Name \n";
            cout<<"-->";
            cin>>customer.L_name;
            cout <<" *Enter a license Number \n";
            cout<<"-->";
            cin>>customer.license_number;
            cout<<" *Enter a plate number \n";
            cout<<"-->";
            cin>>customer.plate_number;
            cout<<" *Enter the phone number\n";
            cout<<"-->";
            cin>>customer.phone_number;
            cout <<" *Enter an Address \n";
            cout<<"-->";
            cin>>customer.address;
            cout<<"* Enter the start date  \n";
            cout<<"-->";
            cin>>customer.rented_date;
            cout<<"*Enter the return date\n";
            cout<<"-->";
            cin>>customer.return_date;
        cab_rental_system.book_vehicle(customer.F_name, customer.L_name, customer.license_number, customer.plate_number, customer.address, customer.phone_number);
        
    }
    
void book_and_return(Cab_rental_system cab_rental_system)
{
    int input ;
    cout <<"1, BOOK A VEHICLE"<<endl;
    cout<<"2,retuen a vehicle"<<endl;
    cin >> input;
    if (input == 1)
    {
        booking_cab(cab_rental_system);
    }
    else if (input ==2)
    {
        string plate_number;
        cout <<" enter plate number "<<endl;
        cab_rental_system.return_vehicle(plate_number);
    }
}

    void menu (Cab_rental_system cab_rental_system)
    {
        int menu_number;
        cout<<"====MENU===="<<endl;
        cout<<"1, ADD A VEHICLE "<<endl;
        cout<<"2, CAB BOOKING AND RETURNING "<<endl;
        cout<<"3, DISPLAY ALL BOOKINGS"<<endl;
        cout<<"4,DISPLAY ALL VEHICLES"<<endl;
        cout<<"5, EXIT..."<<endl;
        cout<<"-->";
        cin >>menu_number;
        if (menu_number == 1)
        {
            int vehicle_size;
            cout<<"--ADDING VEHICLE-- "<<endl;
            cout<<"how many vehicles you want to add"<<endl;
            cout<<"-->";
            cin>>vehicle_size;
            add_vehicle(vehicle_size,cab_rental_system);
        }
        else if (menu_number == 2)
        {
         
            cout<<" --BOOKING A RETURNING A CAB--"<<endl;
            
            book_and_return(cab_rental_system);
        }
        else if (menu_number==3)
        {
            cab_rental_system.display_bookings();
        }
        else if (menu_number==4)
        {
            cab_rental_system.display_vehicle();
        }
        
        else if (menu_number == 5)
            {
                cout << "Exiting program..." << endl;
                exit(0);
            }
            else
            {
                cout << "Invalid choice! Try again.\n";
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
        
        return 0;
    }

