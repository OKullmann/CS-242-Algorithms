# Oliver Kullmann, 10.11.2011 (Swansea)

SHELL = /bin/bash
.SUFFIXES :

.PHONY : all cleanall

CXX = g++

Standard_options := -std=c++0x -pedantic
Warning_options := -Wall
Optimisation_options := -O3 -DNDEBUG

###

programs = Inversions

all : $(programs)

cleanall :
	-rm $(programs)

# ########################

$(programs) : % : %.cpp
	$(CXX) -o $@ $(Standard_options) $(Warning_options) $(Optimisation_options) $(include_option) $(CPPFLAGS) $(CXXFLAGS) $<
