// My name: Anh Ho
// Class: CS202
// Project: Programming Assignment 1
// File name: header.h
// This file contains 5 classes:
// 1. Location class is a base of smart derivces.
// 2. Smart_Devices is a base of 3 devices. the three other class for 3 types of devices will be driverd from smart devices class.
#ifndef SMARTDEVICES_H
#define SMARTDEVICES_H
#include <iostream>
#include <cstring>

using namespace std;
const int STR_SIZE = 256; // the size of character allows to input
const int MAXCANS = 2; // each truck can pick up 2 cans. Reaching to 2  means the truck is full.
//loc : location
class location {
	public:
		location();
		location(char * t_street, char * t_zip);
		location(const location & to_copy); // copy constructor
		~location();
		
		void copy_address(char * new_street, char * new_zip);
		void change_address(char * new_street, char * new_zip);
		void add_address(char * new_street, char * new_zip);
		void remove_address();

		void input_loc();
		void display_loc() const;

	protected:
		char * street;
		char * zip;
};


//sd : smart devices
class Smart_Devices: public location 
{
	public:
		Smart_Devices(); // default constructor
		Smart_Devices(const Smart_Devices& to_copy); // copy constructor
		Smart_Devices(const location & to_copy);
		Smart_Devices(int id, char * message, const location & source); // parameter constructor 
		~Smart_Devices(); //destructor

		int  getID();
		bool match_id(int source); // try to find a device matching with the id.
		
		void set_id(int id);
		void set_message(char * message); //set a new message;
		void change_message(char * new_message); // change a new message
		bool find_by_zipcode(char * find_zipcode); // this finds smart devices having the same zipcode

		void input_sd();
		void display_sd() const;

	protected:
		int id_devices;
		char * message_devices;

};

class Smart_Car: public Smart_Devices
{
	public:
		Smart_Car(); // default constructor
		Smart_Car(const Smart_Car & to_copy);// copy constructor
		//Smart_Car(const Smart_Devices & to_copy); 
		Smart_Car(string, int, const Smart_Devices & source); //inital list
		~Smart_Car();

		
		void set_destination(string input_destination);
		void check_power(); // check the powers in order to let users know when they need to charge the car
							// this function will work when searching a car by id.
		bool change_area(); // the users ask to move into different area. 

		void input_car();  // getting data from this class and plus more from base.
		void display_car() const;             //display all info
		void remove_car();
		
	
	protected:
		int battery;
		string destination;
};


class Garbage_Truck: public Smart_Devices
{
	public:
		Garbage_Truck();
		Garbage_Truck(const Garbage_Truck & to_copy); //copy constructor
		// Garbage_Truck(Smart_Devices & source);
		Garbage_Truck(string , string, int, const Smart_Devices & source);
		~Garbage_Truck();
		int getNumOfCans(); // get the number of cans that the truck has picked up.
		string getStatus() const;
		void change_status(string input);
		
		void schedule_pickup(char * schedule);
		bool check_status(); // this function to check any truck is ready to pick up or not
		
		int increase_cans(); //inscreasing number of cans when already picking up trash.
	
  		void input_truck();
		void display_truck() const;             //display all info
		void remove();

	protected:
		string schedule; // using string type as required 
		string status_truck; // ready or not ready
		int numberofcans; // the number of cans make a truck full 
};

class Garbage_Can: public Smart_Devices
{
	public:
		Garbage_Can();
		Garbage_Can(const Garbage_Can & input); //copy constructor
		//Garbage_can(Smart_Devices & source);
		Garbage_Can(string , string, const Smart_Devices & source);
		~Garbage_Can();

		string getstatus();

		
		void update_status_type();
		void garbage_status(bool full_status); // when it's full, it communicates w/ truck and give them a location to pick up 
		void need_pickup();
		// -- doing -- //
		bool change_status(string input); // change the status of the trash can

		// --------------//
		void input_can();
		void display_can() const;             //display all info
		void remove_can();

	protected:
		
		string type_trash; // will change the data type to string instead of char later
		string full_status; // return a status of the trash can
};


#endif
