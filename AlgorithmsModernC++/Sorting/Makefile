.PHONY : cleanall all test measure

CXX := g++
warning_options := -Wall
standard_options := --std=c++11
optimisation_options := -Ofast -DNDEBUG
add_opt_options := -funroll-loops
debug_options := -g

all : Testing Testing_debug Measuring

Testing: InsertionSort.hpp Testing.cpp
	$(CXX) -o Testing $(standard_options) $(warning_options) $(optimisation_options) $(CPPFLAGS) $(CXXFLAGS) Testing.cpp

Testing_debug : InsertionSort.hpp Testing.cpp
	$(CXX) -o Testing_debug $(standard_options) $(warning_options) $(debug_options) $(CPPFLAGS) $(CXXFLAGS) Testing.cpp

Measuring : InsertionSort.hpp Measuring.cpp
	$(CXX) -o Measuring $(standard_options) $(warning_options) $(optimisation_options) $(add_opt_options) $(CPPFLAGS) $(CXXFLAGS) Measuring.cpp

test : Testing Testing_debug
	./Testing_debug; echo -e "$$? \n"
	valgrind ./Testing; echo -e "$$? \n"

measure : Measuring
	./Measuring


cleanall:
	- rm Testing Testing_debug Measuring

