
// 'include' "is like copy and pasting"
#include <iostream>
#include <cstring> //strlen
#include <string>
#include <cmath>
#include <list>
#include <vector>
#include <fstream>
#include <map>

//"abc" vs <abc>: quotes mean it searches the current directory for the file (as well as the system's 'include' directories)
#include "pair.h"
#include "shape.h"
#include "square.h"
#include "circle.h"

#include <boost/lambda/lambda.hpp>

#include "lib_string.h"

using namespace boost::lambda;
using namespace std;

// namespace burrough {}
// using namespace burrough;

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

				// UNFINISHED
void reverseNodes(Node* head) {
	// iterate through the list, taking the last node each time
	// add the last node to the end of a new linked list
	// repeat until the original linked list is empty
	// do not create or destroy any nodes
	// NodePtr tmp = head;
	// // while (getLinkedListLength(head) > 0) {

	// // }

	// // step 1: connect last node to first node (make the list 'circular')
	// // step 2: change the second-to-last node to point to NULL
	// // step 3: assign the last node as the 'head' node

	// NodePtr prev = head;
	// NodePtr next = head;

	// while (tmp != NULL) {
	// 	// cout << "name (forwards):" << tmp->name << "\n";
		
	// 	next = tmp->link;

	// 	NodePtr tmpCopy = tmp;

	// 	if (prev != NULL && tmp != NULL && next != NULL) {
	// 		cout << "prev: " << prev->name << " tmp:" << tmp->name << " next:" << next->name << "\n";
	// 	}
	// 	if (prev != NULL && tmp != NULL && next == NULL) {
	// 		cout << "prev: " << prev->name << " tmp:" << tmp->name << " next:NULL" << "\n";
	// 		head = tmp;
	// 	}

	// 	if (tmp->link != NULL) {

	// 	}

	// 	if (tmp->link == NULL) {

	// 	}


	// 	// tmpCopy->link = prev;

	// 	prev = tmp;

}

struct TimeFormatException : public std::exception
{
	const char * what () const throw ()
    {
    	cout << "Error: Time Format Exception\n";
    	return "Time Format Exception";
    }
};

struct InvalidLineException : public std::exception
{	
	const char * description = "Invalid Line Exception";
	const char * what () const throw ()
    {
    	cout << description << "\n";
    	return description;
    }
};

// exceptions required:
// minutes must be '00' to '60'

string twentyfour_to_twelve_time(string twentyfour_time) {
	// split the string by ':'
	string delimiter = ":";
	int delimiter_pos = twentyfour_time.find(delimiter);
	
	try {
		if (delimiter_pos == std::string::npos) {
			throw TimeFormatException();
		}
	}
	catch (TimeFormatException e) {
		e.what();
		return "";
	}

	string hours = twentyfour_time.substr(0, delimiter_pos);
	string minutes = twentyfour_time.substr(delimiter_pos + delimiter.length(), twentyfour_time.length() - 1);

	if (std::stoi(hours) > 12) {
		hours = std::to_string(std::stoi(hours) - 12);
	}

	return hours + ":" + minutes + " PM";
}

// vector<string> vector_string;
map<int, vector<std::string> > map_id_to_classes;
void input_student_data() {
	ifstream myfile ("data_students.txt");
	string line;
 
	// 'copy constructor' : 
	// don't do this unless you are using pointers
	// map_id_to_classes = new std::map<int, vector<string> >;

	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			cout << "file line:[" << line << "]\n";
			
			int id = 0;
			try {
				id = stoi(burrough::split_string_first_occurance(line, " "));
			} 
			// 'invalid_argument' is thrown by stoi if it tries to process something that is not an integer
			catch (std::invalid_argument&) {
				// if line is invalid, skip it
				continue;
			}
			string course = burrough::split_string_last_occurance(line, " ");
			
			cout << "course:[" << course << "]\n";
			cout << "id:[" << id << "]\n";

			//vector_string.push_back(line);

			// if ID number does not exist, insert ID value with new vector (with one element)
			if (map_id_to_classes.count(id) == 0) {
				vector<std::string> tmp_vector = {course};
				
				pair<int,vector<string> > mypair = make_pair(id, tmp_vector);
				map_id_to_classes.insert(mypair);
			}
			// If ID number already exists, find that ID value and add a new element to vector
			else {
				cout << "id already exists:" << map_id_to_classes.at(id).at(0) << "\n";
				map_id_to_classes.at(id).push_back(course);
			}
		}
	}
	else {
		cout << "ERROR: cannot open file\n";
	}

	myfile.close();
}

// reads an input file line-by-line into a 'set'. 
// As it is a set, duplicates will be removed
set<std::string> read_lines_into_set(string file_path) {
	ifstream myfile (file_path);
	string line = "";

	set<std::string> set_of_strings;
 
	if (myfile.is_open()) {
		while (getline(myfile, line, '\n')) {
			cout << "file line:[" << line << "]\n";
			set_of_strings.insert(line);
		}
	}

	myfile.close();

	return set_of_strings;
}

// back inserter: https://stackoverflow.com/questions/5034211/c-copy-set-to-vector
// "std::back_inserter creates an output iterator that calls push_back on a container for each element, 
// ...so each element is inserted into the container. "
vector<string> set_string_to_vector_string(set<string> set_string) {
	vector<string> output;
	std::copy(set_string.begin(), set_string.end(), std::back_inserter(output));
	return output;
}


// fast searching algo
// precondition: 
// low end: always set to 0
// high end: alwayse set to (array.kength - 1)
template<class T>
void binary_search(const T a[], int low_end, int high_end, int key, bool& found, int& location) {
	
	int first = low_end;
	int last = high_end;
	int mid;
	
	found = false; //so far
	
	while ( (first <= last) && !(found) ) {
		mid = (first + last) / 2;
		if (key == a[mid]) {
			found = true;
			location = mid;
		}
		else if (key < a[mid]) {
			last = mid -1;
		}
		else if (key > a[mid]) {
			first = mid + 1;
		}
	}
}

int strip_whitespace_from_file(string in_file_name, string out_file_name) {
	ifstream myfile (in_file_name);
	ofstream outfile(out_file_name);
	char c;

	// read by character not by line

	if (myfile.is_open()) {
		bool non_whitespace_found = false;
		while ( myfile.good()  ) {
			cout << "char:[" << c << "]\n";
			// if (non_whitespace_found == false) {
				myfile >> c;
				outfile << c;
			// }
		}
	}

	myfile.close();
	outfile.close();
}

class Doctor {
public:
	string speciality;
	Doctor(string mSpeciality, int m_visit_fee);
	int visit_fee;

	// 'accessor' functions


	// 'mutator' functions


protected:
private:
};


int main() {

	int rows = 3;
	int columns = 5;

	cout << "creating dynamic array...\n";
	int* dynamic_array = burrough::create2DArray(rows, columns); 

	cout << "setting dynamic array...\n";
	// warning: columns are being counted here from '1', not '0'
	int desired_row = 2;
	int desired_col = 3;
	burrough::set2D(dynamic_array, rows, columns, desired_row, desired_col, 3);
	burrough::set2D(dynamic_array, rows, columns, 1, 1, 5);
	burrough::set2D(dynamic_array, rows, columns, 3, 5, 9);

	cout << "printing dynamic array...\n";
	burrough::print2DArray(dynamic_array, rows, columns);

	
	int val = burrough::get2D(dynamic_array, rows, columns, desired_row, desired_col);
	cout << "val:" << val << "\n";



	return 0;





















	strip_whitespace_from_file("messy_file.txt", "clean_file.txt");
	return 0;


	string forward_string = "burrough";
	string backwards_string = burrough::reverse_string(forward_string);

	cout << "burrough reversed: " << backwards_string << "\n";

	return 0;






	int intarray[] = {1, 2, 3, 7, 9, 100, 999};
	int low_end = 0;
	int high_end = 6;  
	int key = 7;
	bool found = false; 
	int location = -1;

	binary_search(intarray, low_end, high_end, key, found, location);

	cout << "found:" << found << "\n";
	cout << "location:" << location << "\n";

	return 0;










	set<string> myset = read_lines_into_set("names_list.txt");
	
	std::set<string>::iterator it;
	for (it = myset.begin(); it != myset.end(); ++it) {
    	cout << "set iterator:" << *it << "\n";
	}

	vector<string> vector_string = set_string_to_vector_string(myset);

	for (int i = 0; i < vector_string.size(); i++) {
		cout << "vector[" << i << "]:" << vector_string.at(i) << "\n";
	}

	// not required! outputting the set is already sorted when it gets outputted
	vector<string> messy_vector = {"miow", "cats", "fish", "dog"};
	std::sort(messy_vector.begin(), messy_vector.end());
	for (int i = 0; i < messy_vector.size(); i++) {
		cout << "(sorted) messy vector[" << i << "]:" << messy_vector.at(i) << "\n";
	}





	return 0;


















	input_student_data();

	// test loop
	for (int i = 0; i < map_id_to_classes[2].size(); i++) {
		cout << "id 2 has class: " << map_id_to_classes[2].at(i) << "\n";
	}

	return 0;


	string twentyfour_time;
	
	cout << "Enter 24-hour time:";
	cin >> twentyfour_time;
	
	string twelve_hour_time = twentyfour_to_twelve_time(twentyfour_time);

	cout << "Converted to 12-hour time:" << twelve_hour_time << "\n";

	return 0;









    typedef std::istream_iterator<int> in;
    // for_each
    std::for_each( in(std::cin), in(), std::cout << (_1 * 3) << " " );
	return 0;


	MyPair pairOne(5, 6);
	MyPair pairTwo(7, 8);

	int pairTotal = pairOne + pairTwo;

	cout << "should be 5+6+7+8:" << pairTotal << "\n";

	// Shape* myShape = new Shape;   // Shape is an abstract class, cannot be allocated
	Circle* myCircle = new Circle;
	Square* mySquare = new Square;

	try {
		int sides_of_circle = myCircle->getNumberOfSides();
		int sides_of_square = mySquare->getNumberOfSides();

		cout << "sides to a circle: " << sides_of_circle << "\n";
		cout << "sides to a square: " << sides_of_square << "\n";

		if (sides_of_circle != 1) {
			throw sides_of_circle;
		}
		
	}
	catch (int e) {
		cout << e << " is the wrong number of sides to a circle\n";
	}

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