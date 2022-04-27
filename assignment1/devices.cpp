// My name: Anh Ho
// Class: CS202
// Project: Programming Assignment 1
// File name: devices.cpp
// this cpp will implement all the member functions from base class and derived class.
// including input data, display, remove, and member functions from the core hierarchy clear
#include "header.h"
#include <iostream>
#include "nodecar.h"
#include <string>
#include <bits/stdc++.h>

using namespace std;
//-------------LOCATION CLASS --------------//

void location::input_loc(){
    cout << "\n\tWhere is your current location? \n\t► Please enter street: "; 
    street = new char[STR_SIZE];
    cin.getline(street, STR_SIZE);
    
    cout << "\t► Please enter zipcode: ";
    zip = new char[STR_SIZE];
    cin.getline(zip, STR_SIZE);
} 

void location::display_loc() const{
    cout << "\n=============// DISPLAY //=============== \n\n";
    cout << ">> >> You start a location << <<" << endl;
    cout << "\tStreet: " << street << "\n\tZipcode: "<< zip;      
}


// -------------- SMART DEVICES --------------//

void Smart_Devices::input_sd(){
   
    location::input_loc(); //testing
    cout << "\n\tEach smart device will have their own ID!\n";  
    cout << "\t► Please enter your iD devices: ";
    cin >> id_devices;
    cin.ignore();
    cout << "\tWould you like to leave any note for your smart deivce!\n";  
    cout << "\t► Please enter your note for your devices: ";
    message_devices = new char[STR_SIZE];
    cin.getline(message_devices, STR_SIZE);
   

}

void Smart_Devices::display_sd() const {
    
    location::display_loc(); // testing
    cout << "\n\n>> >> Your smart devices information << << ";
    cout <<"\n\tID Device: " << id_devices;
    cout <<"\n\tThe messages for your device: " << message_devices << endl;
}

bool Smart_Devices::match_id(int source) // function to check whether it matches an ID or not
{
    if ( source == id_devices)
        return true;
    return false;
}
//=======================================//
// ---------- SMART CAR ----------------//

void Smart_Car::input_car() {
    Smart_Devices::input_sd(); // testing 
    cout << "\n\tWe would like to check your car battery first!";
    cout << "\n\t► Please enter car's battery: ";
    cin >> battery;
    cin.ignore();

    cout << "\tDo you want to take a 'control' or use 'autopilot' mode? ";
    cout << "\n\t► Please enter your choice: ";
    getline(cin, destination);

}

void Smart_Car::display_car() const {
    Smart_Devices::display_sd();
    cout << "\n>> >> The car has " << battery << " % of the battery now!\n";
    cout << ">> >> Your car is on " << destination << " mode!" << endl;
}

void Smart_Car::check_power() {
    if (battery > 40  && battery < 60 )
        cout << "\nYour battery is lower than 60%. Please re-charge your car if possible.\n";
    if (battery > 10 && battery < 40 ) 
        cout << "Your battery is lower than 45%. You should re-charge asap.\n";
    if (battery > 80 )
        cout << "Your battery is greater 80%. You're good to go. Drive safely!\n";
    if (battery < 10)
        cout << "your battery is too low! The car will be stopped shortly.\n";
}

//----------GARBAGE TRUCK -------------//

int Garbage_Truck::increase_cans(){
    numberofcans++;
    return numberofcans;
}

int Garbage_Truck::getNumOfCans(){
    return numberofcans;
}
void Garbage_Truck::input_truck(){
    Smart_Devices::input_sd();
    cout << "\n\t► Please enter a schedule for the garbage truck: ";
    getline(cin, schedule);
    cout << "\nNote: Since you add your truck at first, it's always ready to pick up trash!";
    cout << "\n testing status ";
    getline(cin, status_truck);
}

//Function to change the status of the truck when reaching to the capacity of trashcans they collect.
void Garbage_Truck::change_status(string input){
    status_truck = input;
}

void Garbage_Truck::display_truck() const{
    Smart_Devices::display_sd();
    cout << ">> >> The schedule of garbage truck: " << schedule << endl;
    cout << ">> >> Your truck has " << numberofcans << " trash cans now!" << endl;
    if (numberofcans == MAXCANS){
        cout << "\n*** Warning: Your truck is full. Please let the truck go to the trash field!";
        cout << "\nPlease remove the truck by the status." << endl;
    }
    cout << ">> >> Your truck is " << status_truck << " to pick up trash!" << endl;
}


////////////////////////////////////////
//-----------GARBAGE_CAN ------------//

void Garbage_Can::input_can(){
    Smart_Devices::input_sd();
    
    cout << "\nGetting data from Garbage Can!\n ";
    cout << "► Please enter kinds of trash you want to fill today: ";
    getline(cin, type_trash);
      
    do {
        cout << "\nPlease enter a status of your garbage can [full, empty]: ";
        getline(cin, full_status);

        transform (full_status.begin(), full_status.end(), full_status.begin(), [] (unsigned char c) { 
            return  :: tolower(c);  // change all upper to lowercase using STL 
        }); 
    
    } while (full_status != "full" && full_status != "empty");
}

void Garbage_Can::display_can() const {
    Smart_Devices::display_sd();
    cout << endl;
    cout << ">> >> Your trash you was filled today is:  " << type_trash << endl; 
    cout << ">> >> Your trash can has been " << full_status << " !" << endl;
}

void Garbage_Can::update_status_type(){
    string type ="", status = "";
    cout << "► Please enter kinds of trash you want to fill today: ";
    getline(cin, type);
    type_trash = type;
      
    do {
        cout << "\nPlease enter a status of your garbage can [full, empty]: ";
        getline(cin, status);

        transform (status.begin(), status.end(), status.begin(), [] (unsigned char c) { 
            return  :: tolower(c);  // change all upper to lowercase using STL 
        }); 
    
    } while (status != "full" && status != "empty");
    full_status = status;
}