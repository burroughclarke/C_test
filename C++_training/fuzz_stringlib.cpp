
#include <iostream> // need for 'std::string'
#include "lib_string.h"

int main() {

	std::string original_string;
	std::cin >> original_string;

	std::string reversed_string = burrough::reverse_string(original_string);
	std::string splitted_string = burrough::split_string_first_occurance(original_string, original_string); 
	std::string rsplit_string    = burrough::split_string_last_occurance(original_string, original_string); 

	std::cout << "original_string:" << original_string << "\n";
	std::cout << "reversed_string:" << reversed_string << "\n";
 
	return 0;
} 