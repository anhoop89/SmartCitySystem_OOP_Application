// My name: Anh Ho
// Class: CS202
// Project: Programming Assignment 1
// File name: main.cpp
// this cpp is to set up testing class that works or not. This is also an interface with users.
// it also has a note here to keep track of what i need to do
// helps me not to feel overwheeled. 
#include "header.h"
#include "nodecar.h"
#include "nodetruckcan.h"
#include <vector>
#include <iostream>

using namespace std;    

int main(){
	Car_Management car;
	Truck_List truck;
	Can_Management can;
	int select = 0;
	do {
		cout << "\n░░░░░░░░ WELCOME TO THE SMART CITY APPLICATION! ░░░░░░░░░";
		cout << "\n    We have currently 3 smart devices in our system: ";
		cout << "\n\t [1] SMART CAR system.";
		cout << "\n\t [2] GARBAGE TRUCK system.";
		cout << "\n\t [3] GARBAGE CAN system.";
		cout << "\n\t ***[0] Quite the application! ";
		cout << "\n\n\t Which device do you want to check today? ";
		cout << "\n\t ► Please enter a number: ";
		cin >> select;
		cin.ignore();
		cout << endl;

		if (select == 1) 
		{			
			int number = 0; // Smart Can system!
			do {	
				car.asking();
				cin >> number;
				cin.ignore();
				
				if (number != 0)
				{
					switch (number){
					case 1: car.add_car(); // add function 
						break;
					case 2: car.searchcar_byid(); // search a car by id
						break;
					case 3: car.display_all(); // display all car in each location
						break;
					case 4: car.removecar_byid(); // remove a car by ID.
						break;
					case 5: car.remove_all_cars(); // remove all the cars 
						break;
					}
					cout << "\n\tPress 'enter' key to get back to the car menu " << endl;
					cin.ignore();
				} else 
				{
					cout << "\n\tThe car syterm is closing! ☺☺☺\n";
					cout << "    --- Please hit 'enter' key to continue! ---";
					cin.ignore();
				}	
			} while (number != 0); 
		}
		if (select == 2) // Garbage Truck system!
		{ 
			int number = 0;
			do {	
				truck.asking();
				cin >> number;
				cin.ignore();
		
				if (number != 0)
				{
					switch (number){
					case 1: truck.insertTruck(); // add function 
						break;
					case 2:  truck.find_readytruck(); // find ready truck
						break;
					case 3: truck.display(); // display all car in each location
						break;
					case 4:  truck.remove_by_status();// remove a car by the status
						break;
					case 5:  truck.remove_node();
						break;
					}
					cout << "\n\tPress 'enter' key to get back to the car menu " << endl;
					cin.ignore();
				} else 
				{
					cout << "\n\tThe truck syterm is closing! ☺☺☺\n";
					cout << "    --- Please hit 'enter' key to continue! ---";
					cin.ignore();
				}	
			} while (number != 0); 
		} 
		if (select == 3) // Garbage Can system!
		{	
			int number = 0;
			do {	
				can.asking();
				cin >> number;
				cin.ignore();
				
				if (number != 0)
				{
					switch (number){
					case 1: can.insertcans(); // add function 
						break;
					case 2:  can.findcan_byid(truck);// search a car by id and ask to pick if being full.
						break;
					case 3: can.display(); // display all car in each location
						break;
					case 4: can.change_status_type();// update stautus and type of trash by status "unready"
						break;
					case 5:  can.remove_all();
						break;
					}
					cout << "\n\tPress 'enter' key to get back to the car menu " << endl;
					cin.ignore();
				} else 
				{
					cout << "\n\tThe car syterm is closing! ☺☺☺\n";
					cout << "    --- Please hit 'enter' key to continue! ---";
					cin.ignore();
				}	
			} while (number != 0); 
		}
		if (select == 0) 
			cout << "\n\tThe application is closing! ☺☺☺\n\n";
	} while (select != 0);
	
}
