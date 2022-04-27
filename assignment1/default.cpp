// My name: Anh Ho
// Class: CS202
// Project: Programming Assignment 1
// File name: default.cpp
// this cpp will desing for constructors, destructors for all class 
// it helps me keep track of the core of hierarchy 
#include "header.h"
#include "nodecar.h"
#include "nodetruckcan.h"

//-------------LOCATION CLASS --------------//

location::location():street(nullptr), zip(nullptr){

}

location::location(char * t_street, char * t_zip){
    if (t_street){
        street = new char[strlen(t_street)+1];
        strcpy(street, t_street);
    } else street = nullptr;

    if (t_zip){
        zip = new char[strlen(t_zip)+1];
        strcpy(zip, t_zip);
    } else zip = nullptr;
}

location::location(const location & to_copy) {
    if (to_copy.street){
        street = new char[strlen(to_copy.street)+1];
        strcpy(street, to_copy.street);
    } else street = nullptr;

    if (to_copy.zip){
        zip = new char[strlen(to_copy.zip)+1];
        strcpy(zip, to_copy.zip);
    } else zip = nullptr;
}

location::~location(){ // destructor
    delete [] zip;
    zip = nullptr;
    delete [] street;
    street = nullptr;
}


// -------------- SMART DEVICES --------------//

Smart_Devices::Smart_Devices():id_devices(0),message_devices(nullptr)
{}


Smart_Devices::Smart_Devices(const Smart_Devices & to_copy):location(to_copy)
{   if (to_copy.message_devices) {
         message_devices = new char[strlen(to_copy.message_devices) + 1];
	    strcpy(message_devices,to_copy.message_devices);
    } else message_devices = nullptr;
       
    id_devices = to_copy.id_devices;

}

Smart_Devices::Smart_Devices(const location & to_copy):location(to_copy)
{}

Smart_Devices::Smart_Devices(int id, char * message, const location & source):location(source) {
    if (message) {
         message_devices = new char[strlen(message) + 1];
	    strcpy(message_devices,message);
    } else message_devices = nullptr;
       
    id_devices = id;
}
Smart_Devices::~Smart_Devices() {
    delete [] message_devices;
    message_devices = nullptr;
}

int Smart_Devices::getID(){
    return id_devices;
}

//=======================================//
// ---------- SMART CAR ----------------//


Smart_Car::Smart_Car(): battery(0), destination(" ")
{}

Smart_Car::Smart_Car(const Smart_Car & to_copy):Smart_Devices(to_copy)
{
    destination = to_copy.destination;
    battery = to_copy.battery;
}

//Smart_Car::Smart_Car(const Smart_Devices & to_copy), Smart_Devices(to_copy)
//{} 

Smart_Car::Smart_Car(string t_dest, int t_battery, const Smart_Devices & source)
                    :destination(t_dest), battery(t_battery), Smart_Devices(source) 
{}

Smart_Car::~Smart_Car()
{}

// Function to get data
Smart_Car*& node_car::get_data()
{
	return data_car;
}

//========= NODE CAR CLASS ===========//
node_car::node_car(){
	next = NULL;
	data_car =NULL;
}

node_car::node_car(Smart_Car *& data) 
{
	if (data)
	{
		this->data_car = new Smart_Car(*data);
	}
} 

// Copy constructor
node_car::node_car(const node_car& to_copy) 
{
	if (to_copy.data_car)
	{
		this->data_car = new Smart_Car(*to_copy.data_car);
	}
}

// Destructor
node_car::~node_car()
{
	destroy();
}

// Function to destroy node_cars
void node_car::destroy()
{
	if (data_car)
	{
		delete data_car;
		data_car = NULL;
	}
	return;

}

// Function to go to next node
node_car*& node_car::go_next()
{
	return next;
}

void node_car::connect_next(node_car*& connections)
{
	this->next = connections;
	return;
}

void node_car::display_node_car(){
	cout << "\n\nDisplay from node_car!!!\n";
	data_car->display_car();
}

node_car* Car_List::getHead(){
	return listHead;
}

//========== CAR LIST CLASS ============//

Car_List::Car_List(){
	listHead = NULL;
	listTail = NULL;
}
Car_List::~Car_List(){
    delete listHead;
}

void Car_List::insertCarNode(node_car *& aNode){
	// Case empty node
	if (listTail == NULL)
	{
		listHead = aNode;
		listTail = aNode;
	}
	// If not null
	else
	{
		listTail->connect_next(aNode);
		listTail = aNode;
	}
	return;
} 

///////////////////////////////////////////////
//-------------- Garbage Truck -------------//
Garbage_Truck::Garbage_Truck():schedule(" "), status_truck("ready"), numberofcans(0)
{}

Garbage_Truck::Garbage_Truck(const Garbage_Truck & to_copy):Smart_Devices(to_copy) {
    schedule = to_copy.schedule;
}

Garbage_Truck::Garbage_Truck(string t_schedule, string status, int number, const Smart_Devices & source)
                :Smart_Devices(source)
{
    schedule = t_schedule;
	status_truck = status;
	numberofcans = number;
    
}

Garbage_Truck::~Garbage_Truck() 
{}

string Garbage_Truck::getStatus() const {
	return status_truck;
}

//========= NODE TRUCK CLASS ===========//
node_truck::node_truck(){
	next = nullptr;
	data_truck = nullptr;
}

node_truck::node_truck(Garbage_Truck *& data) 
{
	if (data)
	{
		this->data_truck = new Garbage_Truck(*data);
	}
} 

// Copy constructor
node_truck::node_truck(const node_truck& to_copy) 
{
	if (to_copy.data_truck)
	{
		this->data_truck = new Garbage_Truck(*to_copy.data_truck);
	}
}

// Destructor
node_truck::~node_truck()
{
	destroy();
}

// Function to destroy node_trucks
void node_truck::destroy()
{
	if (data_truck)
	{
		delete data_truck;
		data_truck = NULL;
	}
	return;

}
// Function to destroy node
void node_truck::delete_data()
{
	if (data_truck)
	{
		delete data_truck;
		data_truck = NULL;
	}
	return;
}
void Truck_List::append(Garbage_Truck* item)
{
	node_truck* new_node = new node_truck(item);

	if (!rear)
	{
		rear = new_node;
		rear->go_next() = new_node;
	}
	else
	{
		node_truck* head = rear->go_next();
		rear->go_next() = new_node;
		rear = new_node;
		rear->go_next() = head;
	}
	return;
}


// Function to go to next node
node_truck*& node_truck::go_next()
{
	return next;
}
// Function to get data from node
Garbage_Truck *& node_truck::get_data(){
    return data_truck;
}

void node_truck::connect_next(node_truck*& connections)
{
	this->next = connections;
	return;
}

void node_truck::display(){
	cout << "\n\nDisplay from node_car!!!\n";
	data_truck->display_truck();
}

node_truck* Truck_List::getRear(){
	return rear;
}

// --------- TRUCK LIST ---------------//

Truck_List::Truck_List():rear(nullptr)
{}

Truck_List::~Truck_List(){
    if (rear)
		delete rear;
	rear = nullptr;
}

///////////////////////////////////////
//-----------GARBAGE_CAN ------------//

Garbage_Can::Garbage_Can(): type_trash(" "), full_status(" ") 
{}

Garbage_Can::Garbage_Can(const Garbage_Can & to_copy):Smart_Devices(to_copy) {
  
        type_trash = to_copy.type_trash;
        full_status = to_copy.full_status;
}   
Garbage_Can::Garbage_Can(string type, string status,const Smart_Devices & source) 
            :type_trash(type),full_status(status), Smart_Devices(source)
{}

Garbage_Can::~Garbage_Can(){
}

string Garbage_Can::getstatus()
{
	return full_status;
}

// ------------------------------CAN MANAGEMENT ---------------------//
Can_Management::Can_Management(){

}

Can_Management::~Can_Management(){
}
