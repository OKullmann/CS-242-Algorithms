# Oliver Kullmann, 1.3.2010 (Swansea)

SHELL = /bin/bash
.SUFFIXES :

.PHONY : all cleanall

CXX = g++

Standard_options := -ansi -pedantic
Warning_options := -Wall
Optimisation_options := -O3 -DNDEBUG

base_dir = ../..

###

programs = BreadthFirstSearch BreadthFirstSearch_forest DepthFirstSearch_forest

all : $(programs)

cleanall :
	-rm $(programs)

# ########################

BreadthFirstSearch BreadthFirstSearch_forest : % : %.cpp AdjacencyList.hpp BreadthFirstSearch.hpp
	$(CXX) -o $@ $(Standard_options) $(Warning_options) $(Optimisation_options) $(CPPFLAGS) $(CXXFLAGS) $<

DepthFirstSearch_forest : % : %.cpp AdjacencyList.hpp DepthFirstSearch.hpp
	$(CXX) -o $@ $(Standard_options) $(Warning_options) $(Optimisation_options) $(CPPFLAGS) $(CXXFLAGS) $<
