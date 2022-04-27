// My name: Anh Ho
// Class: CS202
// Project: Programming Assignment 1
// File name: smartcars.cpp
// this cpp will design all function of car list, car management
// it helps me keep track of adding node and checking data structures of array of LLL for smart car
#include "header.h"
#include "nodecar.h"


//Display all data for car in each location! 
void Car_List::display()
{
	if (!listHead){
		cout << "\n***Unformately, we don't have a data to display! Please add a car into system.\n";
		return;
	}
	else displayList(listHead);
}

void Car_List::displayList(node_car * aNode)
{
if (!aNode)
	//cout << "\n\tThe list is empty from car_list!\n";
	return;
else {
		aNode->get_data()->display_car();
		displayList(aNode->go_next());
	}
}

// ================== CAR DESTINATION ============//

Car_Management::Car_Management()
{
	area = new Car_List*[num_area];
	for (int i = 0; i < num_area; i++){
		area[i] = new Car_List;
	}
	
}

Car_Management::~Car_Management(){
	for (int i = 0; i < 3; i++){
		delete area[i];
	}
	if (area){
		delete [] area;
	}
}
void Car_Management::add_car(){	// function starts adding data into a car node and array of LLL.
	cout << "\nBefore starting a good trip, we need to collect some infomation for a car!";
	cout << "\n\tAdding a car into the system.";
	int choice ;
	do {
		Smart_Car * tempcar = new Smart_Car();
		tempcar->input_car();
		int select;
		// trying to create a new node containing smart car data.
		node_car * newnode = new node_car;
		newnode->get_data() = tempcar;
		newnode->go_next() = nullptr;

		cout << "\nWe have 3 cities on systerm. Where do you want to go?\n";
		cout << "\t[1] Portland.\n\t[2]Beaverton\n\t[3]Hillsboro\n";
		cout << "\tPlease enter a number in {1,2,3}: ";
		cin >> select; 
		while (select < 0 || select > 3 ) {
			cout << "\tPlease enter a number in {1,2,3}: ";
			cin >> select;
		}
		switch(select){
			case 1:	area[0]->insertCarNode(newnode);
					cout << "\n\t**Your car will be going to Portland area now!\n";
					break;
			case 2: area[1]->insertCarNode(newnode);
					cout << "\n\t++Your car will be going to Beaverton area now!\n";
					break;
			case 3: area[2]->insertCarNode(newnode);
					cout << "\n\t--Yourr car will be going to Hillsboro area now!\n";
					break;
		}
		// Car_List is a list of all the node cars
		cout << "\nTo stop adding cars for checking!\nPress '0' to stop or Any number to continue adding a car: ";
		cin >> choice;
		cin.ignore();

	} while (choice != 0);
	
	
} 

// Find a car by id recursively
 bool Car_List::findcar_byid(node_car * head, int id) 
 {
	if (!head)
		return false;
	if (head->get_data()->match_id(id)){ // call function from a base ( smart devices)
		cout << "\nWe found your car by id!\n";
		head->get_data()->display_car(); // display car information
		head->get_data()->check_power(); // check power
		return true;
	} 
	else 
		findcar_byid(head->go_next(), id);	
	return false;	
 }

void Car_Management::searchcar_byid() 
{
	int id = 0, i = 0;
	bool check = false;
	cout << "\nWould you like to search car by ID?\n\tThe ID car is: ";
	cin >> id;
	cin.ignore();
	for (i = 0; i < 3; i++) {
		check = area[i]->findcar_byid(area[i]->getHead(), id);
		if (check == true){
			switch (i){
				case 0: cout << "We found the car is in Portland area!\n";
						break;
				case 1: cout << "We found the car is in Beaverton area!\n";
						break;
				case 2: cout << "We found the car is in Hillsboro area!\n";
						break;
			}
    	}

	}
}


//------Remove cars by Recursion-----------//
// Wrapper function to remove cars recursively 
void Car_List::remove_node(){
    if (!listHead){
		cout << "\nThe car list is empty!\n";
		return;
	}       
    remove_node(listHead);
}
void Car_List::remove_node(node_car *& head)
{
	if (!head)
		return;
	else {
		if (head->go_next() == nullptr) // delete the last node;
		{
			delete head; 
			head = nullptr;
			listTail = nullptr;
			return;
		}
		// if not,delete any position 
		node_car * temp = head;
		head = head->go_next();
		delete temp;
		temp = nullptr;
		remove_node(head); 
	}
}
void Car_Management::remove_all_cars(){
  for (int i = 0; i < 3; i++){
        area[i]->remove_node();
    }
}
//----------------------------------------//


//----------- remove a car by ID ---------//
bool Car_List::findcar_remove(int id) 
{
	bool check = false;
	check = recur_find_remove(listHead, id);
	return check;
}

bool Car_List::recur_find_remove(node_car *& head, int id) {
	if (!head)
		return false;
	
	if (head->go_next() == nullptr) { // only one node in the list 
		if (head->get_data()->match_id(id))
		{
			delete listHead;
			listHead = nullptr;
			listTail = nullptr;
			return true;
		}
	} else {
		if (head->get_data()->match_id(id)) { // at the beignning
			node_car * temp = head;
			head = head->go_next();
			delete temp;
			temp = nullptr;
			return true;		
		}

		// delete at the tail
		if (head->go_next() == listTail && head->go_next()->get_data()->match_id(id)){ // check tail first
			delete listTail;
			listTail = head;
			head->go_next() = nullptr;
			listTail->go_next() = nullptr;
			return true;
		}

		node_car * prev = head; 
		node_car * cur = head->go_next(); 

		if (cur->get_data()->match_id(id)){ // remove anywhere between head and tail
			prev->go_next() = cur->go_next(); 
			delete cur;
			cur = nullptr;
			return true;
		} 
		recur_find_remove(head->go_next(), id);	
	}
	
	return false;	
}

void Car_Management::removecar_byid()
{
	int id = 0, i = 0;
	bool check = false;
	cout << "\n The ID device you want to remove:  ";
	cin >> id;
	cin.ignore();
	for (i = 0; i < 3; i++) {
		check = area[i]->findcar_remove(id);
		if (check) {
			cout << "Sucessfully removed a car with ID #"<<id << endl;
			return;
		}			
	}
	if (check == false) cout << "\nWe could not find any ID #" << id << " to remove! \n";
}
//----------------------------------------//
void Car_Management::display_all(){
	cout << "\n♦ Car info in Portland area: \n";
	area[0]->display(); // display function from car list class
	cout << "\n♦ Car info in Beaverton area: \n";
	area[1]->display();
	cout << "\n♦ Car info in Hillsboro area: \n";
	area[2]->display();
}

void Car_Management::asking(){ // menu for users - smart cars
	int number = 0;
	cout << "**********************▲○■*********************\n";
	cout << "\tWelcome to Smart Car systerm!\n"; 
	cout << "\n\t[1] Add car info into the system";
	cout << "\n\t[2] Search a car info by license plate in the system.";
	cout << "\n\t[3] Display all the car that is currently in each area";
	cout << "\n\t[4] remove car by ID device                                 ";
	cout << "\n\t[5] remove all the car in the car system";
	cout << "\n\t***[0] Quit the car system!";

	cout << "\n\t► Please enter a number: ";
	return;
}
