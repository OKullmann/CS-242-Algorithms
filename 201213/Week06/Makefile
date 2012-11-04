# Oliver Kullmann, 4.11.2012 (Swansea)

SHELL = /bin/bash
.SUFFIXES :

.PHONY : all cleanall

CXX = g++
JAVAC = gcj


Standard_options := -std=c++11 -pedantic
Warning_options := -Wall -Wno-main
Optimisation_options := -O3 -DNDEBUG


###

programs = Stack Stack2

all : $(programs)

cleanall :
	-rm $(programs)

# ########################

Stack : Stack.java
	$(JAVAC) -o $@ $(JFLAGS) --main="$@" $<

Stack2 : Stack2.cpp Stack.hpp
	$(CXX) -o $@ $(Standard_options) $(Warning_options) $(include_option) $(CPPFLAGS) $(CXXFLAGS) $<
