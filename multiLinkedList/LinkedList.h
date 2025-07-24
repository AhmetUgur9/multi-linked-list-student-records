#include <iostream>
using namespace std;

class linkedList {
public:
	virtual void insert(int, float) = 0;
	virtual void deleteItem(int) = 0;
	virtual void print(char) = 0;
};

