
// My name: Anh Ho
// Class: CS202
// Project: Programming Assignment 1
// File name: truckandcan.cpps
// this cpp will implement all function from truck list for CLL 
// here will be also implementing for data structure for garbage can
#include "header.h"
#include "nodecar.h"
#include "nodetruckcan.h"

void Truck_List::insertTruck(){
    cout << "\nBefore starting a good trip, we need to collect some infomation for a car!\n";
	
	int choice ;
	do {
		Garbage_Truck * temptruck = new Garbage_Truck();
		temptruck->input_truck();
		
		// trying to create a new node containing garbage truck data.
		node_truck * newnode = new node_truck;
		newnode->get_data() = temptruck;
		newnode->go_next() = nullptr;

		insertTruckNode(newnode);
		// Car_List is a list of all the node cars
		cout << "\nTo stop adding trucks for checking!\nPress '0' to stop or Any number to continue adding a truck: ";
		cin >> choice;
		cin.ignore();

	} while (choice != 0);

}

//Function to insert truck node by recursion
void Truck_List::insertTruckNode(node_truck *& aNode){
    if (!rear){
        rear = aNode; 
        aNode->go_next() = rear; 
    } else {
        aNode->go_next() = rear->go_next();
        rear->go_next() = aNode;
    }
} 

// Helper function to display garbage truck by recursion
void Truck_List::display(){ 
    if (!rear) {
        cout << "\nThe CLL for the truck is empty! \n";
        return;
    }
    displayList(rear->go_next());
}
// Function to display garbage truck by recursion
void Truck_List::displayList(node_truck * check) {
    if (check == rear){
        check->get_data()->display_truck();
        return;
    }

    check->get_data()->display_truck();
    displayList(check->go_next());       
}

// Menu for Garbage Truck
void Truck_List::asking(){
	cout << "**********************▲○■*********************\n";
	cout << "\tWelcome to Garbage Truck systerm!\n"; 
	cout << "\n\t[1] Add garbage truck into the system";
	cout << "\n\t[2] Search garbage can by ID";
	cout << "\n\t[3] Display all the garbage can";
	cout << "\n\t[4] Remove all the truck has a full capacity of trash cans by the status";
	cout << "\n\t[5] remove all the can in the garbage can system";
	cout << "\n\t***[0] Quit the car system!";

	cout << "\n\t► Please enter a number: ";
	return;
}

// Helper function to remove node by recursion
void Truck_List::remove_node(){
    if (!rear) {
        cout << "\nThe CLL for the truck is empty! \n";
        return;
    }    
    remove_node(rear->go_next());
}
// Function to remove all node in the truck list by recursion
void Truck_List::remove_node(node_truck *& head) {
    if (!head)
        return;
    if (head == rear){
        rear->delete_data();
        delete rear;
        head = nullptr;
        rear = nullptr;
        return;
    } else {
        node_truck * temp = head; 
        head = head->go_next(); // allocate head again before removing
        temp->delete_data();
        delete temp;
        temp = nullptr;      
        rear->go_next() = head; // got seg fault because of missing to re-allocate for the next rear
        remove_node(head);
    }
}

//remove truck by status!

// Helper Function to find a "ready" truck to pick up trash
bool Truck_List::find_readytruck(){
    if (!rear){
        cout << "\nUnfortunately, we do not have any truck available now!";
        return false;
    }
    if (find_readytruck(rear->go_next()))
    {
        cout << "\nWe found a first truck is ready in the list";
        return true;
    }
    return false;
}
// Main Function to find a "Ready" truck to pick up trash by recursion. 
bool Truck_List::find_readytruck(node_truck * cur) {
    if (cur == this->rear){
        if (cur->get_data()->getStatus() == "ready" && cur->get_data()->getNumOfCans() < MAXCANS) {
            cout << "\nthe truck is ready - " << cur->get_data()->getID();
            cur->get_data()->increase_cans(); // truck will inscrease 1 can in their storage after picking up 
            if (cur->get_data()->getNumOfCans() == MAXCANS)
            {
                cout << "\nThe garbage truck reached out to the maxcans! \n";
                cur->get_data()->change_status("unready");
            }      
            return true;
        } else 
            return false;
    }

    if (cur->get_data()->getStatus() == "ready" && cur->get_data()->getNumOfCans() < MAXCANS) {
            cout << "\nthe truck is ready - " << cur->get_data()->getID();
            cur->get_data()->increase_cans();
            if (cur->get_data()->getNumOfCans() == MAXCANS)
            {
                cout << "\nThe garbage truck reached out to the maxcans! \n";
                cur->get_data()->change_status("unready");
            }
            return true;
    }
    return find_readytruck(cur->go_next());
    
}
// Helper function to remove by status 
void Truck_List::remove_by_status(){
    if (!rear){
        cout << "\nThe list is empty!~ \n";
        return;
    }
    remove_by_status(rear);
}

void Truck_List::remove_by_status(node_truck *& head)
{

    if (!head)
        return;

    if (head->go_next() == head){
        if (head->go_next()->get_data()->getStatus() == "unready") {
            head->delete_data();
            delete head;
            rear = NULL;
            head = NULL;
            return;
        }
    }

    if (head->go_next() == rear){
        if (head->go_next()->get_data()->getStatus() == "unready") {
            node_truck * temp = head->go_next();
            node_truck * hold = temp->go_next();
            rear->go_next() = head;
            delete temp;
            rear = head;
        }
        return;
    } 
    
    if (head->go_next()->get_data()->getStatus() == "unready") {
            node_truck * temp = head->go_next();
            node_truck * hold = temp->go_next();
            head->go_next() = hold;
            delete temp;
            
            remove_by_status(head->go_next());
        }
    else   remove_by_status(head->go_next());
}


/////////////////////////////////////////////////////////////////////////////
//------------------------ Garbage Can Class -------------------------------//
bool Garbage_Can::change_status(string input){
    if (input == "")
        return false;
    full_status = input;
    return true;
}


// ------------------------------CAN MANAGEMENT ---------------------//

void Can_Management::insertcans() {
    int choice ;
	do {
		Garbage_Can can;
		can.input_can(); // getting data for a can
		listcan.push_back(can);
		cout << "\nTo stop adding cans for checking!\nPress '0' to stop or Any number to continue adding a trash can: ";
		cin >> choice;
		cin.ignore();

	} while (choice != 0);
}

void Can_Management::display(){
    int number = 0;
   // cout << "List Can store: " << listcan.size() << " Objects " << endl;  
	if (listcan.size() != 0)
    {
        cout << "\nDislay the vector list! \n";
        display(number);   // recursively display all the garbage can
    } else  cout << "\n*** Garbage can is empty! *** \n";	
}

void Can_Management::display(int number){
    if (number == listcan.size())
        return;
    listcan.at(number).display_can();
    number++;
    display(number);
} 

void Can_Management::remove_all(){
    listcan.clear();
}

void Can_Management::asking(){ // menu for users - smart cars
	int number = 0;
	cout << "**********************▲○■*********************\n";
	cout << "\tWelcome to Garbage Can systerm!\n"; 
	cout << "\n\t[1] Add garbage can into the system";
	cout << "\n\t[2] Search garbage can by ID and call garbage truck to pick up if needed";
	cout << "\n\t[3] Display all the garbage can";
	cout << "\n\t[4] Update the status of trash can and trash type by ID ";
	cout << "\n\t[5] remove all the can in the garbage can system";
	cout << "\n\t***[0] Quit the car system!";

	cout << "\n\t► Please enter a number: ";
	return;
}
// find can and commnucaite with truck to pick up
void Can_Management::findcan_byid(Truck_List & truck){
    int id = 0;
    int number = 0;
    int choice = 0;
    bool check_status = false;
    bool check_id = false;
    cout << "\n\tWhat's ID can? \n\t ID: ";
    cin >> id;
    cin.ignore();
    check_id = findcan(id, number);
    if (check_id == true){
        listcan.at(number).display_can();
        if (listcan.at(number).getstatus() == "full")
        {
            cout << "\n\tYour trash can is full. You need to empty it! \n";
            cout << "\n\tWould you like to call a truck to pick up your trash? [1] Yes - [0] No ";
            do {
                 cout << "\n\tPlease enter your choice: ";
                cin >> choice;
                cin.ignore();
            } while (choice != 0 && choice != 1);
           
            if (choice == 1) {
                // call function from truck to ask any ready truck to pick up trash
                // if successful, changed the status of the can;
                if (truck.find_readytruck() == true)
                { // testing
                    check_status = listcan.at(number).change_status("empty");
                    if (check_status == true)
                        cout << "\nYour trash can has been picked up by a truck - it's empty now!\n";
                    else cout << "\nUnable to update a new status!\n";
                } else cout << "\n**Unfortunately, there are no ready trucks to pick up your trash at this time!\n";
            }

        }    
    } else cout << "\n\tWe couldn't find any can mathching the ID! \n";
}

bool Can_Management::findcan(int id, int & number){ // recursively find a can matching given ID in vector list.
    if (number == listcan.size())
        return false;
    if (listcan.at(number).getID() == id) {
        return true;
    }
    number++;
    return findcan(id, number);
}

void Can_Management::change_status_type(){
    int id = 0;
    int number = 0;
   
    bool check_id = false;
    cout << "\n\tWhat's ID can? \n\t ID: ";
    cin >> id;
    cin.ignore();
    check_id = findcan(id, number);
    if (check_id == true){
        listcan.at(number).update_status_type();
        cout << "\n\tWe have updated the status of your garbage trash and type of your trash!";
    } else cout << "\n\tWe couldn't find any can mathching the ID! \n";

}