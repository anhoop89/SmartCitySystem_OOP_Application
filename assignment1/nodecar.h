// My name: Anh Ho
// Class: CS202
// Project: Programming Assignment 1
// File name: Node.h
// it has 3 classes including node car, car list, car management
// It helps to store data from smart car into a node car and built array of LLL based on location that I build and will ask 
// 1. Node class to support the linear linked list 
// 2. Car List will store smart devices in arr of linked list
 
#ifndef NODECAR_H
#define NODECAR_H
#include "header.h"

// trying to design the smart car working first and then move on to the next devices.
class node_car // LLL for the car
{
	public:
		// Default Constructor
		node_car();
		// Constructor with parameters
		node_car(Smart_Car *& data);
		// Copy Constructor
		node_car(const node_car& to_copy);
		// Destructor
		~node_car();
		// Function to go next node
		node_car*& go_next();
		// Function to get the data of node
		Smart_Car*& get_data();
		// Function to connect next node
		void connect_next(node_car*& connections);
		
		void display_node_car();
		// Function to destroy node
		void destroy();
       
	protected:
		Smart_Car * data_car; // has a
		node_car* next;
		
	
};
//build an array of LLL for smart car's location 
// each location will be an element of the array.
// The car may come from different locations, but they can go to the destinations I already built.


class Car_List{ // Arr of Linked Linked List 
	public:
		Car_List();
		~Car_List();
		node_car * getHead();
	   
	   
	    void insertCarNode(node_car *& aNode); // insert a node car by recursion
		bool findcar_byid(node_car * head, int id);
		bool findcar_remove(int id);
		void display();
		void  remove_node();
		
	protected:
		void  displayList(node_car*);
		void remove_node( node_car *&);
		bool recur_find_remove(node_car *&, int);
		node_car *listHead;
		node_car *listTail;
};

// Build a menu to interact with users. 
class Car_Management{ // this class builds dynamic arr of link
	public:
		Car_Management();
		~Car_Management();
		void destroy(int num_area);
		void searchcar_byid();
		void removecar_byid();
		void display_all(); // display all the car based on the location
		void add_car();
		void remove_all_cars();
		void asking();  // menu to add, remove, display data
	protected:
		Car_List ** area;  // create  arr of linear linked list
		int num_area = 3;

};











#endif