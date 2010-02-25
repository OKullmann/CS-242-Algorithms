# Oliver Kullmann, 22.2.2010 (Swansea)

SHELL = /bin/bash
.SUFFIXES :

.PHONY : all cleanall

CXX = g++

Standard_options := -ansi -pedantic
Warning_options := -Wall
Optimisation_options := -O3 -DNDEBUG -ffast-math

base_dir = ../..

include_option = -I$(base_dir)

###

programs = LinkedLists ConnectedComponents ConnectedComponentsE

all : $(programs)

cleanall :
	rm $(programs)

# ########################

LinkedLists : % : %.cpp LinkedLists.hpp Framework.hpp
	$(CXX) -o $@ $(Standard_options) $(Warning_options) $(Optimisation_options) $(include_option) $(CPPFLAGS) $(CXXFLAGS) $<

ConnectedComponents ConnectedComponentsE : % : %.cpp LinkedLists.hpp RootedTrees.hpp RandomGraphs.hpp ConnectedComponents.hpp ../../Utilities/Timing.hpp
	$(CXX) -o $@ $(Standard_options) $(Warning_options) $(Optimisation_options) $(include_option) $(CPPFLAGS) $(CXXFLAGS) $<

