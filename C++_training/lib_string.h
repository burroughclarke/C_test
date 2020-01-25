
namespace burrough {
	// bad practice to create a derived class from std::string or any standard class [link: https://stackoverflow.com/questions/6006860/why-should-one-not-derive-from-c-std-string-class]
	// returns the FIRST instance of a string split by a delimiter
	std::string split_string_first_occurance(std::string s, std::string delimiter);

	// 'lsat occurance' e.g. if an array of substrings was returned, this would be the last item in the array
	std::string split_string_last_occurance(std::string s, std::string delimiter);

	// reverses the string
	std::string reverse_string(std::string s);

	// creates a one-dimensional array to emulate a two-dimensional array
	// returns a pointer to the one-dimensional array
	int* create2DArray(int rows, int columns);

	// prints 2d representation of '1-d emulation of 2-d array' to console
	void print2DArray(int *arr, int rows, int columns);

	void set2D(int *arr, int rows, int columns, int desired_row, int desired_column, int val);

	int get2D(int* arr, int rows, int columns, int desired_row, int desired_column);
}
