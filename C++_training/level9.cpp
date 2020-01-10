
// 'include' "is like copy and pasting"
#include <iostream>
#include <cstring> //strlen
#include <string>
#include <cmath>
#include <list>
#include <vector>
//"abc" vs <abc>: quotes mean it searches the current directory for the file (as well as the system's 'include' directories)
#include "pair.h"

using namespace std;

class CounterType {

public:
	CounterType() {
		counter = 0;
	}

	CounterType(int setCounter) {
		counter = abs(setCounter);
	}

	void incrementCounter() {
		counter++;
	}

	int getCounter() {
		return counter;
	}
	
	void counterStream(ostream& output_stream) {
		output_stream << "counter:" << counter << "\n";
	}

protected:

private:
	int counter;
};

struct Node {
	Node* link;
	string name;
};
typedef Node* NodePtr;

// watch out for '[]' vs '*' !!
// there IS a (small) different: https://stackoverflow.com/questions/11555997/c-c-int-vs-int-pointers-vs-array-notation-what-is-the-difference

string* addEntry(string *dynamicArray, int &size, string newEntry) {

	// create new dynamic array
	string* newDynamic = new string();

	for (int i = 0; i < size; i++) {
		cout << "appending: " << dynamicArray[0][i] << "\n";
	}

	// segfault
	// can't do: 'newDynamic[0] = new string("fish")'
	newDynamic = new string("fish");
	// newDynamic->append(dynamicArray[0][0]);

	return newDynamic;
}

string* deleteEntry(string *dynamicArray, int &size, string entryToDelete) {
	return dynamicArray;
}

 char* reverse_cstring(char * cstr) {
	char * result_str;
	result_str = new char[strlen(cstr)];
	char * front = cstr;
  	char * back = cstr + strlen(cstr)-1;
  	int i = 0;
  	while (i < strlen(cstr))
  	{
  		std::cout << "front0:[" << front[0] << "] back0: [" << back[0] << "]\n";
     	result_str[i] = back[0];
     	front++;
  		back--;
  		i++;
 	 }
 	 return result_str;
}

bool isPalindrome(char* cstr)
{
  char* front = cstr;
  char* back = cstr + strlen(cstr)-1;
  while (front < back)
  {
  	std::cout << "front0:[" << front[0] << "] back0: [" << back[0] << "]\n";
   if (front[0] != back[0]) {
   		return false;
   }
  	front++;
  	back--;
  }
  return true;
}

int getLinkedListLength(Node* head) {
	
	NodePtr tmp = head;
	int i = 0;
	while (tmp != NULL) {
		i++;
		tmp = tmp->link;
	}

	int length = i;
	cout << "number of nodes: " << length << "\n";
	return length;
}

// very rarely should you use raw pointers, use STL
// vector and list can do almost the same thing, just different complexity costs
void listTemplate() {
	int myints[] = {16,2,77,29};
  	std::list<int> myList (myints, myints + sizeof(myints) / sizeof(int));

  	list<int> myListTwo;
  	myListTwo.push_back(4);
}

void reverseNodes(Node* head) {
	// iterate through the list, taking the last node each time
	// add the last node to the end of a new linked list
	// repeat until the original linked list is empty
	// do not create or destroy any nodes
	NodePtr tmp = head;
	// while (getLinkedListLength(head) > 0) {

	// }

	// step 1: connect last node to first node (make the list 'circular')
	// step 2: change the second-to-last node to point to NULL
	// step 3: assign the last node as the 'head' node

	NodePtr prev = head;
	NodePtr next = head;

	while (tmp != NULL) {
		// cout << "name (forwards):" << tmp->name << "\n";
		
		next = tmp->link;

		NodePtr tmpCopy = tmp;

		if (prev != NULL && tmp != NULL && next != NULL) {
			cout << "prev: " << prev->name << " tmp:" << tmp->name << " next:" << next->name << "\n";
		}
		if (prev != NULL && tmp != NULL && next == NULL) {
			cout << "prev: " << prev->name << " tmp:" << tmp->name << " next:NULL" << "\n";
			head = tmp;
		}

		if (tmp->link != NULL) {

		}

		if (tmp->link == NULL) {

		}


		// tmpCopy->link = prev;

		prev = tmp;
		tmp = tmp->link;

	}
}


int main() {

	MyPair pairOne(5, 6);
	MyPair pairTwo(7, 8);

	int pairTotal = pairOne + pairTwo;

	cout << "should be 5+6+7+8:" << pairTotal << "\n";

	return 0;



	NodePtr listPtr, tempPtr;
	
	listPtr = new Node;
	listPtr->name = "Emily";
	
	tempPtr = new Node;
	tempPtr->name = "James";
	
	listPtr->link = tempPtr;
	
	tempPtr->link = new Node;
	tempPtr = tempPtr->link;
	tempPtr->name = "Joules";
	tempPtr->link = NULL;

	NodePtr head = listPtr;
	NodePtr tmp = head;

	tmp = head;
	while (tmp != NULL) {
		cout << "name (forwards):" << tmp->name << "\n";
		tmp = tmp->link;
	}

	reverseNodes(head);

	tmp = head;
	while (tmp != NULL) {
		cout << "name (reversed):" << tmp->name << "\n";
		tmp = tmp->link;
	}










	return 0;
	
	CounterType counterTypeOne; // CAN'T do 'counterTypeOne()'
	CounterType counterTypeTwo(2);

	// std::ostream my_ostream;
	counterTypeOne.counterStream(cout);


	cout << "counterOne:" << counterTypeOne.getCounter() << "\n";
	cout << "counterTwo:" << counterTypeTwo.getCounter() << "\n";





	return 0;


















	string add = "fish";
	string* myString = new string("miow");
	int five = 5;

	addEntry(myString, five, add);

	std::cout << "mystring:" << *myString << "\n";

	return 0;




	// char * normal = "normal string";      // depreciated, use 'const char* ...' to silence warning
	// char * odd = "oddnumber"; // length=9 // depreciated, use 'const char* ...' to silence warning


	// char* result1 = reverse_cstring(normal);
	// char* result2 = reverse_cstring(odd);

	// std::cout << "result1:" << result1 << std::endl;
	// std::cout << "result2:" << result2 << std::endl;


	return 0;

	// set booleans to output as 'alpha' (not '0' or '1')
    std::cout << std::boolalpha;  

	char s1[50] = "neveroddoreven";
	char s2[50] = "not a palindrome";
	std::cout << "should be true:" << isPalindrome(s1) << std::endl; // true
	std::cout << "should be false:" << isPalindrome(s2) << std::endl; // false
	return 0;

	std::cout << "Enter number of doubles:";

	int numDoubles;

	std::cin >> numDoubles;

	std::cout << "numDoubles:" << numDoubles << "\n";
	
	// create dynamic array storing 'numDoubles' doubles
	double* doubleArr;

	doubleArr = new double[numDoubles];

	for (int i = 0; i < numDoubles; i++) {
		std::cin >> doubleArr[i];
	}

	double total = 0;
	double avg = 0;
	for (int i = 0; i < numDoubles; i++) {
		total += doubleArr[i];
	}

	avg = total / numDoubles;

	std::cout << "average: " << avg << "\n";

	// delete the memory allocated
	delete [] doubleArr;








}