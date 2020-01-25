
COMPILER = g++
BOOST_PATH = ~/Downloads/boost_1_72_0/ 
IMPLEMENTATION_FILES = level9.cpp pair.cpp shape.cpp circle.cpp square.cpp
LIB_PATHS = -L. 
LIB_INCLUDES = -l_string
CPLUS_STANDARD = -std=c++11

stringlib: lib_string.cpp
	$(COMPILER) -c lib_string.cpp -o lib_string.o  $(CPLUS_STANDARD)
	ar rcs lib_string.a lib_string.o 

stringlibdynamic: lib_string.cpp
	$(COMPILER) -shared -fPIC -o lib_string.so lib_string.cpp

level9: level9.cpp
	@echo "note: if lib_string has been modified, compile that first"
	$(COMPILER) $(LIB_PATHS) -I $(BOOST_PATH) $(LIBS) -o task9 $(CPLUS_STANDARD) $(IMPLEMENTATION_FILES) $(LIB_INCLUDES)

fuzz_stringlib: fuzz_stringlib.cpp
	$(COMPILER) $(LIB_PATHS) fuzz_stringlib.cpp $(LIBS) -o fuzz_stringlib $(CPLUS_STANDARD) $(LIB_INCLUDES)

clean:
	rm *.o *.so

# '@'  :'don't echo this command'
# 'ar' : a utility to write multiple object files into a single static library file
# '-I' : a search path for header files
# '-c' : make an object file, not an executable. Object files don't need 'main()', executables DO

# files on the 'title' line are prerequisites. They must exist before the script is run.

# variables in makefiles: https://stackoverflow.com/questions/448910/what-is-the-difference-between-the-gnu-makefile-variable-assignments-a?rq=1
# g++ compiler flags: https://caiorss.github.io/C-Cpp-Notes/compiler-flags-options.html



##### Dynamic library:  (.so 'shared object' is the linux term)

# to create:
# PIC: position independent code

# to execute:
# $ ./main ./libsample.so

# to debug 'library not found': (this will show all the paths it tries)
# WARNING: if using the '-l' flag, you MUST start the library name with 'lib'
# WARNING: put '-L.' before '-l' or get 'undefined reference' bugs; https://stackoverflow.com/questions/5870026/howto-add-a-static-library-a-into-a-c-program
# ld -L. -llib_string --verbose

