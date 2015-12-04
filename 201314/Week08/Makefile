# Oliver Kullmann, 16.2.2010 (Swansea)

SHELL = /bin/bash
.SUFFIXES :

.PHONY : all cleanall

CXX = g++

Standard_options := -std=c++11 -pedantic
Warning_options := -Wall
Optimisation_options := -O3 -DNDEBUG

base_dir = ../..

include_option = -I$(base_dir)

###

programs = BinaryTrees_Output BinaryTrees_Search BinaryTrees_Statistics

all : $(programs)

cleanall :
	rm $(programs)

# ########################

$(programs) : % : %.cpp BinaryTrees.hpp
	$(CXX) -o $@ $(Standard_options) $(Warning_options) $(Optimisation_options) $(include_option) $(CPPFLAGS) $(CXXFLAGS) $<
