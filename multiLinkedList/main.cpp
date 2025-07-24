#include "multiLinkedList.h"
using namespace std;

int main() {
	char ch = 'a';
	multiLinkedList list1;

	cout << "--------Welcome-------" << endl << endl;

	cout << "Enter 'i' to insert student informations" << endl << "Enter 's' to delete any student's information"
		<< endl << "Enter 'c' or 'd' to print all student's informations as sorted (CGPA/id)" << endl
		<< "Enter 'e' to Exit" << endl;
	cin >> ch;
	cout << endl << endl;

	while (ch != 'e') {
		
		if (ch == 'i') {
			cout << "Enter -1 to exit" << endl;
			int ID;
			float CGPA;
			
			while (1) {
				cout << "id: ";
				cin >> ID;
				cout << endl;
				if (ID == -1)
					break;
				cout << "CGPA: ";
				cin >> CGPA;
				cout << endl << endl;
				list1.insert(ID, CGPA);
			}

		}

		else if (ch == 's') {
			int del;
			cout << "Enter the student's id who you want to delete" << endl << "id : ";
			cin >> del;
			list1.deleteItem(del);
		}

		else if (ch == 'c' || ch == 'd') {
			list1.print(ch);
			cout << endl << endl;
		}
		cout << "Enter 'i' to insert student informations" << endl << "Enter 's' to delete any student's information"
			<< endl << "Enter 'c' or 'd' to print all student's informations as sorted (CGPA/id)" << endl
			<< "Enter 'e' to Exit" << endl;
		cin >> ch;
		cout << endl << endl;
	}

	cout << "------Good Bye !------" << endl << endl;






	return 0;
}