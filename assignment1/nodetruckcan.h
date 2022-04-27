// My name: Anh Ho
// Class: CS202
// Project: Programming Assignment 1
// File name: nodetruck.h
// still working on 2 more class. One is for circularly linked list of garbage truck for checking purposes
// and the other one is used for managing the trucks in order to communicate with garbage cans.
#ifndef NODETRUCK_H
#define NODETRUCK_H
#include "header.h"
#include <vector>

class node_truck // LLL for the car
{
	public:
		// Default Constructor
		node_truck();
		// Constructor with parameters
		node_truck(Garbage_Truck *& data);
		// Copy Constructor
		node_truck(const node_truck& to_copy);
		// Destructor
		~node_truck();
		// Function to go next node
		node_truck*& go_next();
		// Function to get the data of node
		Garbage_Truck*& get_data();
		// Function to connect next node
		void connect_next(node_truck*& connections);
		// Function to display the node truck
		void display();
		// Function to destroy node
		void destroy();
		// function to delete data
		void delete_data();
       
	protected:
		Garbage_Truck * data_truck; // has a
		node_truck * next;
		
	
};

// truck list is CLL list. it manages all 
class Truck_List{ // Arr of Linked Linked List 
	public:
		Truck_List();
		~Truck_List();
		node_truck * getRear();
	   	void append(Garbage_Truck* item);
	   	void asking();
	    void insertTruck();
		void display();
		bool find_readytruck();
		void remove_node();
		void remove_by_status(); // remove all the truck is unready that means those trucks are leaving. 
	protected:
		void remove_by_status(node_truck *&);

		int remove_by_status(node_truck *&, node_truck *&);

		bool find_readytruck(node_truck *); // find by recursion
		void displayList(node_truck*);
		void remove_node( node_truck *&);
        void insertTruckNode(node_truck *& aNode);
		node_truck *rear;
		
};
//---------- GARBAGE CAN MANAGEMENT -------------//
// Some functions I call from a library instead of implementing them in vector.
// the job of this class manages the can menu.
class Can_Management:public Garbage_Can{
	public:
		Can_Management();
		~Can_Management();
		void insertcans();
		void display();
		void remove_all();
		void asking();

		void findcan_byid(Truck_List &); // find can by id. if it's full, communicate with truck to pick up
	//	void find_can_by_status();
		void change_status_type();
		
	protected:
		bool findcan(int id, int &); // find a can matching by ID
		vector<Garbage_Can> listcan;
		void display(int number); // display cans by recursion

};

#endif