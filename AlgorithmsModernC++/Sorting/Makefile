.PHONY : cleanall all test measure

CXX := g++
warning_options := -Wall -Wno-parentheses
standard_options := --std=c++11
optimisation_options := -Ofast -DNDEBUG

add_opt_options := -fstrict-aliasing -funroll-loops -fstrict-overflow -fwhole-program
# -fwhole-program has very patchy effects (some situations get faster, some slower), but seems to help with the fastest algorithms.
# Other options to try are
# -funsafe-loop-optimizations -freschedule-modulo-scheduled-loops -fpeel-loops -funswitch-loops

debug_options := -g

all : Testing Testing_debug Measuring

Testing: Insertion.hpp Small.hpp Selection.hpp Testing.cpp
	$(CXX) -o Testing $(standard_options) $(warning_options) $(optimisation_options) $(CPPFLAGS) $(CXXFLAGS) Testing.cpp

Testing_debug : Insertion.hpp Small.hpp Selection.hpp Testing.cpp
	$(CXX) -o Testing_debug $(standard_options) $(warning_options) $(debug_options) $(CPPFLAGS) $(CXXFLAGS) Testing.cpp

Measuring : Insertion.hpp Small.hpp Selection.hpp Generators.hpp Measuring.cpp
	$(CXX) -o Measuring $(standard_options) $(warning_options) $(optimisation_options) $(add_opt_options) $(CPPFLAGS) $(CXXFLAGS) Measuring.cpp

test : Testing Testing_debug
	./Testing_debug; echo -e "$$? \n"
	valgrind ./Testing; echo -e "$$? \n"

measure : Measuring
	./Measuring


cleanall:
	- rm Testing Testing_debug Measuring

