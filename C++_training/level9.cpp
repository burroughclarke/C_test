
// Github steps (repository from scratch)
// 1. [git clone] to copy a remote directory (e.g. from Github to local machine)
// 2. 

#include <iostream>
#include <cstring> //strlen
#include <string>
#include <cmath>
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

int main() {
	
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



	char * normal = "normal string";
	char * odd = "oddnumber"; // length=9


	char* result1 = reverse_cstring(normal);
	char* result2 = reverse_cstring(odd);

	std::cout << "result1:" << result1 << std::endl;
	std::cout << "result2:" << result2 << std::endl;


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