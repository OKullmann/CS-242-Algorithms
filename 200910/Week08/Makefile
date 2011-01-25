# Oliver Kullmann, 16.3.2010 (Swansea)

SHELL = /bin/bash
.SUFFIXES :

.PHONY : all cleanall

CXX = g++

Standard_options := -ansi -pedantic
Warning_options := -Wall
Optimisation_options := -O3 -DNDEBUG

base_dir = ../..

include_option = -I$(base_dir)

###

programs = ChangeMaking

all : $(programs)

cleanall :
	-rm $(programs)

# ########################

ChangeMaking : % : %.cpp ChangeMaking.hpp
	$(CXX) -o $@ $(Standard_options) $(Warning_options) $(Optimisation_options) $(include_option) $(CPPFLAGS) $(CXXFLAGS) $<

