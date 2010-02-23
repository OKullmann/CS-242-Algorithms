# Oliver Kullmann, 22.2.2010 (Swansea)

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

programs = LinkedLists

all : $(programs)

cleanall :
	rm $(programs)

# ########################

$(programs) : % : %.cpp LinkedLists.hpp Framework.hpp
	$(CXX) -o $@ $(Standard_options) $(Warning_options) $(Optimisation_options) $(include_option) $(CPPFLAGS) $(CXXFLAGS) $<
