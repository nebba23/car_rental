#include <iostream>
#include <vector>
using namespace std;


struct Vehicle
{
    string plate_number;
    string brand_or_model;
    string vehicle_type;
    int manufactured_year;
    string availability;
};

struct Booking
{
    string F_name;
    string L_name;
    string id_number;
    string license_number;
    string phone_number;
    string vehicle_type;
    string address;
    string rented_date,return_date;
};


vector<Booking>renters;
vector<Vehicle> vehicles;


void welcome()
{
    cout <<"      _____________________________        "<<endl;
    cout<<"------ 🚘Welcome To Our Cab Rental🚘 -------"<<endl;
    cout <<"      -----------------------------         "<<endl;
    cout << "              _____     " << endl;
    cout << "           __/_____\\__     " << endl;
    cout << "          |  _     _  |     " << endl;
    cout << "          '-(o)---(o)-'     " << endl<<endl;
}

void add_vehicle(int vehicle_size)
{
    for(int i=0;i<vehicle_size;i++)
    {
        Vehicle vehicle;
        cout <<"* Add plate number \n";
        cout<<"-->";
        cin>>vehicle.plate_number;
        cout <<"*Enter a brand or a model of the car \n";
        cout<<"-->";
        cin>>vehicle.brand_or_model;
        cout <<"* Enter a vehicle type\n";
        cout<<"-->";
        cin>>vehicle.vehicle_type;
        cout <<"* Enter the manufactured year\n";
        cout<<"-->";
        cin>>vehicle.manufactured_year;
        vehicles.push_back(vehicle);
       
    }
    cout<<"---Vechile Added Successfully---\n";
}
    
    void register_customer()
    {
        cout <<"  ";
            Booking customer;
            cout <<" *Enter First Name \n";
            cout<<"-->";
            cin>>customer.F_name;
            cout <<" *Enter Last Name \n";
            cout<<"-->";
            cin>>customer.L_name;
            cout <<" *Enter ID Number \n";
            cout<<"-->";
            cin>>customer.id_number;
            cout <<" *Enter a license Number \n";
            cout<<"-->";
            cin>>customer.license_number;
            cout<<" *Enter a Phone Number \n";
            cout<<"-->";
            cin>>customer.vehicle_type;
            cout<<" *Enter the vehicle type \n";
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
            renters.push_back(customer);
        
    }

    
    void display_customers()
    {
        cout <<"--All the customers you have--"<<endl;
        cout <<"|"<<"first_name"<<"\t"<<"|"<<"last_name"<<"\t"<<"|"<<"id number"<<"\t"<<"|"<<"license_number"<<"\t"<<"|"<<"vehicle_type"<<"\t"<<"|"<<"phone_number"<<"\t"<<"|"<<"address"<<"\t"<<"rented_date"<<"\t"<<"|"<<"returned_date"<<endl;
        for(int i=0;i<renters.size();i++)
        {
            cout<<"|"<<renters[i].F_name<<"\t"<<"\t"<<"|"<<renters[i].L_name<<"\t"<<"\t"<<"|"<<renters[i].id_number<<"\t"<<"\t"<<"|"<<renters[i].license_number<<"\t"<<"\t"<<"|"<< renters[i].vehicle_type<<"\t"<<"\t"<<"|"<<renters[i].phone_number<<"\t"<<"\t"<<"|"<<renters[i].address<<"\t"<<"\t"<<"|"<<renters[i].rented_date<<"\t"<<"\t"<<"|"<<renters[i].return_date<<endl;
        }
    }
    
    void display_vehicle()
    {
        cout <<"--All the vehicles you have--"<<endl;
        cout <<"|"<<"plate_number"<<"\t"<<"|"<<"brand_or_model"<<"\t"<<"|"<<"vehicle_type"<<"\t"<<"|"<<"plate_number"<<"\t"<<"availability"<<endl;
        for(int i=0;i<vehicles.size();i++)
        {
            cout<<"|"<<vehicles[i].plate_number<<"\t"<<"\t"<<"\t"<<"\t"<<"|"<<vehicles[i].brand_or_model<<"\t"<<"\t"<<"\t"<<"\t"<<"|"<<vehicles[i].vehicle_type<<"\t"<<"\t"<<"\t"<<"\t"<<"|"
            <<endl;
        }
    }
    
    void menu ()
    {
        int menu_number;
        cout<<"====MENU===="<<endl;
        cout<<"1, ADD A VEHICLE "<<endl;
        cout<<"2, REGISTER A CUSTOMER "<<endl;
        cout<<"3, DISPLAY ALL CUSTOMERS"<<endl;
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
            add_vehicle(vehicle_size);
        }
        else if (menu_number == 2)
        {
         
            cout<<" --REGISTERING CUSTOMER--"<<endl;
            
            register_customer();
        }
        else if (menu_number==3)
        {
            display_customers();
        }
        else if (menu_number==4)
        {
            display_vehicle();
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
        while (true)
        {
            menu();
        }
        
        return 0;
    }

