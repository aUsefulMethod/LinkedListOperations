#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

//class ArrayClass {
//
//private:
//
//	int size;
//	int* array = new int[size];
//
//public:
//
//	ArrayClass(int userSize) {
//
//		this->size = userSize;
//
//	}
//
//	~ArrayClass() {
//
//		cout << "Destructor called.\n";
//
//	}
//
//	int getSize() {
//
//		return this->size;
//
//	}
//
//};

struct node {

	char data[10];
	node* next;

};

node* head = NULL;


void insertAtStart() {

	node* temp = new node;

	if (temp == NULL)
	{

		cout << "\nOverflow; out of space within allotted memory.\n";
		return;

	}

	cout << "Enter a name to be inserted: ";
	cin >> temp->data;
	temp->next = NULL;

	if (head == NULL)
	{

		head = temp;

	}
	else {

		// we effectively "push" our items into the list,
		// so the first item entered, appears at the end of the list
		// works similarly to a stack with our insert/display methods
		temp->next = head;
		head = temp;

	}

}

void alphabeticalInsert() {

	node* newNode = new node;

	char nodeName[10];
	cout << "Enter the name you wish to insert into the node: ";
	cin >> nodeName;

	// we need two nodes that we can manipulate 
	// so that we can place newNode within,
	// after we find correct spot within list (given alphabetical organization)
	node* previous = NULL;
	node* curr = head;

	if (newNode != NULL)
	{

		// shoving user entry into data member of node 
		strcpy_s(newNode->data, nodeName);



		while (curr != NULL && strcmp(nodeName, curr->data) > 0)
		{

			previous = curr;

			curr = curr->next;

		}

		// signifies list is empty, so we insert at head (start of list)
		if (previous == NULL)
		{

			newNode->next = curr;

			head = newNode;

		// otherwise
		}else {

			// we place newNode between previous and curr
			previous->next = newNode;
			newNode->next = curr;

		}

	}

}

void COUNT() {

	int count = 0;
	node* ptr;
	ptr = head;
	while (ptr != NULL)
	{

		ptr = ptr->next;
		count++;

	}

	cout << "There are " << count << " nodes in your list.\n";

}

void DISPLAY() {

	struct node* ptr;

	if (head == NULL)
	{

		cout << "\nThere are no nodes to print.\n";
		return;

	}
	else {

		ptr = head;
		cout << "\nList of Values:\n";
		while (ptr != NULL)
		{

			cout << ptr->data << "\n";
			ptr = ptr->next;

		}

	}

}

void DELETE() {

	char nodeName[10];

	cout << "Enter a name to delete from the list: ";
	cin >> nodeName;

	node* temp = NULL;
	node* previous = NULL;
	node* curr = head;

	if (NULL == curr)
	{

		cout << "Your list is empty!" << endl;

	}

	if (0 == strcmp(nodeName, curr->data))
	{

		temp = curr;
		head = curr->next;
		cout << temp->data << " has successfully been deleted.\n";
		delete(temp);

	}
	else {

		while (curr != NULL && strcmp(nodeName, curr->data) != 0)
		{

			previous = curr;
			curr = curr->next;

		}

		if (curr != NULL)
		{

			temp = curr;
			previous->next = curr->next;
			cout << temp->data << " has been deleted from the list.\n";
			delete(temp);

		}

	}

}

void CLEAR() {

	head = NULL;

}

int main() {

	/*int userSizeEntry;
	cout << "Please enter the size of your array: ";
	cin >> userSizeEntry;

	ArrayClass myArray(userSizeEntry);

	cout << myArray.getSize() << endl;*/

	/*node* n;
	node* t;
	node* h;

	n = new node;
	n->data = 25;
	t = n;
	h = n;

	n = new node;
	n->data = 10;
	t->next = n;
	t = t->next;

	n = new node;
	n->data = 90;
	t->next = n;
	n = new node;
	t = t->next;
	n->data = 40;
	t->next = n;
	n->next = NULL;*/

	int userChoice;
	while (1)
	{

		cout << "Choose an operation to perform on your linked List:\n";
		cout << "1. Insert a node at the beginning of the list:\n";
		cout << "2. Display your Linked List.\n";
		cout << "3. Insert an item alphabetically:\n";
		cout << "4. Delete an item from the list.\n";
		cout << "5. Display the total number of nodes in your list.\n";
		cout << "6. Clear (delete) all nodes in your list.\n";
		cout << "7. To Exit Application.\n";
		cout << "Enter your choice: ";
		cin >> userChoice;

		switch (userChoice)
		{

		case 1:

			insertAtStart();
			break;

		case 2:

			DISPLAY();
			break;

		case 3:

			alphabeticalInsert();
			break;

		case 4:

			DELETE();
			break;

		case 5:

			COUNT();
			break;

		case 6:

			CLEAR();
			break;

		case 7:

			exit(0);

		default:

			break;

		}

	}

}