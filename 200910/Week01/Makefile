# Oliver Kullmann, 22.12.2009 (Swansea)

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

programs = Experiment_up Experiment_down Experiment_rand Test

all : $(programs)

cleanall :
	rm $(programs)

#########################

Experiment_down : Experiment_down.cpp Sorting.hpp Generators.hpp
	$(CXX) -o $@ $(Standard_options) $(Warning_options) $(Optimisation_options) $(include_option) $(CPPFLAGS) $(CXXFLAGS) $<

Experiment_up : Experiment_up.cpp Sorting.hpp Generators.hpp
	$(CXX) -o $@ $(Standard_options) $(Warning_options) $(Optimisation_options) $(include_option) $(CPPFLAGS) $(CXXFLAGS) $<

Experiment_rand : Experiment_rand.cpp Sorting.hpp Generators.hpp
	$(CXX) -o $@ $(Standard_options) $(Warning_options) $(Optimisation_options) $(include_option) $(CPPFLAGS) $(CXXFLAGS) $<

Test : Test.cpp Sorting.hpp Generators.hpp
	$(CXX) -o $@ $(Standard_options) $(Warning_options) $(Optimisation_options) $(include_option) $(CPPFLAGS) $(CXXFLAGS) $<

gen : solutions/Sorting_1.hpp
	solutions/gensolution Sorting

