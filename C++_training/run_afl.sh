#!/bin/bash

# AFL_PATH="~/Downloads/AFL-master/afl-fuzz"

# $AFL_PATH

# note: must put options BEFORE path to program to fuzz

# if not root user, AFL will not run withou this command
export AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1
export AFL_SKIP_CPUFREQ=1

~/Downloads/AFL-master/afl-fuzz -n -i /users/6/a1645126/C_test/C++_training/fuzz_stringlib_reversestring -o /users/6/a1645126/C_test/C++_training/fuzz_stringlib_reversestring_out /users/6/a1645126/C_test/C++_training/fuzz_stringlib