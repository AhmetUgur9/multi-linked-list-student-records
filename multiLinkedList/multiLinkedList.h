#include "LinkedList.h"
using namespace std;

struct Node {
	int id;
	float cgpa;
	Node* linkId;
	Node* linkCgpa;
};

class multiLinkedList:public linkedList{
public:
	void insert(int, float);
	void deleteItem(int);
	void print(char);
	multiLinkedList();
	~multiLinkedList();
private:
	Node* firstId;
	Node* lastId;
	Node* firstCgpa;
	Node* lastCgpa;
};


void multiLinkedList::insert(int id_, float cgpa_) {
	Node* currentId;
	Node* trailCurrentId = NULL;
	Node* currentCgpa;
	Node* trailCurrentCgpa = NULL;
	Node* newNode;
	bool found;


	newNode = new Node;
	newNode->id = id_;
	newNode->cgpa = cgpa_;
	newNode->linkId = NULL;
	newNode->linkCgpa = NULL;


	if (firstId == NULL) {//Empty case(id)
		firstId = newNode;
		lastId = newNode;
	}
	else {//Not empty case(id)
		currentId = firstId;
		found = false;

		while (currentId != NULL && !found) {
			if (currentId->id >= id_)
				found = true;
			else {
				trailCurrentId = currentId;
				currentId = currentId->linkId;
			}
		}
			

		if (currentId == firstId) {
			newNode->linkId = firstId;
			firstId = newNode;
		}
		else {
			trailCurrentId->linkId = newNode;
			newNode->linkId = currentId;

			if (currentId == NULL)
				lastId = newNode;
			
		}

	}//End of not empty case(id)


	if (firstCgpa == NULL) {//Empty case(cgpa)
		firstCgpa = newNode;
		lastCgpa = newNode;
	}
	else {//Not empty case(cgpa)
		currentCgpa = firstCgpa;
		found = false;

		while (currentCgpa != NULL && !found)
			if (currentCgpa->cgpa >= cgpa_)
				found = true;
			else {
				trailCurrentCgpa = currentCgpa;
				currentCgpa = currentCgpa->linkCgpa;
			}

		if (currentCgpa == firstCgpa) {
			newNode->linkCgpa = firstCgpa;
			firstCgpa = newNode;
		}
		else {
			trailCurrentCgpa->linkCgpa = newNode;
			newNode->linkCgpa = currentCgpa;

			if (currentCgpa == NULL)
				lastCgpa = newNode;

		}


	}//End of not empty case(cgpa)

}//End of insert function


void multiLinkedList::deleteItem(int id__) {
	Node* currentId;
	Node* trailCurrentId = NULL;
	Node* currentCgpa;
	Node* trailCurrentCgpa = NULL;
	bool found;

	if(firstId == NULL)//case1: The list is empty.
		cout << "Cannot delete from an empty list." << endl;
	else {
		currentId = firstId;
		found = false;

		while (currentId != NULL && !found)
			if (currentId->id >= id__)
				found = true;
			else
			{
				trailCurrentId = currentId;
				currentId = currentId->linkId;
			}

		if (currentId == NULL)   //case4: Item is not in the list.
			cout << "The item to be deleted is not in the list." << endl;
		else {
			if (currentId->id == id__) {//The item in the list.

				if (firstId == currentId) {//case2: The item is in the first node.
					firstId = firstId->linkId;

					if (firstId == NULL) {//This means there is just one node and we are deleting it.
						lastId = NULL;
						firstCgpa = NULL;
						lastCgpa = NULL;
					}
					else {
						currentCgpa = firstCgpa;
						while (currentCgpa != currentId) {
							trailCurrentCgpa = currentCgpa;
							currentCgpa = currentCgpa->linkCgpa;
						}
						if (firstCgpa == currentCgpa)
							firstCgpa = firstCgpa->linkCgpa;
						else {
							trailCurrentCgpa->linkCgpa = currentCgpa->linkCgpa;
							if (currentCgpa == lastCgpa)
								lastCgpa = trailCurrentCgpa;
						}

					}

					delete currentId;

				}
				else {//case3: The item is somewhere in the list.
					trailCurrentId->linkId = currentId->linkId;

					if (currentId == lastId)
						lastId = trailCurrentId;

					currentCgpa = firstCgpa;
					while (currentCgpa != currentId) {
						trailCurrentCgpa = currentCgpa;
						currentCgpa = currentCgpa->linkCgpa;
					}
					if (firstCgpa == currentCgpa)
						firstCgpa = firstCgpa->linkCgpa;
					else {
						trailCurrentCgpa->linkCgpa = currentCgpa->linkCgpa;
						if (currentCgpa == lastCgpa)
							lastCgpa = trailCurrentCgpa;
					}
					delete currentId;
				}

			}
			else//Again case4
				cout << "The item to be deleted is not in the list." << endl;
		}
			
			
	}

}//End of deleteItem function.


void multiLinkedList::print(char mode) {
	if (mode == 'c') {
		Node* currentCgpa = firstCgpa;

		if (currentCgpa == NULL)
			cout << endl << "The list is empty." << endl;
		else {
			while (currentCgpa != NULL) {
				cout << endl << "id : " << currentCgpa->id << "   CGPA : " << currentCgpa->cgpa << endl;
				currentCgpa = currentCgpa->linkCgpa;
			}
		}
		
	}

	else if (mode == 'd') {
		Node* currentId = firstId;

		if (currentId == NULL)
			cout << endl << "The list is empty." << endl;
		else {
			while (currentId != NULL) {
				cout << endl << "id : " << currentId->id << "   CGPA : " << currentId->cgpa << endl;
				currentId = currentId->linkId;
			}
		}
	}

}//End of print function

multiLinkedList::multiLinkedList() {
	firstId = NULL;
	lastId = NULL;
	firstCgpa = NULL;
	lastCgpa = NULL;
}

multiLinkedList::~multiLinkedList() {
	delete firstId;
	delete lastId;
	cout << "The list has been removed!";
}
