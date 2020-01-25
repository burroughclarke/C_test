
#include <iostream>
#include <stack>
#include "lib_string.h"
using namespace std;

// seems you need 'namespace' in both .h and .cpp files ...
namespace burrough {

	string split_string_first_occurance(string s, string delimiter) {
		int delimiter_pos = s.find(delimiter);
		return s.substr(0, delimiter_pos);
	}

	string split_string_last_occurance(string s, string delimiter) {
		int delimiter_pos = s.rfind(delimiter);
		return s.substr(delimiter_pos + delimiter.length(), s.length() - 1);
	}

	string reverse_string(string s) { 
		// 1. read characters one by one ONTO the stack
		stack<char> mystack;
		while (s.length() > 0) {
			char c = s.front();
			s.erase(0, 1);
			cout << "pushing [" << c << "] onto stack\n";
			mystack.push(c);
		}

		string reversed_string;

		while (mystack.size() > 0) {
			reversed_string += mystack.top();
			mystack.pop();
		}

		return reversed_string;
	}

	// creates a one-dimensional array to emulate a two-dimensional array
	// returns a pointer to the one-dimensional array
	int* create2DArray(int rows, int columns) {
		int array_length = rows * columns;
		int* dynamic_array = new int[array_length];

		for (int i = 0; i < array_length; i++) {
			dynamic_array[i] = 0;
		}
		
		return dynamic_array;
	}

	void print2DArray(int *arr, int rows, int columns) {
		// cout << "arr[0]:" << arr[0] << "\n";
		// cout << "arr[1]:" << arr[1] << "\n";

		for (int i = 0; i < rows * columns; i++) {
			// cout << "arr[" << i << "]: " << arr[i] << "\n";
		}
		
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				int item_number = ((i) * columns) + j;
				// cout << "printing item [" << item_number << "]\n";
				cout << arr[item_number] << " ";
			}
			cout << "\n";
		}
	}
 
	void set2D(int *arr, int rows, int columns, int desired_row, int desired_column, int val) {
		int item_number = ((desired_row - 1) * columns) + (desired_column - 1);
		arr[item_number]  = val;
	}

	int get2D(int* arr, int rows, int columns, int desired_row, int desired_column) {
		int item_number = ((desired_row - 1) * columns) + (desired_column - 1);
		return arr[item_number];
	}

}
